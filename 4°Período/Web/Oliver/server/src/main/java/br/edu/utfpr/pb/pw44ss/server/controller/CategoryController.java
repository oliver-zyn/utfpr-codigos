package br.edu.utfpr.pb.pw44ss.server.controller;

import br.edu.utfpr.pb.pw44ss.server.model.Category;
import br.edu.utfpr.pb.pw44ss.server.service.ICategoryService;
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

@RequestMapping("categories")
public class CategoryController {
  private final ICategoryService categoryService;

  public CategoryController(ICategoryService categoryService) {
    this.categoryService = categoryService;
  }

  @PostMapping
  public ResponseEntity<Category> create(@RequestBody @Valid Category category) {
    Category categoryCreated = categoryService.save(category);
    URI location = ServletUriComponentsBuilder.fromCurrentRequest().path("/{id}")
        .buildAndExpand(categoryCreated.getId()).toUri();
    return ResponseEntity.created(location).body(categoryCreated);
  }

  @GetMapping("{id}")
  public ResponseEntity<Category> findOne(@PathVariable Long id) {
    return ResponseEntity.ok(categoryService.findById(id));
  }

  @GetMapping
  public ResponseEntity<List<Category>> findAll() {
    return ResponseEntity.ok(categoryService.findAll());
  }

  @GetMapping("exists/{id}")
  public ResponseEntity<Boolean> exists(@PathVariable Long id) {
    return ResponseEntity.ok(categoryService.exists(id));
  }

  @GetMapping("count")
  public ResponseEntity<Long> count() {
    return ResponseEntity.ok(categoryService.count());
  }

  @DeleteMapping("{id}")
  @ResponseStatus(HttpStatus.NO_CONTENT)
  public void delete(@PathVariable Long id) {
    categoryService.delete(id);
  }

  @GetMapping("page")
  public ResponseEntity<Page<Category>> findPage(@RequestParam int page, @RequestParam int size,
      @RequestParam(required = false) String order, @RequestParam(required = false) Boolean asc) {
    
    page -= 1;
    PageRequest pageRequest = PageRequest.of(page, size);

    if (order != null && asc != null) {
      pageRequest = PageRequest.of(page, size, asc ? Sort.Direction.ASC : Sort.Direction.DESC, order);
    }

    return ResponseEntity.ok(categoryService.findAll(pageRequest));
  }

}