package util;

import entidades.Destinatario;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

public class DestinatarioDAO extends AbstractDAO<Destinatario> {
    
    private final Connection conexao;
    private Logger logger = Logger.getLogger("DestinatarioDAO");
    ResultSet rs;
    PreparedStatement stmt;
    
    public DestinatarioDAO() {
        conexao = ConexaoDAO.getInstance().getCon();
    }
    
    @Override
    protected Destinatario mapearParaEntidade(ResultSet rs) {
        try {
            Destinatario d = new Destinatario();
            d.setDestinatario_id(rs.getInt("destinatario_id"));
            d.setNome(rs.getString("nome"));
            d.setCPF(rs.getString("cpf"));
            d.setTelefone(rs.getString("telefone"));
            d.setRua(rs.getString("rua"));
            d.setBairro(rs.getString("bairro"));
            d.setNumero(rs.getInt("numero"));
            d.setCep(rs.getString("cep"));
            return d;
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao mapear entidade: {0}", ex.getMessage());
            return null;
        }
    }
    
    @Override
    public List<Destinatario> listar() {
        String sql = "SELECT * FROM DESTINATARIOS";
        List<Destinatario> retorno = new ArrayList<>();

        try {
            stmt = conexao.prepareStatement(sql);
            logger.info(sql);
            rs = stmt.executeQuery();
            while (rs.next()) {
                Destinatario d = mapearParaEntidade(rs);
                retorno.add(d);
            }
            stmt.close();
            rs.close();
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao executar consulta: {0}", ex.getMessage());
        }

        return retorno;
    }
    
    @Override
    public boolean inserir(Destinatario d) {
        String sql = "INSERT INTO DESTINATARIOS(nome, cpf, telefone, rua, bairro, numero, cep) VALUES(?,?,?,?,?,?,?)";
        try {
            stmt = conexao.prepareStatement(sql);
            stmt.setString(1, d.getNome());
            stmt.setString(2, d.getCPF());
            stmt.setString(3, d.getTelefone());
            stmt.setString(4, d.getRua());
            stmt.setString(5, d.getBairro());
            stmt.setInt(6, d.getNumero());
            stmt.setString(7, d.getCep());
            stmt.execute();
            logger.info("Insercao no banco de dados realizada!");
            stmt.close();
            return true;
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao executar consulta: {0}", ex.getMessage());
            return false;
        }
    }
    
    @Override
    public boolean remover(int id) {
        String sql = "DELETE FROM DESTINATARIOS WHERE destinatario_id=?";
        try {
            stmt = conexao.prepareStatement(sql);
            stmt.setInt(1, id);
            stmt.execute();
            logger.info("Deleção no banco de dados realizada!");
            stmt.close();
            return true;
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao executar consulta: {0}", ex.getMessage());
            return false;
        }
    }
    
    @Override
    public boolean alterar(Destinatario d) {
        String sql = "UPDATE DESTINATARIOS SET nome=?, cpf=?, telefone=?, rua=?, bairro=?, numero=?, cep=? WHERE destinatario_id=?";
        try {
            stmt = conexao.prepareStatement(sql);
            stmt.setString(1, d.getNome());
            stmt.setString(2, d.getCPF());
            stmt.setString(3, d.getTelefone());
            stmt.setString(4, d.getRua());
            stmt.setString(5, d.getBairro());
            stmt.setInt(6, d.getNumero());
            stmt.setString(7, d.getCep());
            stmt.setInt(8, d.getDestinatario_id());
            stmt.execute();
            logger.info("Alteracao no banco de dados realizada!");
            stmt.close();
            return true;
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao executar consulta: {0}", ex.getMessage());
            return false;
        }
    }
    
    @Override
    public Destinatario buscarPorCodigo(int id) {
        String sql = "SELECT * FROM DESTINATARIOS WHERE destinatario_id=?";
        Destinatario d = new Destinatario();
        try {
            stmt = conexao.prepareStatement(sql);
            stmt.setInt(1, id);
            rs = stmt.executeQuery();
            while (rs.next()) {
                d = mapearParaEntidade(rs);
            }
            return d;
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao executar consulta: {0}", ex.getMessage());
            return d;
        } finally {
            try {
                stmt.close();
            } catch (SQLException ex) {
                logger.log(Level.SEVERE, "Erro ao fechar conexão: {0}", ex.getMessage());
            }
        }
    }
}

