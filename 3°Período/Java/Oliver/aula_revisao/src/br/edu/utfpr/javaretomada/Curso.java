package br.edu.utfpr.javaretomada;

public class Curso {
  private String nome;
  private int codigo;

  public Curso(String nome, int codigo) {
    this.nome = nome;
    this.codigo = codigo;
  }

  public Curso() {
  }

  public String getNome() {
    return this.nome;
  }

  public void setNome(String nome) {
    this.nome = nome;
  }

  public int getCodigo() {
    return this.codigo;
  }

  public void setCodigo(int codigo) {
    this.codigo = codigo;
  }

  @Override
  public String toString() {
    return "{" +
      " nome='" + getNome() + "'" +
      ", codigo='" + getCodigo() + "'" +
      "}";
  }
}
