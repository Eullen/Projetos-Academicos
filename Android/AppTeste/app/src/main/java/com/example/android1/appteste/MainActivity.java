package com.example.android1.appteste;

import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    private EditText edNome;
    private EditText edIdade;
    private Button btnOk;
    private Button btnLimpar;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        setContentView(R.layout.activity_main);
        edNome = (EditText)findViewById(R.id.edNome);
        edIdade = (EditText)findViewById(R.id.edIdade);
        btnOk = (Button)findViewById(R.id.btnOk);
        btnOk.setOnClickListener(this);
        btnLimpar = (Button)findViewById(R.id.btnLimpar);
        btnLimpar.setOnClickListener(this);

    }

    public void onClick(View view){
        if(view.equals(btnOk)){
            String nome = edNome.getText().toString();
            int idade = Integer.parseInt(edIdade.getText().toString());

            String msg = "Bem vindo, " +nome+ "\nsua idade é de "+idade;
            Toast.makeText(getBaseContext(),msg,Toast.LENGTH_LONG).show();
            //Snackbar.make(,msg,Snackbar.LENGTH_LONG) //só aparece com o teclado desligado

           /* edNome.setText("");
            edIdade.setText("");
            edNome.requestFocus();*/

        }else if(view.equals(btnLimpar)){

            edNome.setText("");
            edIdade.setText("");
            edNome.requestFocus();
        }
    }


}
