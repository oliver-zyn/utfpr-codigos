package br.edu.utfpr.javaretomada;

public class Pessoa {

    private String nome;
    private double salario;
    private int idade;

    @Override
    public String toString() {
        return "{" +
            " nome='" + getNome() + "'" +
            ", salario='" + getSalario() + "'" +
            ", idade='" + getIdade() + "'" +
            "}";
    }

    public String getNome() {
        return this.nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public double getSalario() {
        return this.salario;
    }

    public void setSalario(double salario) {
        this.salario = salario;
    }

    public int getIdade() {
        return this.idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public Pessoa(String nome, double salario, int idade) {
        this.nome = nome;
        this.salario = salario;
        this.idade = idade;
    }

    public Pessoa() {
    }

    public double aumentaSalario(double pct) {
        double ret;
        this.setSalario(this.getSalario()+(this.getSalario()*pct/100));
        ret = this.getSalario();
        return ret;
    }
}
