package br.edu.utfpr.pb.pw44ss.server.repository;

import br.edu.utfpr.pb.pw44ss.server.model.Product;
import org.springframework.data.jpa.repository.JpaRepository;

public interface ProductRepository extends JpaRepository<Product, Long> {
}