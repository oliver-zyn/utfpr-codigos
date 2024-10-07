package classes;

public class Cliente {
    private static int contadorClientes = 0;
    private int codigoCliente;
    private String nome;

    public Cliente(String nome) {
        this.nome = nome;
        this.codigoCliente = ++contadorClientes;
    }

    public int getCodigoCliente() {
        return this.codigoCliente;
    }

    public void setCodigoCliente(int codigoCliente) {
        this.codigoCliente = codigoCliente;
    }

    public String getNome() {
        return this.nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }
    
    @Override
    public String toString() {
        return "{" +
            " codigoCliente='" + getCodigoCliente() + "'" +
            ", nome='" + getNome() + "'" +
            "}";
    }
}
