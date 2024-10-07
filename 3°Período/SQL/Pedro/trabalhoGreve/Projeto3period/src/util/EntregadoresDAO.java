package util;

import entidades.Entregadores;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

public class EntregadoresDAO extends AbstractDAO<Entregadores> {
    
    private final Connection conexao;
    private Logger logger = Logger.getLogger("EntregadorDAO");
    ResultSet rs;
    PreparedStatement stmt;
    
    public EntregadoresDAO() {
        conexao = ConexaoDAO.getInstance().getCon();
    }
    
    @Override
    protected Entregadores mapearParaEntidade(ResultSet rs) {
        try {
            Entregadores e = new Entregadores();
            e.setEntregador_id(rs.getInt("entregador_id"));
            e.setUsuario_id(rs.getInt("usuario_id"));
            e.setCPF(rs.getString("cpf"));
            e.setNome(rs.getString("nome"));
            e.setTelefone(rs.getString("telefone"));
            return e;
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao mapear entidade: {0}", ex.getMessage());
            return null;
        }
    }
    
    @Override
    public List<Entregadores> listar() {
        String sql = "SELECT * FROM ENTREGADORES";
        List<Entregadores> retorno = new ArrayList<>();

        try {
            stmt = conexao.prepareStatement(sql);
            logger.info(sql);
            rs = stmt.executeQuery();
            while (rs.next()) {
                Entregadores e = mapearParaEntidade(rs);
                retorno.add(e);
            }
            stmt.close();
            rs.close();
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao executar consulta: {0}", ex.getMessage());
        }

        return retorno;
    }
    
    @Override
    public boolean inserir(Entregadores e) {
        String sql = "INSERT INTO ENTREGADORES(usuario_id, cpf, nome, telefone) VALUES(?,?,?,?)";
        try {
            stmt = conexao.prepareStatement(sql);
            stmt.setInt(1, e.getUsuario_id());
            stmt.setString(2, e.getCPF());
            stmt.setString(3, e.getNome());
            stmt.setString(4, e.getTelefone());
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
        String sql = "DELETE FROM ENTREGADORES WHERE entregador_id=?";
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
    public boolean alterar(Entregadores e) {
        String sql = "UPDATE ENTREGADORES SET usuario_id=?, cpf=?, nome=?, telefone=? WHERE entregador_id=?";
        try {
            stmt = conexao.prepareStatement(sql);
            stmt.setInt(1, e.getUsuario_id());
            stmt.setString(2, e.getCPF());
            stmt.setString(3, e.getNome());
            stmt.setString(4, e.getTelefone());
            stmt.setInt(5, e.getEntregador_id());
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
    public Entregadores buscarPorCodigo(int id) {
        String sql = "SELECT * FROM ENTREGADORES WHERE entregador_id=?";
        Entregadores e = new Entregadores();
        try {
            stmt = conexao.prepareStatement(sql);
            stmt.setInt(1, id);
            rs = stmt.executeQuery();
            while (rs.next()) {
                e = mapearParaEntidade(rs);
            }
            return e;
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao executar consulta: {0}", ex.getMessage());
            return e;
        } finally {
            try {
                stmt.close();
            } catch (SQLException ex) {
                logger.log(Level.SEVERE, "Erro ao fechar conexão: {0}", ex.getMessage());
            }
        }
    }
}

