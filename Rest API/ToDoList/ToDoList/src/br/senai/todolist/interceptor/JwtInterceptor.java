package br.senai.todolist.interceptor;

import java.util.Map;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.springframework.http.HttpStatus;
import org.springframework.web.method.HandlerMethod;
import org.springframework.web.servlet.handler.HandlerInterceptorAdapter;

import com.auth0.jwt.JWTVerifier;
import com.sun.org.apache.xml.internal.security.utils.HelperNodeList;

import br.senai.todolist.controller.UsuarioRestController;

public class JwtInterceptor extends HandlerInterceptorAdapter {
	//ações antes de passar no controller
	@Override
	public boolean preHandle(HttpServletRequest request, HttpServletResponse response, Object handler)
			throws Exception { //handler obj contém informações do destino
		HandlerMethod method = (HandlerMethod) handler;
		System.out.println("Controller chamado:"+method.getBean().getClass().getSimpleName());
		System.out.println("Método chamado: "+method.getMethod().getName());
		
		//retorna boolean - TRUE para permitir acesso e FALSE para rejeitar
		if(request.getRequestURI().contains("login")){ //liberando acesso ao login
			return true;
		}//qualquer outra return false
		//recebendo token
		String token = request.getHeader("Authorization");
		try{
			//descript token, verificar informações e libera acesso ao recurso
			JWTVerifier verifier = new JWTVerifier(UsuarioRestController.SECRET);
			Map<String, Object> claims = verifier.verify(token);
			System.out.println(claims);
			return true;
		}catch (Exception e) {
			e.printStackTrace();
			if(token == null){
				response.sendError(HttpStatus.UNAUTHORIZED.value());//não autorizado
			}else{
				response.sendError(HttpStatus.FORBIDDEN.value()); //acesso negado
			}
			return false;
		}
	}
}
