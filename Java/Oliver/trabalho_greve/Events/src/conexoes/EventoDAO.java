package conexoes;

import entidades.Evento;
import entidades.Local;
import entidades.Palestrante;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

public class EventoDAO extends AbstractDAO<Evento> {

    private final Connection conexao;
    private Logger logger = Logger.getLogger("EventoDAO");
    ResultSet rs;
    PreparedStatement stmt;

    public EventoDAO() {
        conexao = ConexaoDAO.getInstance().getCon();
    }

    @Override
    protected Evento mapearParaEntidade(ResultSet rs) {
        try {
            Evento e = new Evento();
            e.setId(rs.getInt("id"));
            e.setTitulo(rs.getString("titulo"));
            e.setDescricao(rs.getString("descricao"));
            e.setMaxParticipantes(rs.getInt("max_participantes"));
            e.setDataEvento(rs.getTimestamp("data_evento"));

            Palestrante palestrante = new PalestranteDAO().buscarPorCodigo(rs.getInt("palestrante_id"));
            e.setPalestrante(palestrante);
            
            Local local = new LocalDAO().buscarPorCodigo(rs.getInt("local_id"));
            e.setLocal(local);
            
            return e;
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao mapear para entidade: {0}", ex.getMessage());
            return null;
        }
    }

    @Override
    public List<Evento> listar() {
        String sql = "SELECT * FROM eventos";
        List<Evento> retorno = new ArrayList<>();

        try {
            stmt = conexao.prepareStatement(sql);
            logger.info(sql);
            rs = stmt.executeQuery();
            while (rs.next()) {
                Evento e = mapearParaEntidade(rs);
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
    public boolean inserir(Evento e) {
        String sql = "INSERT INTO eventos(titulo, descricao, max_participantes, data_evento, palestrante_id, local_id) VALUES(?,?,?,?,?,?)";
        try {
            stmt = conexao.prepareStatement(sql, Statement.RETURN_GENERATED_KEYS);
            stmt.setString(1, e.getTitulo());
            stmt.setString(2, e.getDescricao());
            stmt.setInt(3, e.getMaxParticipantes());
            stmt.setTimestamp(4, new Timestamp(e.getDataEvento().getTime()));
            stmt.setInt(5, e.getPalestrante().getId());
            stmt.setInt(6, e.getLocal().getId());
            stmt.executeUpdate();
            rs = stmt.getGeneratedKeys();
            if (rs.next()) {
                e.setId(rs.getInt(1));
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
        String sql = "DELETE FROM eventos WHERE id=?";
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
    public boolean alterar(Evento e) {
        String sql = "UPDATE eventos SET titulo=?, descricao=?, max_participantes=?, data_evento=?, palestrante_id=?, local_id=? WHERE id=?";
        try {
            stmt = conexao.prepareStatement(sql);
            stmt.setString(1, e.getTitulo());
            stmt.setString(2, e.getDescricao());
            stmt.setInt(3, e.getMaxParticipantes());
            stmt.setTimestamp(4, new Timestamp(e.getDataEvento().getTime()));
            stmt.setInt(5, e.getPalestrante().getId());
            stmt.setInt(6, e.getLocal().getId());
            stmt.setInt(7, e.getId());
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
    public Evento buscarPorCodigo(int id) {
        String sql = "SELECT * FROM eventos WHERE id=?";
        Evento e = new Evento();
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
