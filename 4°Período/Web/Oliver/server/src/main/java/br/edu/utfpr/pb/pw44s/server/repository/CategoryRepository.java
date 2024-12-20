package br.edu.utfpr.pb.pw44s.server.repository;

import java.util.List;

import org.springframework.data.jpa.repository.JpaRepository;

import br.edu.utfpr.pb.pw44s.server.model.Category;

public interface CategoryRepository extends JpaRepository<Category, Long> {
  List<Category> findByNameContaining(String name);
}