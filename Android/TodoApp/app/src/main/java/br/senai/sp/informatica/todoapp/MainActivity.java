package br.senai.sp.informatica.todoapp;

import android.content.Intent;
import android.support.design.widget.FloatingActionButton;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.ListViewCompat;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;
import android.widget.TabHost;

import br.senai.sp.informatica.todoapp.R;
import br.senai.sp.informatica.todoapp.view.DetalheTodo;
import br.senai.sp.informatica.todoapp.view.TodoAdapter;

public class MainActivity extends AppCompatActivity
        implements TabHost.OnTabChangeListener,
                   AdapterView.OnItemClickListener,
                    View.OnClickListener {
    private TabHost tabHost;
    private TodoAdapter adapterAFazer;
    private TodoAdapter adapterFeito;

    public static final int EDITAR_ITEM = 0;
    public static final int INCLUIR_ITEM = 1;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        tabHost = (TabHost)findViewById(R.id.tab_host);
        tabHost.setup();

        TabHost.TabSpec spec = tabHost.newTabSpec("A Fazer");
        spec.setContent(R.id.layout_afazer);
        spec.setIndicator("A Fazer");
        tabHost.addTab(spec);

        spec = tabHost.newTabSpec("Concluídos");
        spec.setContent(R.id.layout_concluido);
        spec.setIndicator("Concluídos");
        tabHost.addTab(spec);

        tabHost.setOnTabChangedListener(this);

        ListView listaAFazer = (ListView)findViewById(R.id.lista_afazer);
        adapterAFazer = new TodoAdapter(this, false);
        listaAFazer.setAdapter(adapterAFazer);
        listaAFazer.setOnItemClickListener(this);

        ListView listaConcluido = (ListView)findViewById(R.id.lista_concluido);
        adapterFeito = new TodoAdapter(this, true);
        listaConcluido.setAdapter(adapterFeito);
        listaConcluido.setOnItemClickListener(this);

        FloatingActionButton fab = (FloatingActionButton)findViewById(R.id.bt_adicionar);
        fab.setOnClickListener(this);
    }

    @Override
    public void onTabChanged(String tabId) {
        if (tabId.equals("A Fazer")) {
            tabHost.setCurrentTab(0);
        } else {
            tabHost.setCurrentTab(1);
        }
    }

    @Override
    public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
        Intent intent = new Intent(getBaseContext(), DetalheTodo.class);
        intent.putExtra("id", id);
        startActivityForResult(intent, EDITAR_ITEM);
    }

    @Override
    public void onClick(View v) {
        Intent intent = new Intent(getBaseContext(), DetalheTodo.class);
        startActivityForResult(intent, INCLUIR_ITEM);
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        if(resultCode == RESULT_OK) {
            adapterAFazer.notifyDataSetChanged();
            adapterFeito.notifyDataSetChanged();
        }
    }
}
