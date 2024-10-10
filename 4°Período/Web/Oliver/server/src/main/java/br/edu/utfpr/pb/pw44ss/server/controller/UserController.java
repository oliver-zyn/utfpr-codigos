package br.edu.utfpr.pb.pw44ss.server.controller;

import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import br.edu.utfpr.pb.pw44ss.server.model.User;
import br.edu.utfpr.pb.pw44ss.server.service.UserService;

@RestController
@RequestMapping("users")
public class UserController {
  
  private final UserService userService;

  public UserController(UserService userService) {
    this.userService = userService;
  }

  @PostMapping
  public void createUser(@RequestBody User user) {
    userService.save(user);
  }

}
