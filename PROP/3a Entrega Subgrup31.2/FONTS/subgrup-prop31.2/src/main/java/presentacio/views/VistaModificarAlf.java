package presentacio.views;

import presentacio.CtrlPresentacio;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;
import java.net.URL;

/**
 * Aquesta vista permet modificar un alfabet.
 */
public class VistaModificarAlf extends JFrame{
    /**
     * Constructora de la classe.
     * @param nom nom de l'alfabet
     * @param dades contingut de l'alfabet
     */
    public VistaModificarAlf(String nom, String dades){
        setSize(700,300);
        setLocationRelativeTo(null);
        setResizable(false);
        setTitle("Modifica " + nom);

        ImageIcon arrow = null;
        URL imgURL = VistaTeclats.class.getClassLoader().getResource("arrow.png");
        if(imgURL != null) arrow = new ImageIcon(imgURL);
        else JOptionPane.showMessageDialog(this, "Icon image not found.");

        JLabel linst = new JLabel();
        linst.setText("Escriu l'alfabet (no es tenen en compte els espais com a caràcters)");
        linst.setBounds(20,50,700,20);
        add(linst);

        JTextField textField = new JTextField(dades);
        JPanel laminaArea = new JPanel(new BorderLayout());
        JScrollPane scrollPane = new JScrollPane(textField);
        laminaArea.add(scrollPane);
        laminaArea.setBounds(20,80,getSize().width-40,50);
        add(laminaArea);

        JButton bModificar = new JButton("Modificar");
        bModificar.setBounds(getSize().width-120, getSize().height-70, 90, 30);
        add(bModificar);

        JButton bEnrere = new JButton(arrow);
        bEnrere.setBounds(10,10, 30,30);
        add(bEnrere);

        JPanel lamina = new JPanel();
        add(lamina);
        setVisible(true);
        setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
        addWindowListener(new WindowEventHandlerImpl());

        ActionListener crear = e -> {
            try {
                CtrlPresentacio.modificarAlfTextLl(nom, textField.getText(), "Alfabets");
                setVisible(false);
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(null, ex.getMessage(), "ERROR", JOptionPane.ERROR_MESSAGE);
            }
        };

        ActionListener enrere = e -> {
            try {
                CtrlPresentacio.vistaElements("Alfabets", nom);
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(null, ex.getMessage(), "ERROR", JOptionPane.ERROR_MESSAGE);
                CtrlPresentacio.vistaElements("Alfabets", nom);
            }
            setVisible(false);
        };

        bModificar.addActionListener(crear);
        bEnrere.addActionListener(enrere);
    }


}
