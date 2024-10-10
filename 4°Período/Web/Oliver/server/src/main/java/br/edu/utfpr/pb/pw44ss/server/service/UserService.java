package br.edu.utfpr.pb.pw44ss.server.service;

import org.springframework.stereotype.Service;

import br.edu.utfpr.pb.pw44ss.server.model.User;
import br.edu.utfpr.pb.pw44ss.server.repository.UserRepository;

@Service
public class UserService {

  private final UserRepository userRepository;

  public UserService(UserRepository userRepository) {
    this.userRepository = userRepository;
  }

  public User save(User user) {
    return userRepository.save(user);
  }
}
