package br.edu.utfpr.pb.pw44ss.server.dto;

import br.edu.utfpr.pb.pw44ss.server.model.User;
import jakarta.validation.constraints.NotNull;
import jakarta.validation.constraints.Pattern;
import jakarta.validation.constraints.Size;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class UserDTO {
  private Long id;

  @NotNull(message = "O atributo usuário não pode ser nulo.")
  @Size(min = 4, max= 50)
  private String username;

  @NotNull
  @Size(min = 4, max= 50)
  private String displayName;

  @NotNull
  @Size(min = 6)
  @Pattern(regexp = "^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d).*$")
  private String password;

  public void toDto(User user) {
    this.username = user.getUsername();
    this.displayName = user.getDisplayName();
    this.password = user.getPassword();
    this.id = user.getId();
  }

  public User fromDto() {
    User user = new User();
    user.setUsername(this.username);
    user.setDisplayName(this.displayName);
    user.setPassword(this.password);
    user.setId(this.id);
    return user;
  }
}
