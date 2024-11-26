package br.edu.utfpr.pb.pw44s.server.controller;

import org.modelmapper.ModelMapper;
import org.springframework.web.bind.annotation.*;

import br.edu.utfpr.pb.pw44s.server.dto.CategoryDTO;
import br.edu.utfpr.pb.pw44s.server.model.Category;
import br.edu.utfpr.pb.pw44s.server.service.ICategoryService;
import br.edu.utfpr.pb.pw44s.server.service.ICrudService;

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