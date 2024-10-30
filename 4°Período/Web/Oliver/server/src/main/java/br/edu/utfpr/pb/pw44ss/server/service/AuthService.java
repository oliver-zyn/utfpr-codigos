package br.edu.utfpr.pb.pw44ss.server.service;

import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.core.userdetails.UserDetailsService;
import org.springframework.security.core.userdetails.UsernameNotFoundException;
import org.springframework.stereotype.Service;
import br.edu.utfpr.pb.pw44ss.server.model.User;

import br.edu.utfpr.pb.pw44ss.server.repository.UserRepository;

@Service
public class AuthService implements UserDetailsService {
  private final UserRepository userRepository;

  public AuthService(UserRepository userRepository) {
    this.userRepository = userRepository;
  }

  @Override
  public UserDetails loadUserByUsername(String username) throws UsernameNotFoundException {
    User user = this.userRepository.findByUsername(username);
    
    if (user == null) {
      throw new UsernameNotFoundException("Usuário não encontrado!");
    }

    return user;
  }
  
}