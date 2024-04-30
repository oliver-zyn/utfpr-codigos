/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package entidades;

public class Usuario {
    
    private int usuario_id;
    private String CPF;
    private String senha;
    private int usuario_admin;

    public Usuario(String CPF, String senha, int usuario_admin) {
        this.CPF = CPF;
        this.senha = senha;
        this.usuario_admin = usuario_admin;
    }
    
    public Usuario() {
    }

    public int getUsuario_id() {
        return usuario_id;
    }

    public String getCPF() {
        return CPF;
    }

    public String getSenha() {
        return senha;
    }

    public int getUsuario_admin() {
        return usuario_admin;
    }

    public void setUsuario_id(int usuario_id) {
        this.usuario_id = usuario_id;
    }

    public void setCPF(String CPF) {
        this.CPF = CPF;
    }

    public void setSenha(String senha) {
        this.senha = senha;
    }

    public void setUsuario_admin(int usuario_admin) {
        this.usuario_admin = usuario_admin;
    }

    @Override
    public String toString() {
        return "Usuario{" + "usuario_id=" + usuario_id + ", CPF=" + CPF + ", senha=" + senha + ", usuario_admin=" + usuario_admin + '}';
    }
    
}
