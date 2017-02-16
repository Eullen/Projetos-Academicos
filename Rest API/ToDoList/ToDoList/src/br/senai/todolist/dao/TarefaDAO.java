package br.senai.todolist.dao;

import java.util.List;

import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;
import javax.persistence.TypedQuery;

import org.springframework.stereotype.Repository;
import org.springframework.transaction.annotation.Transactional;

import br.senai.todolist.modelo.Tarefa;

@Repository //Anotação para classes que se comunicam com BD
public class TarefaDAO {
	
	@PersistenceContext //traz Entitymanager de outro local, no caso o Spring
	private EntityManager manager; //objeto responsavel por persistir obj no banco
	
	@Transactional //operação precisa de transação
	public void inserir(Tarefa tarefa){
		//insere tarefa e itens da tarefa e recupera id
		manager.persist(tarefa);
	}
	
	//listagem de tarefas
	
	public List<Tarefa> listar(){
		//mais segura pois recebe apenas obj dos tipos declarados
		TypedQuery<Tarefa> query = manager.createQuery("select t from Tarefa t",Tarefa.class); //select , Tipo do obj
		return query.getResultList();
		
	}

	//removendo tarefa e itens por consequência
	@Transactional //operação precisa de transação
	public void excluir(Long idTarefa){
		Tarefa t = manager.find(Tarefa.class, idTarefa); //(Tipo de objeto,object)
		manager.remove(t);
	}
	
	public Tarefa localizar (Long idTarefa){
		return manager.find(Tarefa.class, idTarefa); //retorna único objeto
	}
	
	
}
