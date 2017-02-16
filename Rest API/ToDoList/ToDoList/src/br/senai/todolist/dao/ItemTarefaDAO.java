package br.senai.todolist.dao;

import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;

import org.springframework.stereotype.Repository;
import org.springframework.transaction.annotation.Transactional;

import br.senai.todolist.modelo.ItemTarefa;
import br.senai.todolist.modelo.Tarefa;

@Repository
public class ItemTarefaDAO {
	@PersistenceContext
	private EntityManager manager;

	//inserindo itens
	@Transactional
	public void inserirItem(Long idTarefa, ItemTarefa item){
		item.setTarefa(manager.find(Tarefa.class,idTarefa));
		manager.persist(item);
	}
	
	
	//marcar como feito
	@Transactional
	public void marcarFeito(Long idItemTarefa, boolean valor){
		ItemTarefa item = manager.find(ItemTarefa.class,idItemTarefa); //buscando item
		item.setFeito(valor);
		manager.merge(item);
	}
	
	@Transactional
	public void excluir(Long idItemTarefa){
		//precisa tirar item da tarefa antes de remover
		ItemTarefa item = manager.find(ItemTarefa.class,idItemTarefa);
		Tarefa tarefa = item.getTarefa();
		tarefa.getItens().remove(item);
		//atualizando tarefa
		manager.merge(tarefa);
	}
	
}
