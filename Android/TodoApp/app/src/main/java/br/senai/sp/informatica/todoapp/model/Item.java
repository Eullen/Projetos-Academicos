package br.senai.sp.informatica.todoapp.model;


public class Item {
    private Long id;
    private String descricao;
    private boolean feito;

    public Item() {
    }

    public Item(Long id) {
        this.id = id;
    }

    public Item(String descricao) {
        this.descricao = descricao;
    }

    public Item(String descricao, boolean feito) {
        this.descricao = descricao;
        this.feito = feito;
    }

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

    @Override
    protected Object clone() throws CloneNotSupportedException { // <<=== TODO: avisar
        Item novo = new Item();
        novo.id = (long)id;
        novo.feito = feito;
        novo.descricao = new String(descricao.toCharArray());

        return novo;
    }

}
