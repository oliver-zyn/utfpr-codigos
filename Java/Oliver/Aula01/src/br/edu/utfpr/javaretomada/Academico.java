package br.edu.utfpr.javaretomada;

public class Academico extends Pessoa {
  private String ra;
  private Curso curso;

  public Academico(String ra, Curso curso, String nome, double salario, int idade) {
    super(nome, salario, idade);
    this.ra = ra;
    this.curso = curso;
  }

  public Academico() {
  }

  public String getRa() {
    return this.ra;
  }

  public void setRa(String ra) {
    this.ra = ra;
  }

  public Curso getCurso() {
    return this.curso;
  }

  public void setCurso(Curso curso) {
    this.curso = curso;
  }

  @Override
  public String toString() {
    return "{" +
      " ra='" + getRa() + "'" +
      ", curso='" + getCurso() + "'" +
      "}";
  }
}
