package conexoes;

import entidades.CheckIn;
import entidades.Ingresso;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

public class CheckInDAO extends AbstractDAO<CheckIn> {

    private final Connection conexao;
    private Logger logger = Logger.getLogger("CheckInDAO");
    ResultSet rs;
    PreparedStatement stmt;

    public CheckInDAO() {
        conexao = ConexaoDAO.getInstance().getCon();
    }

    @Override
    protected CheckIn mapearParaEntidade(ResultSet rs) {
        try {
            CheckIn checkIn = new CheckIn();
            checkIn.setId(rs.getInt("id"));
            checkIn.setDataCheckIn(rs.getTimestamp("data_check_in"));
            
            // Carregar o ingresso
            IngressoDAO ingressoDAO = new IngressoDAO();
            Ingresso ingresso = ingressoDAO.buscarPorCodigo(rs.getInt("ingresso_id"));
            checkIn.setIngresso(ingresso);
            
            return checkIn;
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao mapear para entidade: {0}", ex.getMessage());
            return null;
        }
    }

    @Override
    public List<CheckIn> listar() {
        String sql = "SELECT * FROM check_ins";
        List<CheckIn> retorno = new ArrayList<>();

        try {
            stmt = conexao.prepareStatement(sql);
            logger.info(sql);
            rs = stmt.executeQuery();
            while (rs.next()) {
                CheckIn checkIn = mapearParaEntidade(rs);
                retorno.add(checkIn);
            }
            stmt.close();
            rs.close();
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao executar consulta: {0}", ex.getMessage());
        }

        return retorno;
    }

    @Override
    public boolean inserir(CheckIn checkIn) {
        String sql = "INSERT INTO check_ins(ingresso_id, data_check_in) VALUES(?,?)";
        try {
            stmt = conexao.prepareStatement(sql, Statement.RETURN_GENERATED_KEYS);
            stmt.setInt(1, checkIn.getIngresso().getId());
            stmt.setTimestamp(2, new Timestamp(checkIn.getDataCheckIn().getTime()));
            stmt.executeUpdate();
            rs = stmt.getGeneratedKeys();
            if (rs.next()) {
                checkIn.setId(rs.getInt(1));
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
        String sql = "DELETE FROM check_ins WHERE id=?";
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
    public boolean alterar(CheckIn checkIn) {
        String sql = "UPDATE check_ins SET ingresso_id=?, data_check_in=? WHERE id=?";
        try {
            stmt = conexao.prepareStatement(sql);
            stmt.setInt(1, checkIn.getIngresso().getId());
            stmt.setTimestamp(2, new Timestamp(checkIn.getDataCheckIn().getTime()));
            stmt.setInt(3, checkIn.getId());
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
    public CheckIn buscarPorCodigo(int id) {
        String sql = "SELECT * FROM check_ins WHERE id=?";
        CheckIn checkIn = new CheckIn();
        try {
            stmt = conexao.prepareStatement(sql);
            stmt.setInt(1, id);
            rs = stmt.executeQuery();
            while (rs.next()) {
                checkIn = mapearParaEntidade(rs);
            }
            return checkIn;
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao executar consulta: {0}", ex.getMessage());
            return checkIn;
        } finally {
            try {
                stmt.close();
            } catch (SQLException ex) {
                logger.log(Level.SEVERE, "Erro ao fechar conexão: {0}", ex.getMessage());
            }
        }
    }
}
