/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package entidades;

/**
 *
 * @author geri_
 */
public class Palestrante {
    private int id;
    private String nome;
    private String descricao;
    private String areaAtuacao;

    public Palestrante() {
    }

    public Palestrante(String nome, String descricao, String areaAtuacao) {
        this.nome = nome;
        this.descricao = descricao;
        this.areaAtuacao = areaAtuacao;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }
    
    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }
    
    public String getDescricao() {
        return descricao;
    }

    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }

    public String getAreaAtuacao() {
        return areaAtuacao;
    }

    public void setAreaAtuacao(String areaAtuacao) {
        this.areaAtuacao = areaAtuacao;
    }

    @Override
    public String toString() {
        return "Palestrante{" + "id=" + id + ", nome=" + nome + ", descricao=" + descricao + ", areaAtuacao=" + areaAtuacao + '}';
    }
    
}
