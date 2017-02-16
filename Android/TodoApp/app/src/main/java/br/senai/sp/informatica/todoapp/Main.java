package br.senai.sp.informatica.todoapp;

import android.app.Application;
import android.content.Context;


public class Main extends Application {
    public static Context context; //para todo mundo visulizar contexto

    @Override
    public void onCreate() {
        super.onCreate();
        context = getApplicationContext();
    }
}
