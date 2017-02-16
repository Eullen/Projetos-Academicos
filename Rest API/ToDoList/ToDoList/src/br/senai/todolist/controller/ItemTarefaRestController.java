package br.senai.todolist.controller;

import java.net.URI;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.security.access.prepost.PostAuthorize;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

import br.senai.todolist.dao.ItemTarefaDAO;
import br.senai.todolist.modelo.ItemTarefa;
import br.senai.todolist.modelo.Tarefa;

@RestController
public class ItemTarefaRestController {
	@Autowired
	private ItemTarefaDAO dao;
	
	@RequestMapping(value="/lista/{idTarefa}/item",method = RequestMethod.POST,consumes=MediaType.APPLICATION_JSON_UTF8_VALUE)
	public ResponseEntity<ItemTarefa> addItem(@PathVariable Long idTarefa, @RequestBody ItemTarefa item){ //AddItem vem na requisição, Item vem no corpo da requisição
		try{
			dao.inserirItem(idTarefa, item);
			return ResponseEntity.created(URI.create("/item/"+item.getId())).body(item);
		}catch (Exception e) {
			e.printStackTrace();
			return new ResponseEntity<>(HttpStatus.INTERNAL_SERVER_ERROR);
		}
	}
	
	@RequestMapping(value="/item/{idItemTarefa}",method = RequestMethod.PUT,consumes=MediaType.APPLICATION_JSON_UTF8_VALUE)
	public ResponseEntity<Void> marcarFeito(@PathVariable Long idItemTarefa ,@RequestBody ItemTarefa item){
		try{
			dao.marcarFeito(idItemTarefa, item.isFeito());
			//criando header para devolver codigo 200 de OK
			HttpHeaders responseHeaders = new HttpHeaders();
			URI location =URI.create("/item/"+idItemTarefa);
			responseHeaders.setLocation(location);
			return new ResponseEntity<Void>(responseHeaders,HttpStatus.OK);
		}catch (Exception e) {
			e.printStackTrace();
			return new ResponseEntity<>(HttpStatus.INTERNAL_SERVER_ERROR);
		}
	}
	@RequestMapping(value="/item/{idItemTarefa}",method=RequestMethod.DELETE)
	public ResponseEntity<Void> excluir(@PathVariable Long idItemTarefa){
		dao.excluir(idItemTarefa);
		return ResponseEntity.noContent().build();
	}
}
