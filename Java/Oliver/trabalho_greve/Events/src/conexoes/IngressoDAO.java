package conexoes;

import entidades.Ingresso;
import entidades.Evento;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

public class IngressoDAO extends AbstractDAO<Ingresso> {

    private final Connection conexao;
    private Logger logger = Logger.getLogger("IngressoDAO");
    ResultSet rs;
    PreparedStatement stmt;

    public IngressoDAO() {
        conexao = ConexaoDAO.getInstance().getCon();
    }

    @Override
    protected Ingresso mapearParaEntidade(ResultSet rs) {
        try {
            Ingresso i = new Ingresso();
            i.setId(rs.getInt("id"));
            i.setPreco(rs.getDouble("preco"));
            i.setQuantidade(rs.getInt("quantidade"));
            i.setTipo(rs.getString("tipo"));
            
            EventoDAO eventoDAO = new EventoDAO();
            Evento evento = eventoDAO.buscarPorCodigo(rs.getInt("evento_id"));
            i.setEvento(evento);
            
            return i;
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao mapear para entidade: {0}", ex.getMessage());
            return null;
        }
    }

    @Override
    public List<Ingresso> listar() {
        String sql = "SELECT * FROM ingressos";
        List<Ingresso> retorno = new ArrayList<>();

        try {
            stmt = conexao.prepareStatement(sql);
            logger.info(sql);
            rs = stmt.executeQuery();
            while (rs.next()) {
                Ingresso i = mapearParaEntidade(rs);
                retorno.add(i);
            }
            stmt.close();
            rs.close();
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao executar consulta: {0}", ex.getMessage());
        }

        return retorno;
    }

    @Override
    public boolean inserir(Ingresso i) {
        String sql = "INSERT INTO ingressos(preco, quantidade, tipo, evento_id) VALUES(?,?,?,?)";
        try {
            stmt = conexao.prepareStatement(sql, Statement.RETURN_GENERATED_KEYS);
            stmt.setDouble(1, i.getPreco());
            stmt.setInt(2, i.getQuantidade());
            stmt.setString(3, i.getTipo());
            stmt.setInt(4, i.getEvento().getId());
            stmt.executeUpdate();
            rs = stmt.getGeneratedKeys();
            if (rs.next()) {
                i.setId(rs.getInt(1));
            }
            logger.info("Inserção no banco de dados realizada.");
            stmt.close();
            return true;
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao executar consulta: {0}", ex.getMessage());
            return false;
        }
    }

    @Override
    public boolean remover(int id) {
        String sql = "DELETE FROM ingressos WHERE id=?";
        try {
            stmt = conexao.prepareStatement(sql);
            stmt.setInt(1, id);
            stmt.executeUpdate();
            logger.info("Remoção no banco de dados realizada.");
            stmt.close();
            return true;
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao executar consulta: {0}", ex.getMessage());
            return false;
        }
    }

    @Override
    public boolean alterar(Ingresso i) {
        String sql = "UPDATE ingressos SET preco=?, quantidade=?, tipo=?, evento_id=? WHERE id=?";
        try {
            stmt = conexao.prepareStatement(sql);
            stmt.setDouble(1, i.getPreco());
            stmt.setInt(2, i.getQuantidade());
            stmt.setString(3, i.getTipo());
            stmt.setInt(4, i.getEvento().getId());
            stmt.setInt(5, i.getId());
            stmt.executeUpdate();
            logger.info("Alteração no banco de dados realizada.");
            stmt.close();
            return true;
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao executar consulta: {0}", ex.getMessage());
            return false;
        }
    }

    @Override
    public Ingresso buscarPorCodigo(int id) {
        String sql = "SELECT * FROM ingressos WHERE id=?";
        Ingresso i = new Ingresso();
        try {
            stmt = conexao.prepareStatement(sql);
            stmt.setInt(1, id);
            rs = stmt.executeQuery();
            while (rs.next()) {
                i = mapearParaEntidade(rs);
            }
            return i;
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao executar consulta: {0}", ex.getMessage());
            return i;
        } finally {
            try {
                stmt.close();
            } catch (SQLException ex) {
                logger.log(Level.SEVERE, "Erro ao fechar conexão: {0}", ex.getMessage());
            }
        }
    }
}
