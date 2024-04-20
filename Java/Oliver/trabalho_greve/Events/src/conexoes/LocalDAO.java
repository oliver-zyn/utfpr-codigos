package conexoes;

import entidades.Local;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

public class LocalDAO extends AbstractDAO<Local> {

    private final Connection conexao;
    private Logger logger = Logger.getLogger("LocalDAO");
    ResultSet rs;
    PreparedStatement stmt;

    public LocalDAO() {
        conexao = ConexaoDAO.getInstance().getCon();
    }

    @Override
    protected Local mapearParaEntidade(ResultSet rs) {
        try {
            Local l = new Local();
            l.setId(rs.getInt("id"));
            l.setNome(rs.getString("nome"));
            l.setEndereco(rs.getString("endereco"));
            l.setCidade(rs.getString("cidade"));
            l.setCapacidade(rs.getInt("capacidade"));
            return l;
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao mapear para entidade: {0}", ex.getMessage());
            return null;
        }
    }

    @Override
    public List<Local> listar() {
        String sql = "SELECT * FROM locais";
        List<Local> retorno = new ArrayList<>();

        try {
            stmt = conexao.prepareStatement(sql);
            logger.info(sql);
            rs = stmt.executeQuery();
            while (rs.next()) {
                Local l = mapearParaEntidade(rs);
                retorno.add(l);
            }
            stmt.close();
            rs.close();
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao executar consulta: {0}", ex.getMessage());
        }

        return retorno;
    }

    @Override
    public boolean inserir(Local l) {
        String sql = "INSERT INTO locais(nome, endereco, cidade, capacidade) VALUES(?,?,?,?)";
        try {
            stmt = conexao.prepareStatement(sql, Statement.RETURN_GENERATED_KEYS);
            stmt.setString(1, l.getNome());
            stmt.setString(2, l.getEndereco());
            stmt.setString(3, l.getCidade());
            stmt.setInt(4, l.getCapacidade());
            stmt.executeUpdate();
            rs = stmt.getGeneratedKeys();
            if (rs.next()) {
                l.setId(rs.getInt(1));
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
        String sql = "DELETE FROM locais WHERE id=?";
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
    public boolean alterar(Local l) {
        String sql = "UPDATE locais SET nome=?, endereco=?, cidade=?, capacidade=? WHERE id=?";
        try {
            stmt = conexao.prepareStatement(sql);
            stmt.setString(1, l.getNome());
            stmt.setString(2, l.getEndereco());
            stmt.setString(3, l.getCidade());
            stmt.setInt(4, l.getCapacidade());
            stmt.setInt(5, l.getId());
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
    public Local buscarPorCodigo(int id) {
        String sql = "SELECT * FROM locais WHERE id=?";
        Local l = new Local();
        try {
            stmt = conexao.prepareStatement(sql);
            stmt.setInt(1, id);
            rs = stmt.executeQuery();
            while (rs.next()) {
                l = mapearParaEntidade(rs);
            }
            return l;
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao executar consulta: {0}", ex.getMessage());
            return l;
        } finally {
            try {
                stmt.close();
            } catch (SQLException ex) {
                logger.log(Level.SEVERE, "Erro ao fechar conexão: {0}", ex.getMessage());
            }
        }
    }
}
