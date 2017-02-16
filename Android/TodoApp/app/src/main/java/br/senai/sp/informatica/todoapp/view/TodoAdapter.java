package br.senai.sp.informatica.todoapp.view;

import android.app.Activity;
import android.content.Context;
import android.support.constraint.ConstraintLayout;
import android.util.SparseArray;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.TextView;

import br.senai.sp.informatica.todoapp.R;
import br.senai.sp.informatica.todoapp.model.Todo;
import br.senai.sp.informatica.todoapp.model.TodoDao;

public class TodoAdapter extends BaseAdapter
            implements  View.OnClickListener {
    private static TodoDao dao = TodoDao.instancia;
    private SparseArray<Long> mapa; // <===== TODO: avisar
    private boolean feito;
    private Activity activity;

    public TodoAdapter(Activity activity, boolean feito) {
        this.feito = feito;
        this.activity = activity;
        criarMapa();
    }

    private void criarMapa() {
        mapa = new SparseArray<>();
        int id = 0;

        for(Todo obj : dao.listar(feito)) {
            mapa.put(id++, obj.getId()); // <===== TODO: avisar
        }
    }

    @Override
    public void notifyDataSetChanged() {
        criarMapa();
        super.notifyDataSetChanged();
    }

    // Informa quantas linhas devem ser exibidas
    @Override
    public int getCount() {
        return mapa.size();
    }

    // Retorma o objeto que reside na linha informada
    @Override
    public Object getItem(int linha) { // <===== TODO: avisar
        return dao.localizar(mapa.get(linha)); // <===== TODO: avisar
    }

    // Retorna a chave primária (id) do objeto que reside na linha informada
    @Override
    public long getItemId(int lin) {
        return mapa.get(lin);
    }

    // Constroi e retorna o Layout a ser apresentado na linha do ListView
    @Override
    public View getView(int lin, View detalhe, ViewGroup parent) {
        ConstraintLayout layout;

        if(detalhe == null) {
            // Criar o detalhe
            Context ctx = parent.getContext();
            layout = new ConstraintLayout(ctx);
            LayoutInflater service = (LayoutInflater)
               ctx.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
            service.inflate(R.layout.detalhe_todo, layout, true);
        } else {
            // reutiliza o detalhe
            layout = (ConstraintLayout)detalhe;
        }

        //pntando feito
        if(feito){
            layout.setBackgroundColor(parent.getResources().getColor(R.color.colorAccent));
        }else{
            layout.setBackgroundColor(parent.getResources().getColor(R.color.colorNaoFeito));
        }


        // atribuir valores aos campos do layout
        Todo obj = dao.localizar(mapa.get(lin)); // <===== TODO: avisar

        TextView tvTitulo = (TextView)layout.findViewById(R.id.edItem);
        tvTitulo.setText(obj.getTitulo());

        TextView tvDel = (TextView)layout.findViewById(R.id.tvDel);
        tvDel.setOnClickListener(this);
        tvDel.setTag(obj.getId());

        return layout;
    }

    // O mecanismo que apresenta o diálogo de confirmação de exclusão de Linha
    @Override
    public void onClick(View view) {
        if(view instanceof TextView) {
            long id = (long)view.getTag();
            Alerta alerta = new Alerta();
            alerta.setId(id);
            alerta.setAdapter(this);
            alerta.setDao(dao);
            alerta.show(activity.getFragmentManager(), "Alerta");
        }
    }

}
