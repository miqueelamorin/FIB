package presentacio.views;

import presentacio.CtrlPresentacio;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;
import java.net.URL;

import static java.lang.Math.max;

/**
 * Aquesta vista permet veure la distribució un teclat.
 */
public class VistaTeclat extends JFrame{

    /**
     * Constructora de la classe.
     * @param key distribucio del teclat
     * @param nom nom del teclat
     */
    public VistaTeclat(char[][] key, String nom) {
        setSize(700, 500);
        setLocationRelativeTo(null);
        setResizable(true);
        setTitle(nom);
        JPanel lamina = new JPanel(new BorderLayout());

        ImageIcon arrow = null;
        URL imgURL = VistaTeclats.class.getClassLoader().getResource("arrow.png");
        if(imgURL != null) arrow = new ImageIcon(imgURL);
        else JOptionPane.showMessageDialog(this, "Icon image not found.");

        int altura = max(key.length*31, 500);

        JPanel buttonsPanel = new JPanel();
        add(buttonsPanel, BorderLayout.SOUTH);

        JButton bModificar = new JButton("Modificar");
        bModificar.setBounds(20, altura-110, 90, 30);
        buttonsPanel.add(bModificar);

        JButton bEliminar = new JButton("Eliminar");
        bEliminar.setBounds(20, altura-80, 90, 30);
        buttonsPanel.add(bEliminar);

        JButton bEnrere = new JButton(arrow);
        bEnrere.setBounds(10,10, 30,30);
        lamina.add(bEnrere);

        JPanel keyboard = new JPanel();
        keyboard.setLayout(new GridBagLayout());

        JPanel pRow;
        GridBagConstraints c = new GridBagConstraints();
        c.anchor = GridBagConstraints.CENTER;
        c.weightx = 1d;

        for (int row = 0; row < key.length; ++row) {
            pRow = new JPanel(new GridBagLayout());

            c.gridy = row;

            for (int col = 0; col < key[row].length; ++col) {
                JButton b = new JButton(String.valueOf(key[row][col]));
                b.setSize(30,30);
                pRow.add(b);
            }

            keyboard.add(pRow, c);
        }

        lamina.add(keyboard, BorderLayout.CENTER);
        JPanel laminaArea = new JPanel(new BorderLayout());
        JScrollPane scrollPane = new JScrollPane(lamina);
        laminaArea.add(scrollPane);

        add(laminaArea);

        setVisible(true);
        setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
        addWindowListener(new WindowEventHandlerImpl());

        ActionListener eliminar = e -> {
            int a = JOptionPane.showConfirmDialog(null, "Vols eliminar " + nom + "?", "Eliminació", JOptionPane.YES_NO_OPTION);
            if (a == JOptionPane.YES_OPTION) {
                try {
                    CtrlPresentacio.eliminarElement(nom, "Teclats");
                    setVisible(false);
                } catch (Exception ex) {
                    JOptionPane.showMessageDialog(null, ex.getMessage(), "ERROR", JOptionPane.ERROR_MESSAGE);
                }
            }
        };

        ActionListener modificar = e -> {
            int sel  = JOptionPane.showOptionDialog(
                    null,
                    "Selecciona una opció",
                    "Modificar " + nom,
                    JOptionPane.YES_NO_OPTION,
                    JOptionPane.QUESTION_MESSAGE,
                    null,
                    new Object[] {"Layout","Tecles"},
                    null);
            try {
                CtrlPresentacio.modificarTeclat(nom, sel);
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(null, ex.getMessage(), "ERROR", JOptionPane.ERROR_MESSAGE);
            }
            setVisible(false);
        };

        ActionListener enrere = e -> {
            try {
                CtrlPresentacio.vistaElements("Teclats", nom);
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(null, ex.getMessage(), "ERROR", JOptionPane.ERROR_MESSAGE);
            }
            setVisible(false);
        };

        bModificar.addActionListener(modificar);
        bEliminar.addActionListener(eliminar);
        bEnrere.addActionListener(enrere);
    }
}
