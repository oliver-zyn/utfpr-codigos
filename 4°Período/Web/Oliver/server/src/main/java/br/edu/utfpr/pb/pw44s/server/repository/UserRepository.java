package br.edu.utfpr.pb.pw44s.server.repository;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import br.edu.utfpr.pb.pw44s.server.model.User;

@Repository
public interface UserRepository extends JpaRepository<User, Long> { 
  User findByUsername(String username);
}
