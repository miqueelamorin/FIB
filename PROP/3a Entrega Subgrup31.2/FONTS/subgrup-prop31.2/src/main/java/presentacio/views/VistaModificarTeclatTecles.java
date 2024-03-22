package presentacio.views;

import presentacio.CtrlPresentacio;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;
import java.net.URL;

import static java.lang.Math.max;

/**
 * Aquesta vista permet modificar les tecles d'un teclat.
 */
public class VistaModificarTeclatTecles extends JFrame{
    /**
     * Constructora de la classe.
     * @param nom nom del teclat
     * @param key distribucio del teclat a modificar
     * @param alfabet nom de l'alfabet del teclat per llistar les lletres
     */
    public VistaModificarTeclatTecles(String nom, char[][] key, Character[] alfabet){
        setSize(700, 500);
        setLocationRelativeTo(null);
        setResizable(false);
        setTitle("Modificat tecles de " + nom);
        JPanel lamina = new JPanel(new BorderLayout());

        ImageIcon arrow = null;
        URL imgURL = VistaTeclats.class.getClassLoader().getResource("arrow.png");
        if(imgURL != null) arrow = new ImageIcon(imgURL);
        else JOptionPane.showMessageDialog(this, "Icon image not found.");

        JButton bEnrere = new JButton(arrow);
        bEnrere.setBounds(10,10, 30,30);
        lamina.add(bEnrere);

        int altura = max(key.length*31, 500);

        JButton bModificar = new JButton("Modificar");
        bModificar.setBounds(20, altura-80, 100, 30);
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

        JLabel fil1 = new JLabel("Lletra 1:");
        fil1.setBounds(20, 40, 60, 20);
        lamina.add(fil1);

        JComboBox<Character> llista1 = new JComboBox<>(alfabet);
        llista1.setBounds(80,35,60,30);
        lamina.add(llista1);

        JLabel col1 = new JLabel("Lletra 2:");
        col1.setBounds(20, 60, 60, 20);
        lamina.add(col1);

        JComboBox<Character> llista2 = new JComboBox<>(alfabet);
        llista2.setBounds(80,60,60,30);
        lamina.add(llista2);

        lamina.add(keyboard, BorderLayout.CENTER);
        JPanel laminaArea = new JPanel(new BorderLayout());
        JScrollPane scrollPane = new JScrollPane(lamina);
        laminaArea.add(scrollPane);

        add(laminaArea);

        setVisible(true);
        setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
        addWindowListener(new WindowEventHandlerImpl());

        ActionListener enrere = e -> {
            new VistaTeclat(key, nom);
            setVisible(false);
        };

        ActionListener modificar = e -> {
            char l1 = (char) llista1.getSelectedItem();
            char l2 = (char) llista2.getSelectedItem();

            try {
                CtrlPresentacio.modificarTeclatTecles(nom, l1, l2, key);
                setVisible(false);
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(null, ex.getMessage(), "ERROR", JOptionPane.ERROR_MESSAGE);
            }
        };

        bModificar.addActionListener(modificar);
        bEnrere.addActionListener(enrere);
    }
}
