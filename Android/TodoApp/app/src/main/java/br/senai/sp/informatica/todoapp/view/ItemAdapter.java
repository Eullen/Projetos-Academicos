package br.senai.sp.informatica.todoapp.view;

import android.app.Activity;
import android.content.Context;
import android.support.constraint.ConstraintLayout;
import android.util.SparseArray;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.CheckBox;
import android.widget.TextView;

import br.senai.sp.informatica.todoapp.R;
import br.senai.sp.informatica.todoapp.model.Item;
import br.senai.sp.informatica.todoapp.model.ItemDao;

public class ItemAdapter extends BaseAdapter
        implements  View.OnClickListener {
    private ItemDao dao;
    private SparseArray<Long> mapa;
    private Activity activity;

    public ItemAdapter(Activity activity, ItemDao dao) {
        this.activity = activity;
        this.dao = dao;

        criarMapa();
    }

    private void criarMapa() {
        mapa = new SparseArray<>();
        int id = 0;

        for(Item item : dao.listar()) {
            mapa.put(id++, item.getId());
        }
    }

    @Override
    public void notifyDataSetChanged() {
        criarMapa();
        super.notifyDataSetChanged();
    }

    @Override
    public int getCount() {
        return mapa.size();
    }

    @Override
    public Object getItem(int id) {
        return dao.localizar(id);
    }

    @Override
    public long getItemId(int lin) {
        return mapa.get(lin);
    }

    @Override
    public View getView(int lin, View detalhe, ViewGroup parent) {
        ConstraintLayout layout;

        if(detalhe == null) {
            // Criar o detalhe
            Context ctx = parent.getContext();
            layout = new ConstraintLayout(ctx);
            LayoutInflater service = (LayoutInflater)
                    ctx.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
            service.inflate(R.layout.detalhe_item, layout, true);
        } else {
            // reutiliza o detalhe
            layout = (ConstraintLayout)detalhe;
        }

        // atribuir valores aos campos do layout
        Item obj = dao.localizar(mapa.get(lin));

        TextView edDesc = (TextView)layout.findViewById(R.id.edItem);
        edDesc.setText(obj.getDescricao());

        TextView tvDel = (TextView)layout.findViewById(R.id.tvDel);
        tvDel.setOnClickListener(this);
        tvDel.setTag(obj.getId());

        CheckBox ckDel = (CheckBox)layout.findViewById(R.id.ckDel);
        ckDel.setChecked(obj.isFeito());
        ckDel.setOnClickListener(this);
        ckDel.setTag(obj.getId());

        return layout;
    }

    @Override
    public void onClick(View view) {
        if(view.getId() == R.id.ckDel) {
            // Marca o item como Feito/A Fazer
            Item item = dao.localizar((long)view.getTag());
            item.setFeito(!item.isFeito());
            dao.salvar(item);
        } else {
            // Apresenta o diálogo para confirmar a exclusão do item
            Alerta alerta = new Alerta();
            alerta.setId((long) view.getTag());
            alerta.setAdapter(this);
            alerta.setDao(dao);
            alerta.show(activity.getFragmentManager(), "Alerta");
        }
    }
}
