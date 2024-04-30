
package telas;

import javax.swing.JDialog;

public class MenuPrincipal extends javax.swing.JFrame {

    public MenuPrincipal() {
        
        try {
            javax.swing.UIManager.setLookAndFeel("com.sun.java.swing.plaf.windows.WindowsLookAndFeel");
        } catch (Exception e) {
        }
        initComponents();
    }
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jInternalFrame1 = new javax.swing.JInternalFrame();
        jMenuBar1 = new javax.swing.JMenuBar();
        jMenu1 = new javax.swing.JMenu();
        jSeparator1 = new javax.swing.JPopupMenu.Separator();
        miPacote = new javax.swing.JMenuItem();
        miUsuario = new javax.swing.JMenuItem();
        miSituacoes = new javax.swing.JMenuItem();
        miEntregador = new javax.swing.JMenuItem();
        miDestinatario = new javax.swing.JMenuItem();
        jSeparator2 = new javax.swing.JPopupMenu.Separator();
        miSair = new javax.swing.JMenuItem();
        jMenu2 = new javax.swing.JMenu();
        jMenuItem1 = new javax.swing.JMenuItem();

        jInternalFrame1.setVisible(true);

        javax.swing.GroupLayout jInternalFrame1Layout = new javax.swing.GroupLayout(jInternalFrame1.getContentPane());
        jInternalFrame1.getContentPane().setLayout(jInternalFrame1Layout);
        jInternalFrame1Layout.setHorizontalGroup(
            jInternalFrame1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 0, Short.MAX_VALUE)
        );
        jInternalFrame1Layout.setVerticalGroup(
            jInternalFrame1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 0, Short.MAX_VALUE)
        );

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Exemplo de utilização de componentes para ambiente desktop");
        setExtendedState(6);

        jMenu1.setText("Arquivo");
        jMenu1.add(jSeparator1);

        miPacote.setIcon(new javax.swing.ImageIcon(getClass().getResource("/icons/briefcase.png"))); // NOI18N
        miPacote.setText("Pacote");
        miPacote.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                miPacoteActionPerformed(evt);
            }
        });
        jMenu1.add(miPacote);

        miUsuario.setIcon(new javax.swing.ImageIcon(getClass().getResource("/icons/bricks.png"))); // NOI18N
        miUsuario.setText("Usuario");
        miUsuario.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                miUsuarioActionPerformed(evt);
            }
        });
        jMenu1.add(miUsuario);

        miSituacoes.setIcon(new javax.swing.ImageIcon(getClass().getResource("/icons/brick_link.png"))); // NOI18N
        miSituacoes.setText("Situacoes");
        miSituacoes.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                miSituacoesActionPerformed(evt);
            }
        });
        jMenu1.add(miSituacoes);

        miEntregador.setIcon(new javax.swing.ImageIcon(getClass().getResource("/icons/car.png"))); // NOI18N
        miEntregador.setText("Entregador");
        miEntregador.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                miEntregadorActionPerformed(evt);
            }
        });
        jMenu1.add(miEntregador);

        miDestinatario.setIcon(new javax.swing.ImageIcon(getClass().getResource("/icons/car_add.png"))); // NOI18N
        miDestinatario.setText("Destinatario");
        miDestinatario.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                miDestinatarioActionPerformed(evt);
            }
        });
        jMenu1.add(miDestinatario);
        jMenu1.add(jSeparator2);

        miSair.setAccelerator(javax.swing.KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_F4, java.awt.event.InputEvent.ALT_DOWN_MASK));
        miSair.setIcon(new javax.swing.ImageIcon(getClass().getResource("/icons/door_in.png"))); // NOI18N
        miSair.setText("Sair do Sistema");
        miSair.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                miSairActionPerformed(evt);
            }
        });
        jMenu1.add(miSair);

        jMenuBar1.add(jMenu1);

        jMenu2.setText("Ajuda");

        jMenuItem1.setIcon(new javax.swing.ImageIcon(getClass().getResource("/icons/tick.png"))); // NOI18N
        jMenuItem1.setText("Sobre");
        jMenuItem1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItem1ActionPerformed(evt);
            }
        });
        jMenu2.add(jMenuItem1);

        jMenuBar1.add(jMenu2);

        setJMenuBar(jMenuBar1);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 400, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 279, Short.MAX_VALUE)
        );

        setSize(new java.awt.Dimension(416, 336));
        setLocationRelativeTo(null);
    }// </editor-fold>//GEN-END:initComponents

    private void miSairActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_miSairActionPerformed
        
        Object[] opcoes = {"Sim", "Nao"};
        int opc = javax.swing.JOptionPane.showOptionDialog(this,
                "Sair do sistema ?", "Saida do Sistema",
                javax.swing.JOptionPane.YES_NO_OPTION,
                javax.swing.JOptionPane.QUESTION_MESSAGE,
                null, opcoes, opcoes[0]);
        if (opc == 0) {
            System.exit(0);
        }
    }//GEN-LAST:event_miSairActionPerformed

    private void miPacoteActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_miPacoteActionPerformed
        JDialog cPart = new CadastrarPacote(this, true);
        cPart.setVisible(true);
    }//GEN-LAST:event_miPacoteActionPerformed

    private void miUsuarioActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_miUsuarioActionPerformed
        JDialog cPart = new ManterUsuario(this, true);
        cPart.setVisible(true);
    }//GEN-LAST:event_miUsuarioActionPerformed

    private void miSituacoesActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_miSituacoesActionPerformed
        JDialog cPart = new ManterSituacoes(this, true);
        cPart.setVisible(true);
    }//GEN-LAST:event_miSituacoesActionPerformed

    private void miEntregadorActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_miEntregadorActionPerformed
        JDialog cPart = new CadastrarEntregadores(this, true);
        cPart.setVisible(true);
    }//GEN-LAST:event_miEntregadorActionPerformed

    private void miDestinatarioActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_miDestinatarioActionPerformed
        JDialog cPart = new CadastrarDestinatario(this, true);
        cPart.setVisible(true);
    }//GEN-LAST:event_miDestinatarioActionPerformed

    private void jMenuItem1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItem1ActionPerformed
        JDialog cPart = new SobreProjeto(this, true);
        cPart.setVisible(true);
    }//GEN-LAST:event_jMenuItem1ActionPerformed
    
    
    public static void main(String args[]) {
    java.awt.EventQueue.invokeLater(() -> {
        MenuPrincipal menu = new MenuPrincipal();
        menu.setVisible(true);
        menu.jMenuItem1ActionPerformed(null); // Chama o evento de clique do JMenuItem1 (Sobre)
    });
}

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JInternalFrame jInternalFrame1;
    private javax.swing.JMenu jMenu1;
    private javax.swing.JMenu jMenu2;
    private javax.swing.JMenuBar jMenuBar1;
    private javax.swing.JMenuItem jMenuItem1;
    private javax.swing.JPopupMenu.Separator jSeparator1;
    private javax.swing.JPopupMenu.Separator jSeparator2;
    private javax.swing.JMenuItem miDestinatario;
    private javax.swing.JMenuItem miEntregador;
    private javax.swing.JMenuItem miPacote;
    private javax.swing.JMenuItem miSair;
    private javax.swing.JMenuItem miSituacoes;
    private javax.swing.JMenuItem miUsuario;
    // End of variables declaration//GEN-END:variables

}
