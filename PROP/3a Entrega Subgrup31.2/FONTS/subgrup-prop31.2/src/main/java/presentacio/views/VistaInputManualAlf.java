package presentacio.views;

import presentacio.CtrlPresentacio;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;
import java.net.URL;

/**
 * Aquesta vista permet crear un alfabet a manualment.
 */
public class VistaInputManualAlf extends JFrame{
    /**
     * Constructora de la classe.
     */
    public VistaInputManualAlf(){
        setSize(700,300);
        setLocationRelativeTo(null);
        setResizable(false);
        setTitle("Creació d'alfabets");

        ImageIcon arrow = null;
        URL imgURL = VistaTeclats.class.getClassLoader().getResource("arrow.png");
        if(imgURL != null) arrow = new ImageIcon(imgURL);
        else JOptionPane.showMessageDialog(this, "Icon image not found.");

        JLabel lnom = new JLabel("Posa-li un nom:");
        lnom.setBounds(20,50,210,20);
        add(lnom);

        JTextField nom = new JTextField();
        nom.setBounds(230,50,210,20);
        add(nom);

        JLabel linst = new JLabel();
        linst.setText("Escriu l'alfabet (no es tenen en compte els espais com a caràcters)");
        linst.setBounds(20,100,getSize().width-40,20);
        add(linst);

        JTextField textField = new JTextField();
        JPanel laminaArea = new JPanel(new BorderLayout());
        JScrollPane scrollPane = new JScrollPane(textField);
        laminaArea.add(scrollPane);
        laminaArea.setBounds(20,120,getSize().width-40,50);
        add(laminaArea);

        JButton bCrear = new JButton("Crear");
        bCrear.setBounds(getSize().width-120, getSize().height-75, 100, 30);
        add(bCrear);

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
                CtrlPresentacio.crearAlfTextLl(nom.getText(), textField.getText(), true, "Alfabets");
                setVisible(false);
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(null, ex.getMessage(), "ERROR", JOptionPane.ERROR_MESSAGE);
            }
        };

        ActionListener enrere = e -> {
            CtrlPresentacio.vistaElements("Alfabets", null);
            setVisible(false);
        };

        bCrear.addActionListener(crear);
        bEnrere.addActionListener(enrere);
    }
}
