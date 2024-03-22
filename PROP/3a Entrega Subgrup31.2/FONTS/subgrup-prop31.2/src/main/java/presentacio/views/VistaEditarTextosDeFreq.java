package presentacio.views;

import presentacio.CtrlPresentacio;

import javax.swing.*;
import java.awt.event.ActionListener;
import java.net.URL;

/**
 * Aquesta vista permet editar els textos d'una llista de frequencia.
 */
public class VistaEditarTextosDeFreq extends JFrame {
    /**
     * Llista de noms dels textos.
     */
    private final JComboBox<String> llista;

    /**
     * Constructora de la classe.
     * @param nomLl nom de la llista de frequencia
     * @param dades llista de noms dels textos
     * @param op 0 si es vol eliminar un text, 1 si es vol afegir un text
     */
    public VistaEditarTextosDeFreq(String nomLl, String[] dades, int op){
        setSize(500,150);
        setLocationRelativeTo(null);
        setResizable(false);
        setTitle("Editar Llistes de freqüència");

        ImageIcon arrow = null;
        URL imgURL = VistaTeclats.class.getClassLoader().getResource("arrow.png");
        if(imgURL != null) arrow = new ImageIcon(imgURL);
        else JOptionPane.showMessageDialog(this, "Icon image not found.");

        llista = new JComboBox<>(dades);
        llista.setBounds(20,50,320,30);
        add(llista);

        JButton button = new JButton();
        if (op == 0) button.setText("Eliminar");
        else if (op == 1) button.setText("Afegir");
        button.setBounds(getSize().width-120, getSize().height-70, 100, 20);
        add(button);

        JButton bEnrere = new JButton(arrow);
        bEnrere.setBounds(10,10, 30,30);
        add(bEnrere);

        JPanel lamina = new JPanel();
        add(lamina);
        setVisible(true);
        setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
        addWindowListener(new WindowEventHandlerImpl());

        ActionListener accio = e -> {
            try {
                String a = (String) llista.getSelectedItem();
                CtrlPresentacio.editarTextosDeFrequencia(nomLl, a, op);
                setVisible(false);
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(null, ex.getMessage(), "ERROR", JOptionPane.ERROR_MESSAGE);
            }
        };

        ActionListener enrere = e -> {
            CtrlPresentacio.vistaElements("Llistes de freqüència", nomLl);
            setVisible(false);
        };

        button.addActionListener(accio);
        bEnrere.addActionListener(enrere);
    }
}
