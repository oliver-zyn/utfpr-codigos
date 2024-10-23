package br.edu.utfpr.pb.pw44ss.server.repository;

import br.edu.utfpr.pb.pw44ss.server.model.Category;

import java.util.List;

import org.springframework.data.jpa.repository.JpaRepository;

public interface CategoryRepository extends JpaRepository<Category, Long> {
  List<Category> findByNameContaining(String name);
}