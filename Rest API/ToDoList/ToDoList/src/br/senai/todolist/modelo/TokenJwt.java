package br.senai.todolist.modelo;

public class TokenJwt {
	//classe para criar token
	public String getToken() {
		return token;
	}

	public void setToken(String token) {
		this.token = token;
	}

	private String token;
}
