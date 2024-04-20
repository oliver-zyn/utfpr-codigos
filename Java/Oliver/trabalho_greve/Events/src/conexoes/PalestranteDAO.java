package conexoes;

import entidades.Palestrante;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

public class PalestranteDAO extends AbstractDAO<Palestrante> {

    private final Connection conexao;
    private Logger logger = Logger.getLogger("PalestranteDAO");
    ResultSet rs;
    PreparedStatement stmt;

    public PalestranteDAO() {
        conexao = ConexaoDAO.getInstance().getCon();
    }

    @Override
    protected Palestrante mapearParaEntidade(ResultSet rs) {
        try {
            Palestrante p = new Palestrante();
            p.setId(rs.getInt("id"));
            p.setNome(rs.getString("nome"));
            p.setDescricao(rs.getString("descricao"));
            p.setAreaAtuacao(rs.getString("area_atuacao"));
            return p;
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao mapear para entidade: {0}", ex.getMessage());
            return null;
        }
    }

    @Override
    public List<Palestrante> listar() {
        String sql = "SELECT * FROM palestrantes";
        List<Palestrante> retorno = new ArrayList<>();

        try {
            stmt = conexao.prepareStatement(sql);
            logger.info(sql);
            rs = stmt.executeQuery();
            while (rs.next()) {
                Palestrante p = mapearParaEntidade(rs);
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
    public boolean inserir(Palestrante p) {
        String sql = "INSERT INTO palestrantes(nome, descricao, area_atuacao) VALUES(?,?,?)";
        try {
            stmt = conexao.prepareStatement(sql, Statement.RETURN_GENERATED_KEYS);
            stmt.setString(1, p.getNome());
            stmt.setString(2, p.getDescricao());
            stmt.setString(3, p.getAreaAtuacao());
            stmt.executeUpdate();
            rs = stmt.getGeneratedKeys();
            if (rs.next()) {
                p.setId(rs.getInt(1));
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
        String sql = "DELETE FROM palestrantes WHERE id=?";
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
    public boolean alterar(Palestrante p) {
        String sql = "UPDATE palestrantes SET nome=?, descricao=?, area_atuacao=? WHERE id=?";
        try {
            stmt = conexao.prepareStatement(sql);
            stmt.setString(1, p.getNome());
            stmt.setString(2, p.getDescricao());
            stmt.setString(3, p.getAreaAtuacao());
            stmt.setInt(4, p.getId());
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
    public Palestrante buscarPorCodigo(int id) {
        String sql = "SELECT * FROM palestrantes WHERE id=?";
        Palestrante p = new Palestrante();
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
