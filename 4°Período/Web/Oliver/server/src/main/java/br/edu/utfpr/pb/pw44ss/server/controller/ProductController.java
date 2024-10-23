package br.edu.utfpr.pb.pw44ss.server.controller;

import br.edu.utfpr.pb.pw44ss.server.dto.ProductDTO;
import br.edu.utfpr.pb.pw44ss.server.model.Product;
import br.edu.utfpr.pb.pw44ss.server.service.ICrudService;
import br.edu.utfpr.pb.pw44ss.server.service.IProductService;
import org.modelmapper.ModelMapper;
import org.springframework.web.bind.annotation.*;

@RestController

@RequestMapping("products")
public class ProductController extends CrudController<Product, ProductDTO, Long> {
  private final IProductService productService;
  private final ModelMapper modelMapper;

  public ProductController(IProductService productService, ModelMapper modelMapper) {
      super(Product.class, ProductDTO.class);
      this.productService = productService;
      this.modelMapper = modelMapper;
  }

  @Override
  protected ICrudService<Product, Long> getService() {
      return productService;
  }

  @Override
  protected ModelMapper getModelMapper() {
      return modelMapper;
  }
}