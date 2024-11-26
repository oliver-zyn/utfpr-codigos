package br.edu.utfpr.pb.pw44s.server.service.impl;

import java.util.List;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Service;

import br.edu.utfpr.pb.pw44s.server.model.Category;
import br.edu.utfpr.pb.pw44s.server.repository.CategoryRepository;
import br.edu.utfpr.pb.pw44s.server.service.ICategoryService;

@Service
public class CategoryServiceImpl extends CrudServiceImpl<Category, Long>
    implements ICategoryService {

  private final CategoryRepository categoryRepository;

  public CategoryServiceImpl(CategoryRepository categoryRepository) {
    this.categoryRepository = categoryRepository;
  }

  @Override
  protected JpaRepository<Category, Long> getRepository() {
    return categoryRepository;
  }

  @Override
  public List<Category> findByName(String name) {
    return categoryRepository.findByNameContaining(name);
  }
}