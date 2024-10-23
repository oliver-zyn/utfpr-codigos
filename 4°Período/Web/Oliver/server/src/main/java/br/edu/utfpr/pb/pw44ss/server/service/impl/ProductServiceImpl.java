package br.edu.utfpr.pb.pw44ss.server.service.impl;

import br.edu.utfpr.pb.pw44ss.server.model.Product;
import br.edu.utfpr.pb.pw44ss.server.repository.ProductRepository;
import br.edu.utfpr.pb.pw44ss.server.service.IProductService;
import org.springframework.data.jpa.repository.JpaRepository;

public class ProductServiceImpl extends CrudServiceImpl<Product, Long>
    implements IProductService {

  private final ProductRepository productRepository;

  public ProductServiceImpl(ProductRepository productRepository) {
    this.productRepository = productRepository;
  }

  @Override
  protected JpaRepository<Product, Long> getRepository() {
    return productRepository;
  }
}