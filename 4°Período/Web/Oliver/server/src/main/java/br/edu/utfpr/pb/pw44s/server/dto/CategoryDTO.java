package br.edu.utfpr.pb.pw44s.server.dto;

import br.edu.utfpr.pb.pw44s.server.model.Category;
import jakarta.validation.constraints.NotNull;
import jakarta.validation.constraints.Size;

public class CategoryDTO {
  private Long id;
  
  @NotNull
  @Size(min = 2, max = 50)
  private String name;

  public void toDto(Category category) {
    this.name = category.getName();
    this.id = category.getId();
  }

  public Category fromDto() {
    Category category = new Category();
    category.setName(this.name);
    category.setId(this.id);
    return category;
  }
}