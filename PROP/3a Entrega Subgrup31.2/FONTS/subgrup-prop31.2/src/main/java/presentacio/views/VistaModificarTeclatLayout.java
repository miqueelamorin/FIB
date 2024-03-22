package presentacio.views;

import presentacio.CtrlPresentacio;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;
import java.net.URL;

import static java.lang.Math.max;

/**
 * Aquesta vista permet modificar el layout d'un teclat.
 */
public class VistaModificarTeclatLayout extends JFrame{
    /**
     * Constructora de la classe.
     * @param nom nom del teclat
     * @param key distribucio del teclat a modificar
     * @param alfabet nom de l'alfabet del teclat per calcular els layouts
     */
    public VistaModificarTeclatLayout(String nom, char[][] key, String alfabet){
        setSize(700, 500);
        setLocationRelativeTo(null);
        setResizable(false);
        setTitle("Modificar layout de " + nom);
        JPanel lamina = new JPanel(new BorderLayout());

        ImageIcon arrow = null;
        URL imgURL = VistaTeclats.class.getClassLoader().getResource("arrow.png");
        if(imgURL != null) arrow = new ImageIcon(imgURL);
        else JOptionPane.showMessageDialog(this, "Icon image not found.");

        int altura = max(key.length*31, 500);

        JButton bEnrere = new JButton(arrow);
        bEnrere.setBounds(10,10, 30,30);
        lamina.add(bEnrere);

        JButton bModificar = new JButton("Modificar");
        bModificar.setBounds(20, altura-80, 90, 30);
        lamina.add(bModificar);

        JPanel keyboard = new JPanel();
        keyboard.setLayout(new GridBagLayout());

        JPanel pRow;
        GridBagConstraints c = new GridBagConstraints();
        c.anchor = GridBagConstraints.CENTER;
        c.weightx = 1d;

        for (int row = 0; row < key.length; ++row) {
            pRow = new JPanel(new GridBagLayout());

            c.gridy = row;

            for (int col = 0; col < key[row].length; ++col)
                pRow.add(new JButton(String.valueOf(key[row][col])));

            keyboard.add(pRow, c);
        }

        JLabel label = new JLabel("Layouts:");
        label.setBounds(20, 40, 60, 20);
        lamina.add(label);

        String[] l = new String[0];
        try {
            l = CtrlPresentacio.getLayouts(null, alfabet);
        } catch (Exception ex) {
            JOptionPane.showMessageDialog(null, ex.getMessage(), "ERROR", JOptionPane.ERROR_MESSAGE);
        }

        JComboBox<String> llistaLayouts = new JComboBox<>(l);
        llistaLayouts.setBounds(80,35,100,30);
        lamina.add(llistaLayouts);

        lamina.add(keyboard, BorderLayout.CENTER);
        JPanel laminaArea = new JPanel(new BorderLayout());
        JScrollPane scrollPane = new JScrollPane(lamina);
        laminaArea.add(scrollPane);

        add(laminaArea);

        setVisible(true);
        setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
        addWindowListener(new WindowEventHandlerImpl());

        ActionListener enrere = e -> {
            CtrlPresentacio.vistaElements("Teclats", nom);
            setVisible(false);
        };

        ActionListener modificar = e -> {
            String layout = (String)llistaLayouts.getSelectedItem();
            try {
                CtrlPresentacio.modificarTeclatLayout(nom, layout);
                setVisible(false);
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(null, ex.getMessage(), "ERROR", JOptionPane.ERROR_MESSAGE);
            }
        };

        bModificar.addActionListener(modificar);
        bEnrere.addActionListener(enrere);
    }
}
