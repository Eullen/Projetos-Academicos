package br.senai.todolist.modelo;

import java.util.List;

import javax.persistence.CascadeType;
import javax.persistence.Entity;
import javax.persistence.FetchType;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.OneToMany;

import com.fasterxml.jackson.annotation.JsonIgnoreProperties;

//mapeamento
@Entity
public class Tarefa {
	@Id //mapeia campo em PK
	@GeneratedValue(strategy=GenerationType.IDENTITY) //gerar ID com autoincremento no BD
	private Long id;
	private String titulo;
	
	//criar relacionamento 1:N 
	@OneToMany (mappedBy="tarefa",fetch=FetchType.EAGER,cascade = CascadeType.ALL,orphanRemoval=true) 
								//mappedBy impede criação automática de tabela intermediária
								//fetch = definir de que forma buscar entidades do relacionamento - EAGER busca de primeira 
								//criação de FK na tabela ItemTarefa
								//cascadeType.ALL - inserte itens da tarefa na respectiva tabela automaticamente
								//orphanRemoval - remove itens quando tarefa for excluida - Limpar Banco
	
	private List<ItemTarefa> itens; //List eh interface - Posso instancialo com qualquer classe que implemente List
	
	public Long getId() {
		return id;
	}
	public void setId(Long id) {
		this.id = id;
	}
	public String getTitulo() {
		return titulo;
	}
	public void setTitulo(String titulo) {
		this.titulo = titulo;
	}
	public List<ItemTarefa> getItens() {
		return itens;
	}
	public void setItens(List<ItemTarefa> itens) {
		this.itens = itens;
	}

	//verifcar se tarefa foi concluida - todos os itens feitos
	@JsonIgnoreProperties("feito")
	public boolean isConcluida(){
		//percorrer itens da tarefa
		for(ItemTarefa item: itens){
			//foreach
			if(!item.isFeito()){
				return false;
			}
		}
		return  true;
	}
	
}
