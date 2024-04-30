package util;

import entidades.Situacoes;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

public class SituacoesDAO extends AbstractDAO<Situacoes> {
    
    private final Connection conexao;
    private Logger logger = Logger.getLogger("SituacoesDAO");
    ResultSet rs;
    PreparedStatement stmt;
    
    public SituacoesDAO() {
        conexao = ConexaoDAO.getInstance().getCon();
    }
    
    @Override
    protected Situacoes mapearParaEntidade(ResultSet rs) {
        try {
            Situacoes s = new Situacoes();
            s.setSituacoes_id(rs.getInt("situacao_id"));
            s.setDescricao(rs.getString("descricao"));
            return s;
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao mapear entidade: {0}", ex.getMessage());
            return null;
        }
    }
    
    @Override
    public List<Situacoes> listar() {
        String sql = "SELECT * FROM SITUACOES";
        List<Situacoes> retorno = new ArrayList<>();

        try {
            stmt = conexao.prepareStatement(sql);
            logger.info(sql);
            rs = stmt.executeQuery();
            while (rs.next()) {
                Situacoes s = mapearParaEntidade(rs);
                retorno.add(s);
            }
            stmt.close();
            rs.close();
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao executar consulta: {0}", ex.getMessage());
        }

        return retorno;
    }
    
    @Override
    public boolean inserir(Situacoes s) {
        String sql = "INSERT INTO SITUACOES(descricao) VALUES(?)";
        try {
            stmt = conexao.prepareStatement(sql);
            stmt.setString(1, s.getDescricao());
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
        String sql = "DELETE FROM SITUACOES WHERE situacao_id=?";
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
    public boolean alterar(Situacoes s) {
        String sql = "UPDATE SITUACOES SET descricao=? WHERE situacao_id=?";
        try {
            stmt = conexao.prepareStatement(sql);
            stmt.setString(1, s.getDescricao());
            stmt.setInt(2, s.getSituacoes_id());
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
    public Situacoes buscarPorCodigo(int id) {
        String sql = "SELECT * FROM SITUACOES WHERE situacao_id=?";
        Situacoes s = new Situacoes();
        try {
            stmt = conexao.prepareStatement(sql);
            stmt.setInt(1, id);
            rs = stmt.executeQuery();
            while (rs.next()) {
                s = mapearParaEntidade(rs);
            }
            return s;
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao executar consulta: {0}", ex.getMessage());
            return s;
        } finally {
            try {
                stmt.close();
            } catch (SQLException ex) {
                logger.log(Level.SEVERE, "Erro ao fechar conexão: {0}", ex.getMessage());
            }
        }
    }
}

