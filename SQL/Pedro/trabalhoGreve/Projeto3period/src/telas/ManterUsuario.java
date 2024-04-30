/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package telas;

import entidades.Usuario;
import java.util.ArrayList;
import java.util.List;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import util.UsuarioDAO;

/**
 *
 * @author Geri
 */
public class ManterUsuario extends javax.swing.JDialog {

    UsuarioDAO con = new UsuarioDAO(); 
    List<Usuario> usuario = new ArrayList();
    Usuario usuarioAux;
    
    boolean novo = false;
    int i = -1;
    
    public ManterUsuario(java.awt.Frame parent,
            boolean modal) {
        super(parent, modal);
        initComponents();
        // informa como devem estar os bot?es no in?cio do processo
        ativaInicio();
        usuario = con.listar();
        if (!usuario.isEmpty()) {
            i = 0;
            carregaDados();
            ativaNavegacao();
        }
    }
    
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        buttonGroup1 = new javax.swing.ButtonGroup();
        buttonGroup2 = new javax.swing.ButtonGroup();
        jPanel1 = new javax.swing.JPanel();
        jLabel1 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        tfCPF = new javax.swing.JTextField();
        cbAdmin = new javax.swing.JCheckBox();
        tfSenha = new javax.swing.JTextField();
        jPanel2 = new javax.swing.JPanel();
        btPrimeiro = new javax.swing.JButton();
        btAnterior = new javax.swing.JButton();
        btProximo = new javax.swing.JButton();
        btUltimo = new javax.swing.JButton();
        btExcluir = new javax.swing.JButton();
        btNovo = new javax.swing.JButton();
        btSalvar = new javax.swing.JButton();
        btSair = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);
        setTitle("Cadastro de Usuário\n");

        jPanel1.setBorder(javax.swing.BorderFactory.createTitledBorder(javax.swing.BorderFactory.createEtchedBorder()));

        jLabel1.setText("CPF:");

        jLabel2.setText("Senha:");

        jLabel3.setText("Admin:");

        tfCPF.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                tfCPFActionPerformed(evt);
            }
        });

        cbAdmin.setText("Sim");
        cbAdmin.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                cbAdminActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGap(6, 6, 6)
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addComponent(jLabel2)
                            .addComponent(jLabel1))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(tfCPF)
                            .addComponent(tfSenha, javax.swing.GroupLayout.DEFAULT_SIZE, 140, Short.MAX_VALUE)))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addComponent(jLabel3)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(cbAdmin, javax.swing.GroupLayout.PREFERRED_SIZE, 85, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGap(13, 13, 13)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(tfCPF, javax.swing.GroupLayout.PREFERRED_SIZE, 20, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel1))
                .addGap(12, 12, 12)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel2)
                    .addComponent(tfSenha, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel3)
                    .addComponent(cbAdmin))
                .addContainerGap(7, Short.MAX_VALUE))
        );

        jPanel2.setLayout(new java.awt.GridLayout(2, 4));

        btPrimeiro.setIcon(new javax.swing.ImageIcon(getClass().getResource("/icons/resultset_first.png"))); // NOI18N
        btPrimeiro.setToolTipText("Primeiro registro");
        btPrimeiro.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btPrimeiroActionPerformed(evt);
            }
        });
        jPanel2.add(btPrimeiro);

        btAnterior.setIcon(new javax.swing.ImageIcon(getClass().getResource("/icons/resultset_previous.png"))); // NOI18N
        btAnterior.setToolTipText("Registro anterior");
        btAnterior.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btAnteriorActionPerformed(evt);
            }
        });
        jPanel2.add(btAnterior);

        btProximo.setIcon(new javax.swing.ImageIcon(getClass().getResource("/icons/resultset_next.png"))); // NOI18N
        btProximo.setToolTipText("Próximo registro");
        btProximo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btProximoActionPerformed(evt);
            }
        });
        jPanel2.add(btProximo);

        btUltimo.setIcon(new javax.swing.ImageIcon(getClass().getResource("/icons/resultset_last.png"))); // NOI18N
        btUltimo.setToolTipText("Último registro");
        btUltimo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btUltimoActionPerformed(evt);
            }
        });
        jPanel2.add(btUltimo);

        btExcluir.setIcon(new javax.swing.ImageIcon(getClass().getResource("/icons/brick_delete.png"))); // NOI18N
        btExcluir.setToolTipText("Excluir registro");
        btExcluir.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btExcluirActionPerformed(evt);
            }
        });
        jPanel2.add(btExcluir);

        btNovo.setIcon(new javax.swing.ImageIcon(getClass().getResource("/icons/brick_add.png"))); // NOI18N
        btNovo.setToolTipText("Novo registro");
        btNovo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btNovoActionPerformed(evt);
            }
        });
        jPanel2.add(btNovo);

        btSalvar.setIcon(new javax.swing.ImageIcon(getClass().getResource("/icons/brick_go.png"))); // NOI18N
        btSalvar.setToolTipText("Salvar registro");
        btSalvar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btSalvarActionPerformed(evt);
            }
        });
        jPanel2.add(btSalvar);

        btSair.setIcon(new javax.swing.ImageIcon(getClass().getResource("/icons/door_in.png"))); // NOI18N
        btSair.setToolTipText("Sair do Sistema");
        btSair.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btSairActionPerformed(evt);
            }
        });
        jPanel2.add(btSair);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(jPanel2, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, 390, Short.MAX_VALUE)
                    .addComponent(jPanel1, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(0, 0, Short.MAX_VALUE)
                .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jPanel2, javax.swing.GroupLayout.DEFAULT_SIZE, 180, Short.MAX_VALUE)
                .addContainerGap())
        );

        setSize(new java.awt.Dimension(416, 320));
        setLocationRelativeTo(null);
    }// </editor-fold>//GEN-END:initComponents

    private void btSairActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btSairActionPerformed
        // TODO add your handling code here:
        // Fecha o JDialog
        dispose();
    }//GEN-LAST:event_btSairActionPerformed

    private void btSalvarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btSalvarActionPerformed

        String cpf = tfCPF.getText();
        String senha = tfSenha.getText();
        int admin = cbAdmin.isSelected()?1:0;
        
        usuarioAux = new Usuario(cpf, senha, admin);
        
        if (novo) {
            con.inserir(usuarioAux);
            usuario.add(usuarioAux);
            i = usuario.size() - 1;
        } else {
            con.alterar(usuarioAux);
            usuario.set(i, usuarioAux);
        }
        novo = false;
        ativaNavegacao();
    }//GEN-LAST:event_btSalvarActionPerformed

    private void btNovoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btNovoActionPerformed
        // TODO add your handling code here:
        limpaCampos();
        novo = true;
        ativaEdicao();
        // manda o curso ficar no campo c?digo
        tfCPF.requestFocus();
    }//GEN-LAST:event_btNovoActionPerformed

    private void btPrimeiroActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btPrimeiroActionPerformed
        // TODO add your handling code here:
        // testa se j? h? registros inclu?dos
        if ((!usuario.isEmpty()) && (i > 0)) {
            i = 0; // vai para o primeiro registro
            carregaDados();
        } else {
            JOptionPane.showMessageDialog(this, "Ja esta no primeiro registro");
        }
    }//GEN-LAST:event_btPrimeiroActionPerformed

    private void btAnteriorActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btAnteriorActionPerformed
        // TODO add your handling code here:
        // testa se tem registros e se ainda n?o est? no primeiro registro
        if ((!usuario.isEmpty()) && (i > 0)) {
            i--; // vai para o registro anterior
            carregaDados();
        } else {
            JOptionPane.showMessageDialog(this, "Ja esta no primeiro registro");
        }
    }//GEN-LAST:event_btAnteriorActionPerformed

    private void btProximoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btProximoActionPerformed
        // TODO add your handling code here:
        // testa se tem registros e se n?o est? no ?ltimo registro
        if ((!usuario.isEmpty()) && (i < usuario.size() - 1)) {
            i++; // vai para o pr?ximo registro
            carregaDados();
        } else {
            JOptionPane.showMessageDialog(this, "Ja esta no ultimo registro");
        }
    }//GEN-LAST:event_btProximoActionPerformed

    private void btUltimoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btUltimoActionPerformed
        // TODO add your handling code here:
        if ((!usuario.isEmpty()) && (i < usuario.size() - 1)) {
            i = usuario.size() - 1; // vai para o ?ltimo registro
            carregaDados();
        } else {
            JOptionPane.showMessageDialog(this, "Ja esta no ultimo registro");
        }
    }//GEN-LAST:event_btUltimoActionPerformed

    private void btExcluirActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btExcluirActionPerformed
        // TODO add your handling code here:
        // testa se h? registros
        if (i >= 0) {
            
            con.remover(usuario.get(i).getUsuario_id());
            usuario.remove(i);
            // testa se ainda h? registros
            if (!usuario.isEmpty()) {
                // volta para o primeiro registro
                i = 0;
                // carrega os dados do primeiro registro
                carregaDados();
            } else {
                JOptionPane.showMessageDialog(this, "Nao ha mais registros");
                // limpa os dados da tela
                limpaCampos();
                // ativa o formato de bot?es de in?cio
                ativaInicio();
            }
        }
    }//GEN-LAST:event_btExcluirActionPerformed

    private void cbAdminActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_cbAdminActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_cbAdminActionPerformed

    private void tfCPFActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_tfCPFActionPerformed
        
    }//GEN-LAST:event_tfCPFActionPerformed

    // m?todo para carregar os dados do vetor din?mico para a tela
    private void carregaDados() {
        // os dados ser?o carregados da posi??o corrente, ou seja, do valor
        // armazenado em i
        usuarioAux = usuario.get(i); // recupera o cliente armazenado em i
        tfCPF.setText(usuarioAux.getCPF()+ "");
        tfSenha.setText(usuarioAux.getSenha());
        cbAdmin.setSelected(usuarioAux.getUsuario_admin() == 1);
    }

    // m?todo para ativar apenas os bot?es que podem ser utilizados quando um
    // novo registro est? sendo editado
    public void ativaEdicao() {
        btPrimeiro.setEnabled(false);
        btAnterior.setEnabled(false);
        btProximo.setEnabled(false);
        btUltimo.setEnabled(false);
        btExcluir.setEnabled(false);
        btNovo.setEnabled(false);
        btSalvar.setEnabled(true);
    }
    // m?todo para ativar os bot?es para navega??o novamente

    public void ativaNavegacao() {
        btPrimeiro.setEnabled(true);
        btAnterior.setEnabled(true);
        btProximo.setEnabled(true);
        btUltimo.setEnabled(true);
        btExcluir.setEnabled(true);
        btNovo.setEnabled(true);
        btSalvar.setEnabled(true);
    }
    // m?todo para ativar os bot?es quando o processo est? iniciando

    public void ativaInicio() {
        btPrimeiro.setEnabled(false);
        btAnterior.setEnabled(false);
        btProximo.setEnabled(false);
        btUltimo.setEnabled(false);
        btExcluir.setEnabled(false);
        btNovo.setEnabled(true);
        btSalvar.setEnabled(false);
    }

    // m?todo para limpar os campos do formul?rio
    private void limpaCampos() {
        tfCPF.setText("");
        tfSenha.setText("");
        cbAdmin.setSelected(false);
    }

    public static void main(String args[]) {
        java.awt.EventQueue.invokeLater(new Runnable() {

            @Override
            public void run() {
                ManterUsuario dialog = new ManterUsuario(new javax.swing.JFrame(), true);
                dialog.addWindowListener(new java.awt.event.WindowAdapter() {

                    @Override
                    public void windowClosing(java.awt.event.WindowEvent e) {
                        System.exit(0);
                    }
                });
                dialog.setVisible(true);
            }
        });
    }
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btAnterior;
    private javax.swing.JButton btExcluir;
    private javax.swing.JButton btNovo;
    private javax.swing.JButton btPrimeiro;
    private javax.swing.JButton btProximo;
    private javax.swing.JButton btSair;
    private javax.swing.JButton btSalvar;
    private javax.swing.JButton btUltimo;
    private javax.swing.ButtonGroup buttonGroup1;
    private javax.swing.ButtonGroup buttonGroup2;
    private javax.swing.JCheckBox cbAdmin;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JPanel jPanel2;
    private javax.swing.JTextField tfCPF;
    private javax.swing.JTextField tfSenha;
    // End of variables declaration//GEN-END:variables

}
