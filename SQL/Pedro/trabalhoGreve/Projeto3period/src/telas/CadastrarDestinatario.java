/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package telas;

import entidades.Destinatario;
import java.util.ArrayList;
import java.util.List;
import javax.swing.JOptionPane;
import util.DestinatarioDAO;

/**
 *
 * @author Geri
 */
public class CadastrarDestinatario extends javax.swing.JDialog {

    DestinatarioDAO con = new DestinatarioDAO(); 
    List<Destinatario> destinatario = new ArrayList();
    Destinatario destinatarioAux;
    
    boolean novo = false;
    int i = -1;
    
    public CadastrarDestinatario(java.awt.Frame parent,
            boolean modal) {
        super(parent, modal);
        initComponents();
        // informa como devem estar os bot?es no in?cio do processo
        ativaInicio();
        destinatario = con.listar();
        if (!destinatario.isEmpty()) {
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
        tfRua = new javax.swing.JTextField();
        jLabel4 = new javax.swing.JLabel();
        tfNome = new javax.swing.JTextField();
        tfNumero = new javax.swing.JSpinner();
        tfTelefone = new javax.swing.JTextField();
        jLabel5 = new javax.swing.JLabel();
        jLabel6 = new javax.swing.JLabel();
        tfCEP = new javax.swing.JTextField();
        tfBairro = new javax.swing.JTextField();
        jLabel7 = new javax.swing.JLabel();
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
        setTitle("Cadastro de destinatários\n\n");

        jPanel1.setBorder(javax.swing.BorderFactory.createTitledBorder(javax.swing.BorderFactory.createEtchedBorder()));

        jLabel1.setText("CPF:");

        jLabel2.setText("Numero");

        jLabel3.setText("Nome");

        tfCPF.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                tfCPFActionPerformed(evt);
            }
        });

        jLabel4.setText("Telefone");

        tfTelefone.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                tfTelefoneActionPerformed(evt);
            }
        });

        jLabel5.setText("Rua");

        jLabel6.setText("Bairro");

        tfCEP.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                tfCEPActionPerformed(evt);
            }
        });

        tfBairro.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                tfBairroActionPerformed(evt);
            }
        });

        jLabel7.setText("CEP");

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addGroup(jPanel1Layout.createSequentialGroup()
                            .addGap(8, 8, 8)
                            .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                                .addComponent(jLabel4)
                                .addComponent(jLabel3)))
                        .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                            .addContainerGap()
                            .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                .addComponent(jLabel5, javax.swing.GroupLayout.Alignment.TRAILING)
                                .addComponent(jLabel6, javax.swing.GroupLayout.Alignment.TRAILING))))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGap(11, 11, 11)
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addComponent(jLabel1)
                            .addComponent(jLabel7)
                            .addComponent(jLabel2))))
                .addGap(18, 18, 18)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(tfNome, javax.swing.GroupLayout.DEFAULT_SIZE, 141, Short.MAX_VALUE)
                    .addComponent(tfRua)
                    .addComponent(tfTelefone)
                    .addComponent(tfCEP)
                    .addComponent(tfBairro)
                    .addComponent(tfNumero)
                    .addComponent(tfCPF))
                .addContainerGap(156, Short.MAX_VALUE))
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGap(16, 16, 16)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel1)
                    .addComponent(tfCPF, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel3)
                    .addComponent(tfNome, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel4)
                    .addComponent(tfTelefone, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(12, 12, 12)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(tfRua, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel5))
                .addGap(18, 18, 18)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel6)
                    .addComponent(tfBairro, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(tfCEP, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel7))
                .addGap(18, 18, 18)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jLabel2)
                    .addComponent(tfNumero, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(25, Short.MAX_VALUE))
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
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jPanel2, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addGap(0, 17, Short.MAX_VALUE)
                        .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jPanel2, javax.swing.GroupLayout.DEFAULT_SIZE, 185, Short.MAX_VALUE)
                .addContainerGap())
        );

        setSize(new java.awt.Dimension(416, 493));
        setLocationRelativeTo(null);
    }// </editor-fold>//GEN-END:initComponents

    private void btSairActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btSairActionPerformed
        // TODO add your handling code here:
        // Fecha o JDialog
        dispose();
    }//GEN-LAST:event_btSairActionPerformed

    private void btSalvarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btSalvarActionPerformed

        String cpf = tfCPF.getText();
        String nome = tfNome.getText();
        String telefone = tfTelefone.getText();
        
        String rua = tfRua.getText();
        String bairro = tfBairro.getText();
        String CEP = tfCEP.getText();
        
        int numero = ((Number) tfNumero.getValue()).intValue();
        
        destinatarioAux = new Destinatario(nome, cpf, telefone, rua, bairro, numero, CEP);
        
        if (novo) {
            con.inserir(destinatarioAux);
            destinatario.add(destinatarioAux);
            i = destinatario.size() - 1;
        } else {
            con.alterar(destinatarioAux);
            destinatario.set(i, destinatarioAux);
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
        if ((!destinatario.isEmpty()) && (i > 0)) {
            i = 0; // vai para o primeiro registro
            carregaDados();
        } else {
            JOptionPane.showMessageDialog(this, "Ja esta no primeiro registro");
        }
    }//GEN-LAST:event_btPrimeiroActionPerformed

    private void btAnteriorActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btAnteriorActionPerformed
        // TODO add your handling code here:
        // testa se tem registros e se ainda n?o est? no primeiro registro
        if ((!destinatario.isEmpty()) && (i > 0)) {
            i--; // vai para o registro anterior
            carregaDados();
        } else {
            JOptionPane.showMessageDialog(this, "Ja esta no primeiro registro");
        }
    }//GEN-LAST:event_btAnteriorActionPerformed

    private void btProximoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btProximoActionPerformed
        // TODO add your handling code here:
        // testa se tem registros e se n?o est? no ?ltimo registro
        if ((!destinatario.isEmpty()) && (i < destinatario.size() - 1)) {
            i++; // vai para o pr?ximo registro
            carregaDados();
        } else {
            JOptionPane.showMessageDialog(this, "Ja esta no ultimo registro");
        }
    }//GEN-LAST:event_btProximoActionPerformed

    private void btUltimoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btUltimoActionPerformed
        // TODO add your handling code here:
        if ((!destinatario.isEmpty()) && (i < destinatario.size() - 1)) {
            i = destinatario.size() - 1; // vai para o ?ltimo registro
            carregaDados();
        } else {
            JOptionPane.showMessageDialog(this, "Ja esta no ultimo registro");
        }
    }//GEN-LAST:event_btUltimoActionPerformed

    private void btExcluirActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btExcluirActionPerformed
        // TODO add your handling code here:
        // testa se h? registros
        if (i >= 0) {
            
            con.remover(destinatario.get(i).getDestinatario_id());
            destinatario.remove(i);
            // testa se ainda h? registros
            if (!destinatario.isEmpty()) {
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

    private void tfCPFActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_tfCPFActionPerformed
        
    }//GEN-LAST:event_tfCPFActionPerformed

    private void tfTelefoneActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_tfTelefoneActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_tfTelefoneActionPerformed

    private void tfCEPActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_tfCEPActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_tfCEPActionPerformed

    private void tfBairroActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_tfBairroActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_tfBairroActionPerformed

    // m?todo para carregar os dados do vetor din?mico para a tela
    private void carregaDados() {
        // os dados ser?o carregados da posi??o corrente, ou seja, do valor
        // armazenado em i
        destinatarioAux = destinatario.get(i); // recupera o cliente armazenado em i
        tfCPF.setText(destinatarioAux.getCPF());
        tfNome.setText(destinatarioAux.getNome());
        tfTelefone.setText(destinatarioAux.getTelefone());
        tfRua.setText(destinatarioAux.getRua());
        tfBairro.setText(destinatarioAux.getBairro());
        tfNumero.setValue(destinatarioAux.getNumero());
        tfCEP.setText(destinatarioAux.getCep());
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
        tfNumero.setValue(0);
        tfNome.setText("");
        tfTelefone.setText("");
        tfRua.setText("");
        tfBairro.setText("");
        tfCEP.setText("");
    }

    public static void main(String args[]) {
        java.awt.EventQueue.invokeLater(new Runnable() {

            @Override
            public void run() {
                CadastrarDestinatario dialog = new CadastrarDestinatario(new javax.swing.JFrame(), true);
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
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JPanel jPanel2;
    private javax.swing.JTextField tfBairro;
    private javax.swing.JTextField tfCEP;
    private javax.swing.JTextField tfCPF;
    private javax.swing.JTextField tfNome;
    private javax.swing.JSpinner tfNumero;
    private javax.swing.JTextField tfRua;
    private javax.swing.JTextField tfTelefone;
    // End of variables declaration//GEN-END:variables

}
