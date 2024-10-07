package util;

import entidades.Pacotes_Situacoes;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Pacotes_SituacoesDAO extends AbstractDAO<Pacotes_Situacoes> {
    
    private final Connection conexao;
    private Logger logger = Logger.getLogger("PacoteSituacaoDAO");
    ResultSet rs;
    PreparedStatement stmt;
    
    public Pacotes_SituacoesDAO() {
        conexao = ConexaoDAO.getInstance().getCon();
    }
    
    @Override
    protected Pacotes_Situacoes mapearParaEntidade(ResultSet rs) {
        try {
            Pacotes_Situacoes ps = new Pacotes_Situacoes();
            ps.setPacote_situacoes_id(rs.getInt("pacote_situacao_id"));
            ps.setPacote_id(rs.getInt("pacote_id"));
            ps.setSituacao_anterior_id(rs.getInt("situacao_anterior_id"));
            ps.setSituacao_atual_id(rs.getInt("situacao_atual_id"));
            ps.setData_alteracao(rs.getTimestamp("data_alteracao"));
            return ps;
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao mapear entidade: {0}", ex.getMessage());
            return null;
        }
    }
    
    @Override
    public List<Pacotes_Situacoes> listar() {
        String sql = "SELECT * FROM PACOTES_SITUACOES";
        List<Pacotes_Situacoes> retorno = new ArrayList<>();

        try {
            stmt = conexao.prepareStatement(sql);
            logger.info(sql);
            rs = stmt.executeQuery();
            while (rs.next()) {
                Pacotes_Situacoes ps = mapearParaEntidade(rs);
                retorno.add(ps);
            }
            stmt.close();
            rs.close();
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao executar consulta: {0}", ex.getMessage());
        }

        return retorno;
    }
    
    @Override
    public boolean inserir(Pacotes_Situacoes ps) {
        String sql = "INSERT INTO PACOTES_SITUACOES(pacote_id, situacao_anterior_id, situacao_atual_id, data_alteracao) VALUES(?,?,?,?)";
        try {
            stmt = conexao.prepareStatement(sql);
            stmt.setInt(1, ps.getPacote_id());
            stmt.setInt(2, ps.getSituacao_anterior_id());
            stmt.setInt(3, ps.getSituacao_atual_id());
            stmt.setTimestamp(4, new Timestamp(ps.getData_alteracao().getTime()));
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
        String sql = "DELETE FROM PACOTES_SITUACOES WHERE pacote_situacao_id=?";
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
    public boolean alterar(Pacotes_Situacoes ps) {
        String sql = "UPDATE PACOTES_SITUACOES SET pacote_id=?, situacao_anterior_id=?, situacao_atual_id=?, data_alteracao=? WHERE pacote_situacao_id=?";
        try {
            stmt = conexao.prepareStatement(sql);
            stmt.setInt(1, ps.getPacote_id());
            stmt.setInt(2, ps.getSituacao_anterior_id());
            stmt.setInt(3, ps.getSituacao_atual_id());
            stmt.setTimestamp(4, new Timestamp(ps.getData_alteracao().getTime()));
            stmt.setInt(5, ps.getPacote_situacoes_id());
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
    public Pacotes_Situacoes buscarPorCodigo(int id) {
        String sql = "SELECT * FROM PACOTES_SITUACOES WHERE pacote_situacao_id=?";
        Pacotes_Situacoes ps = new Pacotes_Situacoes();
        try {
            stmt = conexao.prepareStatement(sql);
            stmt.setInt(1, id);
            rs = stmt.executeQuery();
            while (rs.next()) {
                ps = mapearParaEntidade(rs);
            }
            return ps;
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao executar consulta: {0}", ex.getMessage());
            return ps;
        } finally {
            try {
                stmt.close();
            } catch (SQLException ex) {
                logger.log(Level.SEVERE, "Erro ao fechar conexão: {0}", ex.getMessage());
            }
        }
    }
}

