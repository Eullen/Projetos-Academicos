package br.senai.todolist.controller;

import java.net.URI;
import java.util.HashMap;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.servlet.mvc.method.annotation.ResponseEntityExceptionHandler;

import com.auth0.jwt.JWTSigner;
import com.auth0.jwt.internal.org.apache.commons.lang3.ObjectUtils.Null;
import com.sun.xml.internal.ws.server.sei.EndpointArgumentsBuilder.Body;

import antlr.Token;
import br.senai.todolist.dao.UsuarioDAO;
import br.senai.todolist.modelo.TokenJwt;
import br.senai.todolist.modelo.Usuario;

//anotação
@RestController
public class UsuarioRestController {
	
	//atributos 
	public static final String SECRET ="todolistsenai"; //normalmente recebe valor em hexadecimal
	public static final String ISSUER="SENAI"; //emissor
		
	@Autowired
	private UsuarioDAO dao;
	
	//salvando usuario
	@RequestMapping(value="/usuario",method =RequestMethod.POST,consumes=MediaType.APPLICATION_JSON_UTF8_VALUE)
	public ResponseEntity<Object> inserirUsuario(@RequestBody Usuario usuario){
		try{
			dao.inserirUsuario(usuario);
			return ResponseEntity.created(URI.create("/usuario/"+usuario.getId())).body(usuario);
		}catch(Exception e){
			return ResponseEntity.status(HttpStatus.INTERNAL_SERVER_ERROR).body(e.getMessage());
		}
	}
	
	//recuperando dados de usuario
	@RequestMapping(value="/usuario/{idUser}",method=RequestMethod.GET,consumes=MediaType.APPLICATION_JSON_UTF8_VALUE)
	public Usuario recuperarUsuario(@PathVariable Long idUser ){
		return dao.buscarUsuario(idUser);
		
	}

	//deletando usuario
	@RequestMapping(value="/usuario/{idUser}",method=RequestMethod.DELETE)
	public ResponseEntity<Void> deletarUsuario(@PathVariable Long idUser){
		dao.deletarUsuario(idUser);
		return ResponseEntity.noContent().build();
	}
	
	//logar
	@RequestMapping(value="/login",method=RequestMethod.POST, consumes=MediaType.APPLICATION_JSON_UTF8_VALUE)
	public ResponseEntity<TokenJwt> logar(@RequestBody Usuario usuario){
		try{
			Usuario user = dao.logar(usuario);
			if(user!=null){
				long iat = System.currentTimeMillis() / 100;  //data emissão token em SEGUNDOS
				long exp = iat + 3600; //data expiração do token
				JWTSigner signer = new JWTSigner(SECRET);//obj que gera token (precisa de SECRET para cript e descript
				//obrigatorio
				HashMap<String, Object> claims = new HashMap<>();
				claims.put("iss", ISSUER);
				claims.put("iat", iat);
				claims.put("exp", exp);
				//opcionais aqui
				claims.put("id_usuario",user.getId());
				//enviando claims pro signer gerar token
				String jwt = signer.sign(claims);
				//criando objeto token para evitar criar JSON na mão
				TokenJwt tokenJwt = new TokenJwt();
				tokenJwt.setToken(jwt);
				return ResponseEntity.ok(tokenJwt);
			}else{
				return new ResponseEntity<>(HttpStatus.UNAUTHORIZED);
			}
		}catch (Exception e) {
			e.printStackTrace();
			return new ResponseEntity<>(HttpStatus.INTERNAL_SERVER_ERROR);
		}

		
	}
	
	
	
}
