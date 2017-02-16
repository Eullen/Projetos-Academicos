package br.senai.sp.informatica.todoapp.model;


import java.util.ArrayList;
import java.util.List;

public class TodoDaoOLD implements Dao {
    public static TodoDaoOLD instancia = new TodoDaoOLD();

    private List<Todo> lista;
    private long id = 0;

    private TodoDaoOLD() {
        lista = new ArrayList<>();

        Todo todo = new Todo("Migrar o servidor Corp526");
        ItemDao dao = ItemDao.getInstance(todo.getItens());
        dao.salvar(new Item("Item 1º", true));
        dao.salvar(new Item("Item 2º", true));
        todo.setItens(dao.listar());
        salvar(todo);

        todo = new Todo("Escrever o capítulo de RMI");
        dao = ItemDao.getInstance(todo.getItens());
        dao.salvar(new Item("Primeiro Item"));
        dao.salvar(new Item("Segundo Item", true));
        dao.salvar(new Item("Terceiro Item"));
        dao.salvar(new Item("Quarto Item", true));
        todo.setItens(dao.listar());
        salvar(todo);
    }

    public List<Todo> listar(boolean feito) {
        List<Todo> listaSaida = new ArrayList<>();

        for(Todo obj : lista) {
            if(obj.isFeito() == feito) {
                listaSaida.add(obj);
            }
        }

        return listaSaida;
    }

    public void salvar(Todo obj) {
        if(obj.getId() == null) {
            // incluir
            obj.setId(id++);
            lista.add(obj);
        } else {
            // atualizar
            Todo todo = localizar(obj.getId());
            todo.setTitulo(obj.getTitulo());
            //todo.setFeito(obj.isFeito());
        }
    }

    public Todo localizar(long id) {
        Todo todo = null;
        for(Todo obj : lista) {
           if(obj.getId() == id) {
               todo = obj;
               break;
           }
        }
        return todo;
    }

    public void remover(long id) {
        Todo obj = localizar(id);

        if(obj != null)
            lista.remove(obj);
    }
}
