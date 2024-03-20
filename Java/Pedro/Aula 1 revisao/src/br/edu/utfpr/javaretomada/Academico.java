package br.edu.utfpr.javaretomada;

public class Academico extends Pessoa{
    private String ra;
    private Curso curso;

    public Academico() {
    }

    public Academico(String nome, double salario, int idade, String ra, Curso curso) {
        super(nome, salario, idade);
        this.ra = ra;
        this.curso = curso;
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

}
