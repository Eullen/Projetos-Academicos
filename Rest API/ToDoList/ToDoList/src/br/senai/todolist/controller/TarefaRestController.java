package br.senai.todolist.controller;

import java.net.URI;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

import com.auth0.jwt.internal.org.bouncycastle.asn1.ocsp.Request;
import com.sun.media.jfxmedia.Media;

import br.senai.todolist.dao.TarefaDAO;
import br.senai.todolist.modelo.ItemTarefa;
import br.senai.todolist.modelo.Tarefa;

@RestController //anotacao que indica que classe usará biblioteca Jackson, etc...
public class TarefaRestController {
	
	@Autowired //Injeta dao "pronta"
	private TarefaDAO dao;
	
		
	@RequestMapping(value="/lista",method = RequestMethod.POST,consumes=MediaType.APPLICATION_JSON_UTF8_VALUE ) 
					//De onde vem a request, metodo , consome ou produz alguma coisa  
	public ResponseEntity<Object> salvar(@RequestBody Tarefa tarefa){ //obj tarefa vem no corpo da request
		try{
			//setar tarefa nos seus itens
			for(ItemTarefa item : tarefa.getItens()){
				item.setTarefa(tarefa);
			}
			dao.inserir(tarefa);
			 //return codigo de respoata + location com endereço/id da tarefa gerada + body com tarefa criada
			return ResponseEntity.created(URI.create("/lista/"+tarefa.getId())).body(tarefa);
			
		}catch(Exception e){
			return ResponseEntity.status(HttpStatus.INTERNAL_SERVER_ERROR).body(e.getMessage());
		}
	}
	
	
	//anotacoes
	@RequestMapping(value="/lista",method=RequestMethod.GET,produces=MediaType.APPLICATION_JSON_UTF8_VALUE)
	public List<Tarefa> listar(){
		return dao.listar();
	}
	
	
	//mapeamento
	//{caminho variável}
	@RequestMapping(value="/lista/{idTarefa}",method = RequestMethod.DELETE)
	public ResponseEntity<Void> excluir(@PathVariable Long idTarefa){
		dao.excluir(idTarefa);
		return ResponseEntity.noContent().build();
	}
	
	//localizar
	@RequestMapping(value="/lista/{idTarefa}",method = RequestMethod.GET,produces=MediaType.APPLICATION_JSON_UTF8_VALUE)
	public Tarefa localizar(@PathVariable Long idTarefa){
		return dao.localizar(idTarefa);	
	}
	
	
}
