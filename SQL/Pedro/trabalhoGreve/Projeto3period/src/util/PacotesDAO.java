package util;

import entidades.Pacote;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

public class PacotesDAO extends AbstractDAO<Pacote> {
    
    private final Connection conexao;
    private Logger logger = Logger.getLogger("PacoteDAO");
    ResultSet rs;
    PreparedStatement stmt;
    
    public PacotesDAO() {
        conexao = ConexaoDAO.getInstance().getCon();
    }
    
    @Override
    protected Pacote mapearParaEntidade(ResultSet rs) {
        try {
            Pacote p = new Pacote();
            p.setPacotes_id(rs.getInt("pacote_id"));
            p.setDestinatario_id(rs.getInt("destinatario_id"));
            p.setNumero_pedido(rs.getInt("numero_pedido"));
            p.setCpf_receptor(rs.getString("cpf_recebedor"));
            return p;
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao mapear entidade: {0}", ex.getMessage());
            return null;
        }
    }
    
    @Override
    public List<Pacote> listar() {
        String sql = "SELECT * FROM PACOTES";
        List<Pacote> retorno = new ArrayList<>();

        try {
            stmt = conexao.prepareStatement(sql);
            logger.info(sql);
            rs = stmt.executeQuery();
            while (rs.next()) {
                Pacote p = mapearParaEntidade(rs);
                retorno.add(p);
            }
            stmt.close();
            rs.close();
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao executar consulta: {0}", ex.getMessage());
        }

        return retorno;
    }
    
    @Override
    public boolean inserir(Pacote p) {
        String sql = "INSERT INTO PACOTES(destinatario_id, numero_pedido, cpf_recebedor) VALUES(?,?,?)";
        try {
            stmt = conexao.prepareStatement(sql);
            stmt.setInt(1, p.getDestinatario_id());
            stmt.setInt(2, p.getNumero_pedido());
            stmt.setString(3, p.getCpf_receptor());
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
        String sql = "DELETE FROM PACOTES WHERE pacote_id=?";
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
    public boolean alterar(Pacote p) {
        String sql = "UPDATE PACOTES SET destinatario_id=?, numero_pedido=?, cpf_recebedor=? WHERE pacote_id=?";
        try {
            stmt = conexao.prepareStatement(sql);
            stmt.setInt(1, p.getDestinatario_id());
            stmt.setInt(2, p.getNumero_pedido());
            stmt.setString(3, p.getCpf_receptor());
            stmt.setInt(4, p.getPacotes_id());
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
    public Pacote buscarPorCodigo(int id) {
        String sql = "SELECT * FROM PACOTES WHERE pacote_id=?";
        Pacote p = new Pacote();
        try {
            stmt = conexao.prepareStatement(sql);
            stmt.setInt(1, id);
            rs = stmt.executeQuery();
            while (rs.next()) {
                p = mapearParaEntidade(rs);
            }
            return p;
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao executar consulta: {0}", ex.getMessage());
            return p;
        } finally {
            try {
                stmt.close();
            } catch (SQLException ex) {
                logger.log(Level.SEVERE, "Erro ao fechar conexão: {0}", ex.getMessage());
            }
        }
    }
}
