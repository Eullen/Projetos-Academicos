package br.senai.todolist.modelo;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.ManyToOne;

import com.fasterxml.jackson.annotation.JsonIgnoreProperties;

//mapeamento
@Entity
//anotacao para evitar loop do jackson
@JsonIgnoreProperties("tarefa")
public class ItemTarefa {
	@Id //mapeia campo em PK
	@GeneratedValue(strategy=GenerationType.IDENTITY) //gerar ID com autoincremento no BD
	private Long id; //Usar classe pelo menos no identificador para compará-lo com NULL
	
	private String descricao;
	private boolean feito;
	
	@ManyToOne(optional=false) //optional = true - impl. relaciona ManyToZero
	private Tarefa tarefa;
	
	
	public Tarefa getTarefa() {
		return tarefa;
	}
	public void setTarefa(Tarefa tarefa) {
		this.tarefa = tarefa;
	}
	//Getters and Setters
	public Long getId() {
		return id;
	}
	public void setId(Long id) {
		this.id = id;
	}
	public String getDescricao() {
		return descricao;
	}
	public void setDescricao(String descricao) {
		this.descricao = descricao;
	}
	public boolean isFeito() {
		return feito;
	}
	public void setFeito(boolean feito) {
		this.feito = feito;
	}
	
}
