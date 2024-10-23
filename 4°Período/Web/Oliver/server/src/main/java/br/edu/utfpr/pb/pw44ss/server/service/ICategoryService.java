package br.edu.utfpr.pb.pw44ss.server.service;

import java.util.List;

import br.edu.utfpr.pb.pw44ss.server.model.Category;

public interface ICategoryService extends ICrudService<Category, Long> {
  List<Category> findByName(String name);
}