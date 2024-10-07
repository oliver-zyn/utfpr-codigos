/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package entidades;

public class Pacote {
    private int pacotes_id;
    private int destinatario_id;
    private int numero_pedido;
    private String cpf_receptor;

    public Pacote() {
    }

    public Pacote(int destinatario_id, int numero_pedido, String cpf_receptor) {
        this.destinatario_id = destinatario_id;
        this.numero_pedido = numero_pedido;
        this.cpf_receptor = cpf_receptor;
    }

    public int getPacotes_id() {
        return pacotes_id;
    }

    public int getDestinatario_id() {
        return destinatario_id;
    }

    public int getNumero_pedido() {
        return numero_pedido;
    }

    public String getCpf_receptor() {
        return cpf_receptor;
    }

    public void setPacotes_id(int pacotes_id) {
        this.pacotes_id = pacotes_id;
    }

    public void setDestinatario_id(int destinatario_id) {
        this.destinatario_id = destinatario_id;
    }

    public void setNumero_pedido(int numero_pedido) {
        this.numero_pedido = numero_pedido;
    }

    public void setCpf_receptor(String cpf_receptor) {
        this.cpf_receptor = cpf_receptor;
    }

    @Override
    public String toString() {
        return "Pacotes{" + "pacotes_id=" + pacotes_id + ", destinatario_id=" + destinatario_id + ", numero_pedido=" + numero_pedido + ", cpf_receptor=" + cpf_receptor + '}';
    }
}
