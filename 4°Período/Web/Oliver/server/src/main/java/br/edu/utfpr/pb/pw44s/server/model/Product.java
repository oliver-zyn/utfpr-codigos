package br.edu.utfpr.pb.pw44s.server.model;

import jakarta.validation.constraints.NotNull;
import jakarta.validation.constraints.Size;
import lombok.*;
import jakarta.persistence.*;

import java.math.BigDecimal;

@Entity
@Table(name = "tb_product")
@Getter
@Setter
@NoArgsConstructor
@AllArgsConstructor
@Builder
public class Product {
  @Id
  @GeneratedValue(strategy = GenerationType.IDENTITY)
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
  @ManyToOne
  @JoinColumn(name = "category_id", referencedColumnName = "id")
  private Category category;
}
