package br.senai.todolist.dao;

import javax.enterprise.inject.Typed;
import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;
import javax.persistence.TypedQuery;

import org.springframework.stereotype.Repository;
import org.springframework.transaction.annotation.Transactional;

import br.senai.todolist.modelo.Usuario;

@Repository
public class UsuarioDAO {
	@PersistenceContext
	private EntityManager manager;
	
	@Transactional
	public void inserirUsuario ( Usuario usuario) {
		//inserindo usuário
		manager.persist(usuario);
	}
	
	public Usuario buscarUsuario ( Long idUser ){
		return manager.find(Usuario.class,idUser);
	}
	
	@Transactional
	public void deletarUsuario ( Long idUser){
		Usuario user = manager.find(Usuario.class,idUser);
		manager.remove(user);
	}
	
	public Usuario logar(Usuario usuario){
		
		TypedQuery<Usuario> query = manager.createQuery( "select u from Usuario u where u.login= :login "
				+ "and u.senha = :senha",Usuario.class);
		query.setParameter("login", usuario.getLogin());
		query.setParameter("senha", usuario.getSenha());
		try{
			//precisa do catch pois query.getSingleResult não retorna null se não encontrar
			return usuario = query.getSingleResult();
		}catch (Exception e) {
			// TODO: handle exception
			return null;
		}
	}
}
