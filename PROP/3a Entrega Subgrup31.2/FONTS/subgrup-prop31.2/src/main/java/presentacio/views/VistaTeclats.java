package presentacio.views;

import presentacio.CtrlPresentacio;

import javax.swing.*;
import java.awt.event.ActionListener;
import java.net.*;

/**
 * Aquesta vista permet veure els teclats disponibles, crear-ne de nous i seleccionar-ne un.
 */
public class VistaTeclats extends JFrame {
    /**
     * Constructora de la classe.
     * @param dades llista de teclats
     * @param seleccionat teclat seleccionat anteriorment
     */
    public VistaTeclats(String[] dades, String seleccionat){
        setSize(500,300);
        setLocationRelativeTo(null);
        setResizable(false);
        setTitle("Teclats");

        ImageIcon arrow = null;
        URL imgURL = VistaTeclats.class.getClassLoader().getResource("arrow.png");
        if(imgURL != null) arrow = new ImageIcon(imgURL);
        else JOptionPane.showMessageDialog(this, "Icon image not found.");

        ImageIcon add = null;
        imgURL = VistaTeclats.class.getClassLoader().getResource("+.png");
        if(imgURL != null) add = new ImageIcon(imgURL);
        else JOptionPane.showMessageDialog(this, "Icon image not found.");

        JComboBox<String> llista = new JComboBox<>(dades);
        llista.setBounds(20,50,150,40);
        llista.setSelectedItem(seleccionat);
        add(llista);

        JButton bEnrere = new JButton(arrow);
        bEnrere.setBounds(10,10, 30,30);
        add(bEnrere);

        JButton bCrear = new JButton(add);
        bCrear.setBounds(180, 55, 30, 30);
        add(bCrear);

        JPanel lamina = new JPanel();
        add(lamina);
        setVisible(true);
        setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
        addWindowListener(new WindowEventHandlerImpl());

        ActionListener crear = e -> {
            try {
                CtrlPresentacio.vistaCrearTeclat();
                setVisible(false);
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(null, ex.getMessage(), "ERROR", JOptionPane.ERROR_MESSAGE);
            }
        };

        ActionListener enrere = e -> {
            try {
                CtrlPresentacio.iniPresentacio();
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(null, ex.getMessage(), "ERROR", JOptionPane.ERROR_MESSAGE);
            }
            setVisible(false);
        };

        ActionListener seleccionar = e ->{
            String elem = (String) llista.getSelectedItem();
            try {
                char[][] key = CtrlPresentacio.getTeclat(elem);
                new VistaTeclat(key,elem);
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(null, ex.getMessage(), "ERROR", JOptionPane.ERROR_MESSAGE);
            }
            setVisible(false);
        };

        bEnrere.addActionListener(enrere);
        llista.addActionListener(seleccionar);
        bCrear.addActionListener(crear);
    }
}
