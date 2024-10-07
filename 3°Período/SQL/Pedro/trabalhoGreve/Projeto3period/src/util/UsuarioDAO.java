/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package util;

import entidades.Usuario;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

public class UsuarioDAO extends AbstractDAO<Usuario> {
    
    private final Connection conexao;
    private Logger logger = Logger.getLogger("UsuarioDao");
    ResultSet rs;
    PreparedStatement stmt;
    
    public UsuarioDAO() {
        conexao = ConexaoDAO.getInstance().getCon();
    }
    
    @Override
    protected Usuario mapearParaEntidade(ResultSet rs) {
        try {
            Usuario u = new Usuario();
            u.setUsuario_id(rs.getInt("usuario_id"));
            u.setCPF(rs.getString("CPF"));
            u.setSenha(rs.getString("senha"));
            u.setUsuario_admin(rs.getInt("usuario_admin"));
            return u;
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao executar consulta: {0}", ex.getMessage());
            return null;
        }
    }
    
    @Override
    public List<Usuario> listar() {
        String sql = "SELECT * FROM USUARIOS";
        List<Usuario> retorno = new ArrayList<>();

        try {
            stmt = conexao.prepareStatement(sql);
            logger.info(sql);
            rs = stmt.executeQuery();
            while (rs.next()) {
                Usuario u = mapearParaEntidade(rs);
                retorno.add(u);
            }
            stmt.close();
            rs.close();
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao executar consulta: {0}", ex.getMessage());
        }

        return retorno;
    }
    
    @Override
    public boolean inserir(Usuario u) {
        String sql = "INSERT INTO USUARIOS(cpf, senha, usuario_admin) VALUES(?,?,?)";
        try {
            stmt = conexao.prepareStatement(sql);
            stmt.setString(1, u.getCPF());
            stmt.setString(2, u.getSenha());
            stmt.setInt(3, u.getUsuario_admin());
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
        String sql = "DELETE FROM USUARIOS WHERE usuario_id=?";
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
    public boolean alterar(Usuario u) {
        String sql = "UPDATE USUARIOS SET cpf=?, senha=?, usuario_admin=? WHERE usuario_id=?";
        try {
            stmt = conexao.prepareStatement(sql);
            stmt.setString(1, u.getCPF());
            stmt.setString(2, u.getSenha());
            stmt.setInt(3, u.getUsuario_admin());
            stmt.setInt(4, u.getUsuario_id());           
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
    public Usuario buscarPorCodigo(int id) {
        String sql = "SELECT * FROM USUARIOS WHERE usuario_id=?";
        Usuario u = new Usuario();
        try {
            stmt = conexao.prepareStatement(sql);
            stmt.setInt(1, id);
            rs = stmt.executeQuery();
            while (rs.next()) {
                u = mapearParaEntidade(rs);
            }
            return u;
        } catch (SQLException ex) {
            logger.log(Level.SEVERE, "Erro ao executar consulta: {0}", ex.getMessage());
            return u;
        } finally {
            try {
                stmt.close();
            } catch (SQLException ex) {
                logger.log(Level.SEVERE, "Erro ao fechar conex\u00e3o{0}", ex.getMessage());
            }
        }
    }
}
