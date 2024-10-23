package br.edu.utfpr.pb.pw44ss.server.controller;

import br.edu.utfpr.pb.pw44ss.server.model.Product;
import br.edu.utfpr.pb.pw44ss.server.service.IProductService;
import jakarta.validation.Valid;

import org.springframework.data.domain.Page;
import org.springframework.data.domain.PageRequest;
import org.springframework.data.domain.Sort;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.servlet.support.ServletUriComponentsBuilder;
import java.net.URI;
import java.util.List;

import org.springframework.web.bind.annotation.GetMapping;

@RestController

@RequestMapping("products")
public class ProductController {
  private final IProductService productService;

  public ProductController(IProductService productService) {
    this.productService = productService;
  }

  @PostMapping
  public ResponseEntity<Product> create(@RequestBody @Valid Product product) {
    Product ProductCreated = productService.save(product);
    URI location = ServletUriComponentsBuilder.fromCurrentRequest().path("/{id}")
        .buildAndExpand(ProductCreated.getId()).toUri();

    return ResponseEntity.created(location).body(ProductCreated);
  }

  @GetMapping("{id}")
  public ResponseEntity<Product> findOne(@PathVariable Long id) {
    return ResponseEntity.ok(productService.findById(id));
  }

  @GetMapping
  public ResponseEntity<List<Product>> findAll() {
    return ResponseEntity.ok(productService.findAll());
  }

  @GetMapping("exists/{id}")
  public ResponseEntity<Boolean> exists(@PathVariable Long id) {
    return ResponseEntity.ok(productService.exists(id));
  }

  @GetMapping("count")
  public ResponseEntity<Long> count() {
    return ResponseEntity.ok(productService.count());
  }

  @DeleteMapping("{id}")
  @ResponseStatus(HttpStatus.NO_CONTENT)
  public void delete(@PathVariable Long id) {
    productService.delete(id);
  }

  @GetMapping("page")
  public ResponseEntity<Page<Product>> findPage(@RequestParam int page, @RequestParam int size,
      @RequestParam(required = false) String order, @RequestParam(required = false) Boolean asc) {
    
    page -= 1;
    PageRequest pageRequest = PageRequest.of(page, size);

    if (order != null && asc != null) {
      pageRequest = PageRequest.of(page, size, asc ? Sort.Direction.ASC : Sort.Direction.DESC, order);
    }

    return ResponseEntity.ok(productService.findAll(pageRequest));
  }

}