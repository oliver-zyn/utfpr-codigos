package br.edu.utfpr.pb.pw44ss.server.controller;

import java.util.HashMap;
import java.util.Map;

import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.validation.BindingResult;
import org.springframework.validation.FieldError;
import org.springframework.web.bind.MethodArgumentNotValidException;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseStatus;
import org.springframework.web.bind.annotation.RestController;

import br.edu.utfpr.pb.pw44ss.server.error.ApiError;
import br.edu.utfpr.pb.pw44ss.server.model.User;
import br.edu.utfpr.pb.pw44ss.server.service.UserService;
import br.edu.utfpr.pb.pw44ss.server.shared.GenericResponse;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.validation.Valid;

@RestController
@RequestMapping("users")
public class UserController {

  private final UserService userService;

  public UserController(UserService userService) {
    this.userService = userService;
  }

  @PostMapping
  public ResponseEntity<GenericResponse> createUser(@RequestBody @Valid User user) {
    userService.save(user);

    return ResponseEntity.ok(new GenericResponse("User saved!"));
  }

  @ExceptionHandler({ MethodArgumentNotValidException.class })
  @ResponseStatus(HttpStatus.BAD_REQUEST)
  public ApiError handlerValidationException(MethodArgumentNotValidException exception, HttpServletRequest request) {

    BindingResult bindingResult = exception.getBindingResult();
    Map<String, String> validationErrors = new HashMap<>();
    for (FieldError fieldError : bindingResult.getFieldErrors()) {
      validationErrors.put(fieldError.getField(), fieldError.getDefaultMessage());
    }

    return new ApiError(HttpStatus.BAD_REQUEST.value(), "validation error", request.getServletPath(), validationErrors);
  }

}
