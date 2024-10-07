package conexoes;

import entidades.Participante;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

public class ParticipanteDAO extends AbstractDAO<Participante> {

    private final Connection conexao;
    private Logger logger = Logger.getLogger("ParticipanteDAO");
    ResultSet rs;
    PreparedStatement stmt;

    public ParticipanteDAO() {
        conexao = ConexaoDAO.getInstance().getCon();
    }

    @Override
    protected Participante mapearParaEntidade(ResultSet rs) {
        try {
            Participante p = new Participante();
            p.setId(rs.getInt("id"));
            p.setNome(rs.getString("nome"));
            p.setEmail(rs.getString("email"));
            p.setCpf(rs.getString("cpf"));
            p.setTelefone(rs.getString("telefone"));
            return p;
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao executar consulta: {0}", ex.getMessage());
            return null;
        }
    }

    @Override
    public List<Participante> listar() {
        String sql = "SELECT * FROM participantes";
        List<Participante> retorno = new ArrayList<>();

        try {
            stmt = conexao.prepareStatement(sql);
            logger.info(sql);
            rs = stmt.executeQuery();
            while (rs.next()) {
                Participante a = mapearParaEntidade(rs);
                retorno.add(a);
            }
            stmt.close();
            rs.close();
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao executar consulta: {0}", ex.getMessage());
        }

        return retorno;
    }

    @Override
    public boolean inserir(Participante a) {
        String sql = "INSERT INTO participantes(nome, email, "
                + "cpf, telefone) VALUES(?,?,?,?)";
        try {
            stmt = conexao.prepareStatement(sql);
            stmt.setString(1, a.getNome());
            stmt.setString(2, a.getEmail());
            stmt.setString(3, a.getCpf());
            stmt.setString(4, a.getTelefone());
            stmt.execute();
            logger.info("Insercao no banco de dados realizada!.");
            stmt.close();
            return true;
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao executar consulta: {0}", ex.getMessage());
            return false;
        }
    }

    @Override
    public boolean remover(int id) {
        String sql = "DELETE FROM participantes WHERE id=?";
        try {
            stmt = conexao.prepareStatement(sql);
            stmt.setInt(1, id);
            stmt.execute();
            logger.info("Deleção no banco de dados realizada!.");
            stmt.close();
            return true;
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao executar consulta: {0}", ex.getMessage());
            return false;
        }
    }

    @Override
    public boolean alterar(Participante a) {
        String sql = "UPDATE participantes SET nome=?, email=?, cpf=?, telefone=? WHERE id=?";
        try {
            stmt = conexao.prepareStatement(sql);
            stmt.setString(1, a.getNome());
            stmt.setString(2, a.getEmail());
            stmt.setString(3, a.getCpf());
            stmt.setString(4, a.getTelefone());
            stmt.setInt(5, a.getId());
            stmt.execute();
            logger.info(stmt.toString());
            logger.info("Alteracao no banco de dados realizada!.");
            stmt.close();
            return true;
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao executar consulta: {0}", ex.getMessage());
            return false;
        }
    }

    @Override
    public Participante buscarPorCodigo(int id) {
        String sql = "SELECT * FROM participantes WHERE matricula=?";
        Participante a = new Participante();
        try {
            stmt = conexao.prepareStatement(sql);
            stmt.setInt(1, id);
            rs = stmt.executeQuery();
            while (rs.next()) {
                a = mapearParaEntidade(rs);
            }
            return a;
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao executar consulta: {0}", ex.getMessage());
            return a;
        } finally {
            try {
                stmt.close();
            } catch (SQLException ex) {
                logger.log(Level.SEVERE, "Erro ao fechar conex\u00e3o{0}", ex.getMessage());
            }
        }
    }

}
