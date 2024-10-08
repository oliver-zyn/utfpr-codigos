package br.edu.utfpr.pb.pw44ss.server;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.boot.test.web.client.TestRestTemplate;
import org.springframework.http.ResponseEntity;
import org.springframework.test.context.ActiveProfiles;

import br.edu.utfpr.pb.pw44ss.server.model.User;

import static org.assertj.core.api.Assertions.assertThat;

import org.apache.hc.core5.http.HttpStatus;

@SpringBootTest(webEnvironment = SpringBootTest.WebEnvironment.RANDOM_PORT)
@ActiveProfiles("test")
public class UserControllerTest {
  
  @Autowired
  TestRestTemplate testRestTemplate;

  @Test
  public void postUser_whenUserIsValid_receiveOK() {
    User user = new User();
    user.setUsername("test-user");
    user.setDisplayName("test-display");
    user.setPassword("P4ssword");
  
    ResponseEntity<Object> response = testRestTemplate.postForEntity("/users", user, Object.class);

    assertThat(response.getStatusCode()).isEqualTo(HttpStatus.SC_OK);
  }
}
