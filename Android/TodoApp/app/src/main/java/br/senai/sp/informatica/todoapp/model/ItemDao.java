package br.senai.sp.informatica.todoapp.model;

import java.util.List;

public class ItemDao implements Dao {
    private static ItemDao instancia;
    private List<Item> lista;
    private static long id = 0;

    private ItemDao(List<Item> lista) {
        this.lista = lista;
    }

    public static ItemDao getInstance(List<Item> lista) {
        ItemDao dao = new ItemDao(lista);
        ItemDao.instancia = dao;
        return dao;
    }

    public static ItemDao getInstance() {
        return instancia;
    }

    public void salvar(Item item) {
       if(item.getId() == null) {
           // Incluir
           item.setId(id++);
           lista.add(item);
       } else {
           // Atualizar
           Item obj = localizar(item.getId());
           obj.setDescricao(item.getDescricao());
           obj.setFeito(item.isFeito());
       }
    }

    public List<Item> listar() {
        return lista;
    }

    public Item localizar(long id) {
        Item item = null;

        for(Item obj : lista) {
            if(obj.getId() == id) {
                item = obj;
                break;
            }
        }

        return item;
    }

    public void remover (long id) {
        Item item = localizar(id);

        if(item != null)
            lista.remove(item);
    }
}
