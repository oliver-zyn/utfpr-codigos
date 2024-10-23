package br.edu.utfpr.pb.pw44ss.server.controller;

import org.modelmapper.ModelMapper;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import br.edu.utfpr.pb.pw44ss.server.dto.UserDTO;
import br.edu.utfpr.pb.pw44ss.server.model.User;
import br.edu.utfpr.pb.pw44ss.server.service.UserService;
import br.edu.utfpr.pb.pw44ss.server.shared.GenericResponse;
import jakarta.validation.Valid;

@RestController
@RequestMapping("users")
public class UserController {

  private final UserService userService;
  private final ModelMapper modelMapper;

  public UserController(UserService userService, ModelMapper modelMapper) {
    this.userService = userService;
    this.modelMapper = modelMapper;
  }

  @PostMapping
  public ResponseEntity<GenericResponse> createUser(@RequestBody @Valid UserDTO user) {
    userService.save(modelMapper.map(user, User.class));

    return ResponseEntity.ok(new GenericResponse("User saved!"));
  }

}
