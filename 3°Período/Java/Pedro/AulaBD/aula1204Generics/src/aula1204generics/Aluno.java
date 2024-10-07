/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package aula1204generics;

/**
 *
 * @author geri_
 */
public class Aluno {
    private int matricula;
    private String cpf;
    private String nome;
    private char sexo;
    private int profissao;

    public Aluno() {
    }

    public Aluno(int matricula, String cpf, String nome, char sexo, int profissao) {
        this.matricula = matricula;
        this.cpf = cpf;
        this.nome = nome;
        this.sexo = sexo;
        this.profissao = profissao;
    }

    public int getMatricula() {
        return matricula;
    }

    public void setMatricula(int matricula) {
        this.matricula = matricula;
    }

    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public char getSexo() {
        return sexo;
    }

    public void setSexo(char sexo) {
        this.sexo = sexo;
    }

    public int getProfissao() {
        return profissao;
    }

    public void setProfissao(int profissao) {
        this.profissao = profissao;
    }

    @Override
    public String toString() {
        return "Aluno{" + "matricula=" + matricula + ", cpf=" + cpf + ", nome=" + nome + ", sexo=" + sexo + ", profissao=" + profissao + '}';
    }

    
}
