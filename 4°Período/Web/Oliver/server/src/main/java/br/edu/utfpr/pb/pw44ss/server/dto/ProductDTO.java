package br.edu.utfpr.pb.pw44ss.server.dto;

import java.math.BigDecimal;

import br.edu.utfpr.pb.pw44ss.server.model.Category;
import br.edu.utfpr.pb.pw44ss.server.model.Product;
import jakarta.validation.constraints.NotNull;
import jakarta.validation.constraints.Size;

public class ProductDTO {
  private Long id;

  @NotNull
  @Size(min = 2, max = 50)
  private String name;

  @NotNull
  @Size(min = 2, max = 500)
  private String description;

  @NotNull
  private BigDecimal price;

  @NotNull
  private Category category;

  public void toDto(Product product) {
    this.name = product.getName();
    this.description = product.getDescription();
    this.price = product.getPrice();
    this.category = product.getCategory();
  }

  public Product fromDto() {
    Product product = new Product();
    product.setName(this.name);
    product.setDescription(this.description);
    product.setPrice(this.price);
    product.setId(this.id);
    return product;
  }
}
