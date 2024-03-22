package presentacio.views;

import presentacio.CtrlPresentacio;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;
import java.net.URL;

/**
 * Aquesta classe és la vista de la gestió dels alfabets,
 * permet seleccionar un alfabet, modificar-lo, eliminar-lo i crear-ne de nous.
 */
public class VistaAlfabets extends JFrame {
    /**
     * Camp de text on es mostra el contingut de l'alfabet seleccionat.
     */
    private JTextField textField = new JTextField();
    /**
     * Lamina de la vista de l'alfabet seleccionat.
     */
    private JPanel laminaArea;
    /**
     * Boton d'eliminar.
     */
    private final JButton bEliminar = new JButton("Eliminar");
    /**
     * Boton de modificar.
     */
    private final JButton bModificar = new JButton("Modificar");
    /**
     * Lamina de la vista.
     */
    private final JPanel lamina = new JPanel();

    /**
     * Constructora de la classe.
     * @param dades llista de noms dels alfabets
     * @param seleccionat nom de l'alfabet seleccionat anteriorment
     */
    public VistaAlfabets(String[] dades, String seleccionat) {
        setSize(700, 300);
        setLocationRelativeTo(null);
        setResizable(false);
        setTitle("Alfabets");

        ImageIcon arrow = null;
        URL imgURL = VistaTeclats.class.getClassLoader().getResource("arrow.png");
        if(imgURL != null) arrow = new ImageIcon(imgURL);
        else JOptionPane.showMessageDialog(this, "Icon image not found.");

        ImageIcon add = null;
        imgURL = VistaTeclats.class.getClassLoader().getResource("+.png");
        if(imgURL != null) add = new ImageIcon(imgURL);
        else JOptionPane.showMessageDialog(this, "Icon image not found.");

        JComboBox<String> llista = new JComboBox<>(dades);
        llista.setBounds(20, 50, 150, 40);
        llista.setSelectedItem(seleccionat);
        add(llista);

        bModificar.setBounds(getSize().width - 120, getSize().height - 75, 100, 30);

        JButton bEnrere = new JButton(arrow);
        bEnrere.setBounds(10, 10, 30, 30);
        add(bEnrere);

        bEliminar.setBounds(getSize().width - 230, getSize().height - 75, 100, 30);

        JButton bCrear = new JButton(add);
        bCrear.setBounds(180, 55, 30, 30);
        add(bCrear);

        mostrar(seleccionat, true);

        setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
        addWindowListener(new WindowEventHandlerImpl());

        ActionListener crear = e -> {
            try {
                int sel = JOptionPane.showOptionDialog(
                        null,
                        "Selecciona una opció",
                        "Crear alfabet",
                        JOptionPane.YES_NO_OPTION,
                        JOptionPane.QUESTION_MESSAGE,
                        null,
                        new Object[]{"Manualment", "Importar"},
                        null);
                CtrlPresentacio.vistaCrearAlfabet(sel, (String) llista.getSelectedItem());
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

        ActionListener seleccionar = e -> {
            String elem = (String) llista.getSelectedItem();
            mostrar(elem, false);
        };

        ActionListener modificar = e -> {
            try {
                String elem = (String) llista.getSelectedItem();
                CtrlPresentacio.modificarAlfabet(elem);
                setVisible(false);
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(null, ex.getMessage(), "ERROR", JOptionPane.ERROR_MESSAGE);
            }
            setVisible(false);
        };

        ActionListener eliminar = e -> {
            String elem = (String) llista.getSelectedItem();
            int a = JOptionPane.showConfirmDialog(null, "Vols eliminar " + elem + "?", "Eliminació", JOptionPane.YES_NO_OPTION);
            if (a == JOptionPane.YES_OPTION) {
                try {
                    CtrlPresentacio.eliminarElement(elem, "Alfabets");
                    setVisible(false);
                } catch (Exception ex) {
                    JOptionPane.showMessageDialog(null, ex.getMessage(), "ERROR", JOptionPane.ERROR_MESSAGE);
                }
            }
        };

        bEnrere.addActionListener(enrere);
        llista.addActionListener(seleccionar);
        bModificar.addActionListener(modificar);
        bCrear.addActionListener(crear);
        bEliminar.addActionListener(eliminar);
    }

    /**
     * Mostra el contingut de l'alfabet seleccionat
     * @param nom  nom de l'alfabet
     * @param first indica si és la primera vegada que es crida a la funció
     */
    private void mostrar(String nom, boolean first) {
        try {
            if (!first) {
                remove(laminaArea);
                remove(textField);
            }
            if (nom == null) {
                textField = new JTextField();
                bModificar.setEnabled(false);
                bEliminar.setEnabled(false);
            } else {
                String alf = CtrlPresentacio.getAlfabet(nom);
                textField = new JTextField(alf);
                bModificar.setEnabled(true);
                bEliminar.setEnabled(true);
            }
            textField.setEditable(false);
            laminaArea = new JPanel(new BorderLayout());
            JScrollPane scrollPane = new JScrollPane(textField);
            laminaArea.add(scrollPane);
            laminaArea.setBounds(20, 120, getSize().width - 40, 50);
            add(laminaArea);
            add(bEliminar);
            add(bModificar);
            add(laminaArea);
            add(lamina);
            setVisible(true);
        } catch (Exception ex) {
            JOptionPane.showMessageDialog(null, ex.getMessage(), "ERROR", JOptionPane.ERROR_MESSAGE);
        }
    }
}
