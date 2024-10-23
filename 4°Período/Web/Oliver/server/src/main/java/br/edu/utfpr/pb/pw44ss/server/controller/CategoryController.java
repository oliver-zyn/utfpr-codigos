package br.edu.utfpr.pb.pw44ss.server.controller;

import br.edu.utfpr.pb.pw44ss.server.dto.CategoryDTO;
import br.edu.utfpr.pb.pw44ss.server.model.Category;
import br.edu.utfpr.pb.pw44ss.server.service.ICategoryService;
import br.edu.utfpr.pb.pw44ss.server.service.ICrudService;
import org.modelmapper.ModelMapper;
import org.springframework.web.bind.annotation.*;

@RestController

@RequestMapping("categories")
public class CategoryController extends CrudController<Category, CategoryDTO, Long> {
  private final ICategoryService categoryService;
  private final ModelMapper modelMapper;

  public CategoryController(ICategoryService categoryService,
                            ModelMapper modelMapper) {
      super(Category.class, CategoryDTO.class);
      this.categoryService = categoryService;
      this.modelMapper = modelMapper;
  }

  @Override
  protected ICrudService<Category, Long> getService() {
      return this.categoryService;
  }

  @Override
  protected ModelMapper getModelMapper() {
      return this.modelMapper;
  }
}