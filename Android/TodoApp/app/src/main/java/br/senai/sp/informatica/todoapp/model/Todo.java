package br.senai.sp.informatica.todoapp.model;


import java.util.ArrayList;
import java.util.List;

public class Todo {
    private Long id;
    private String titulo;
    private List<Item> itens = new ArrayList<>(); // <<=== TODO: avisar

    public Todo() {
    }

    public Todo(String titulo) {
        this.titulo = titulo;
    }

    public String getTitulo() {
        return titulo;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public boolean isFeito() {
        boolean feito = true;

        for(Item item : itens) {
            if(!item.isFeito()) {
                feito = false;
                break;
            }
        }

        return feito && itens.size() > 0;
    }

    public List<Item> getItens() { // <<=== TODO: avisar
        List<Item> lista = null;
        try {
            lista = new ArrayList<>();
            for (Item item : itens)
                lista.add((Item)item.clone());
        } catch (CloneNotSupportedException ex) {
            lista = itens;
        }
        return lista;
    }

    public void setItens(List<Item> itens) { // <<=== TODO: avisar
        this.itens = itens;
    }

    //imp necessária para implementação do Object mAp´per da bilbioteca Jackson 2
    public void setFeito(boolean feito){

    }

}
