
package br.senai.sp.informatica.todoapp.model;


import android.util.JsonReader;
import android.widget.Toast;

import org.codehaus.jackson.map.ObjectMapper;

import java.io.StringReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

import br.senai.sp.informatica.todoapp.Main;
import br.senai.sp.informatica.todoapp.lib.JSONParser;

public class TodoDao implements Dao {
    public static TodoDao instancia = new TodoDao();

    private final String url = "http://192.168.2.1:8080/TodoServer/";

    private TodoDao() {

    }

    public List<Todo> listar(boolean feito) {
        List<Todo> listaSaida = new ArrayList<>();

        try{
            String json = new JSONParser.Consultar(url + "lista/" + (feito ? 1:0),new JSONParser.DataCallBack(){
                @Override
                public void setResponse(int code, String json) {
                    if(code != 200){
                        Toast.makeText(Main.context,"Deu merda ao consultar os dados",Toast.LENGTH_LONG).show();
                    }
                }
            }).execute().get();
            ObjectMapper mapper = new ObjectMapper(); //prepara conversão

            listaSaida = Arrays.asList(mapper.readValue(new StringReader(json), Todo[].class));

        }catch(Exception excep){
            Toast.makeText(Main.context, excep.getMessage(), Toast.LENGTH_LONG).show();
        }

        return listaSaida;
    }

    public void salvar(Todo obj) {
        try{
            ObjectMapper mapper = new ObjectMapper();
            String json = mapper.writeValueAsString(obj);
            if(obj.getId() == null) {
                // incluir
                new JSONParser.Incluir(url,json,new JSONParser.LocationAndDataCallBack(){
                    @Override
                    public void setResponse(int code, String location, String json){
                        if(code != 201){
                            Toast.makeText(Main.context,"Deu merda ao incluir o TODO",Toast.LENGTH_LONG).show();
                        }
                }

            }).execute();
            }else {
                new JSONParser.Alterar(url + "todo/" + obj.getId(),json,new JSONParser.LocationCallBack(){
                    @Override
                    public void setResponse(int code, String location){
                        if(code != 200){
                            Toast.makeText(Main.context,"Deu merda ao alterar o TODO",Toast.LENGTH_LONG).show();
                        }
                    }

                }).execute();
            }
        }catch(Exception e) {
            Toast.makeText(Main.context,"Deu merda ao acessar server",Toast.LENGTH_LONG).show();
        }
    }

    public Todo localizar(long id) {
        try{
            String json3 = new JSONParser.Consultar(url + "todo/" + id, new JSONParser.DataCallBack() {
                @Override
                public void setResponse(int code, String json) {
                    if(code != 200){
                        Toast.makeText(Main.context,"Deu merda ao alterar o TODO",Toast.LENGTH_LONG).show();
                    }
                }
            }).execute().get();

            ObjectMapper mapper = new ObjectMapper();
            return mapper.readValue(new StringReader(json3),Todo.class);
        }catch (Exception e ){
            Toast.makeText(Main.context,"Deu merda ao acessar server",Toast.LENGTH_LONG).show();
        }

        return null;
    }

    public void remover(long id) {
        try{
            new JSONParser.Remover(url + "todo/" + id, new JSONParser.ResponseCodeCallBack(){
                @Override
                public void setResponse(int code){
                    if(code != 204){
                        Toast.makeText(Main.context,"Deu merda ao remover o TODO",Toast.LENGTH_LONG).show();
                    }
                    else{
                        Toast.makeText(Main.context,"Deletouuuuuuuu!",Toast.LENGTH_LONG).show();
                    }
                }
            }).execute();
        }catch(Exception e){
            Toast.makeText(Main.context,"Deu merda ao acessar server",Toast.LENGTH_LONG).show();
        }
    }
}
