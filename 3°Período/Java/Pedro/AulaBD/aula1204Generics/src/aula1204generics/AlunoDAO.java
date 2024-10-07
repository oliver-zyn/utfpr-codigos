/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package aula1204generics;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

public class AlunoDAO extends AbstractDAO<Aluno> {

    private final Connection conexao;
    private Logger logger = Logger.getLogger("ProdutoDao");
    ResultSet rs;
    PreparedStatement stmt;

    public AlunoDAO() {
        conexao = ConexaoDAO.getInstance().getCon();
    }

    @Override
    protected Aluno mapearParaEntidade(ResultSet rs) {
        try {
            Aluno a = new Aluno();
            a.setMatricula(rs.getInt("matricula"));
            a.setCpf(rs.getString("cpf"));
            a.setNome(rs.getString("nome"));
            a.setSexo(rs.getString("sexo").charAt(0));
            a.setProfissao(rs.getInt("profissao"));
            return a;
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao executar consulta: {0}", ex.getMessage());
            return null;
        }
    }

    @Override
    public List<Aluno> listar() {
        String sql = "SELECT * FROM aluno";
        List<Aluno> retorno = new ArrayList<>();

        try {
            stmt = conexao.prepareStatement(sql);
            logger.info(sql);
            rs = stmt.executeQuery();
            while (rs.next()) {
                Aluno a = mapearParaEntidade(rs);
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
    public boolean inserir(Aluno a) {
        String sql = "INSERT INTO aluno(matricula, cpf, nome, sexo, profissao) VALUES(?,?,?,?,?)";
        try {
            stmt = conexao.prepareStatement(sql);
            stmt.setInt(1, a.getMatricula());
            stmt.setString(2, a.getCpf());
            stmt.setString(3, a.getNome());
            stmt.setString(4, Character.toString(a.getSexo()));
            stmt.setInt(5, a.getProfissao());
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
        String sql = "DELETE FROM aluno WHERE matricula=?";
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
    public boolean alterar(Aluno a) {
        String sql = "UPDATE aluno SET cpf=?, nome=?, sexo=?, profissao=? WHERE matricula=?";
        try {
            stmt = conexao.prepareStatement(sql);
            stmt.setString(1, a.getCpf());
            stmt.setString(2, a.getNome());
            stmt.setString(3, Character.toString(a.getSexo()));
            stmt.setInt(4, a.getProfissao());
            stmt.setInt(5, a.getMatricula());            
            stmt.execute();
            logger.info("Alteracao no banco de dados realizada!.");
            stmt.close();
            return true;
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao executar consulta: {0}", ex.getMessage());
            return false;
        }
    }

    @Override
    public Aluno buscarPorCodigo(int id) {
        String sql = "SELECT * FROM aluno WHERE matricula=?";
        Aluno a = new Aluno();
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
