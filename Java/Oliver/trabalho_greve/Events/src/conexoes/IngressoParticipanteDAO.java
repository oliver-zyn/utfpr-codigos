package conexoes;

import entidades.IngressoParticipante;
import entidades.Participante;
import entidades.Ingresso;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

public class IngressoParticipanteDAO extends AbstractDAO<IngressoParticipante> {

    private final Connection conexao;
    private Logger logger = Logger.getLogger("IngressoParticipanteDAO");
    ResultSet rs;
    PreparedStatement stmt;

    public IngressoParticipanteDAO() {
        conexao = ConexaoDAO.getInstance().getCon();
    }

    @Override
    protected IngressoParticipante mapearParaEntidade(ResultSet rs) {
        try {
            IngressoParticipante ip = new IngressoParticipante();
            ip.setId(rs.getInt("id"));
            
            // Carregar o participante
            Participante participante = new ParticipanteDAO().buscarPorCodigo(rs.getInt("participante_id"));
            ip.setParticipante(participante);
            
            // Carregar o ingresso
            Ingresso ingresso = new IngressoDAO().buscarPorCodigo(rs.getInt("ingresso_id"));
            ip.setIngresso(ingresso);
            
            return ip;
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao mapear para entidade: {0}", ex.getMessage());
            return null;
        }
    }

    @Override
    public List<IngressoParticipante> listar() {
        String sql = "SELECT * FROM ingressos_participantes";
        List<IngressoParticipante> retorno = new ArrayList<>();

        try {
            stmt = conexao.prepareStatement(sql);
            logger.info(sql);
            rs = stmt.executeQuery();
            while (rs.next()) {
                IngressoParticipante ip = mapearParaEntidade(rs);
                retorno.add(ip);
            }
            stmt.close();
            rs.close();
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao executar consulta: {0}", ex.getMessage());
        }

        return retorno;
    }

    @Override
    public boolean inserir(IngressoParticipante ip) {
        String sql = "INSERT INTO ingressos_participantes(participante_id, ingresso_id) VALUES(?,?)";
        try {
            stmt = conexao.prepareStatement(sql, Statement.RETURN_GENERATED_KEYS);
            stmt.setInt(1, ip.getParticipante().getId());
            stmt.setInt(2, ip.getIngresso().getId());
            stmt.executeUpdate();
            rs = stmt.getGeneratedKeys();
            if (rs.next()) {
                ip.setId(rs.getInt(1));
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
        String sql = "DELETE FROM ingressos_participantes WHERE id=?";
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
    public boolean alterar(IngressoParticipante ip) {
        String sql = "UPDATE ingressos_participantes SET participante_id=?, ingresso_id=? WHERE id=?";
        try {
            stmt = conexao.prepareStatement(sql);
            stmt.setInt(1, ip.getParticipante().getId());
            stmt.setInt(2, ip.getIngresso().getId());
            stmt.setInt(3, ip.getId());
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
    public IngressoParticipante buscarPorCodigo(int id) {
        String sql = "SELECT * FROM ingressos_participantes WHERE id=?";
        IngressoParticipante ip = new IngressoParticipante();
        try {
            stmt = conexao.prepareStatement(sql);
            stmt.setInt(1, id);
            rs = stmt.executeQuery();
            while (rs.next()) {
                ip = mapearParaEntidade(rs);
            }
            return ip;
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao executar consulta: {0}", ex.getMessage());
            return ip;
        } finally {
            try {
                stmt.close();
            } catch (SQLException ex) {
                logger.log(Level.SEVERE, "Erro ao fechar conexão: {0}", ex.getMessage());
            }
        }
    }
}
