package presentacio.views;

import presentacio.CtrlPresentacio;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;
import java.net.URL;
import java.util.List;

/**
 * Aquesta vista permet crear una llista de frequencia a partir de textos.
 */
public class VistaCrearFreqAmbTextos extends JFrame {
    /**
     * Llista de noms dels textos.
     */
    private final JList<String> llista;

    /**
     * Constructora de la classe.
     * @param dades llista de noms dels textos
     */
    public VistaCrearFreqAmbTextos(String[] dades){
        setSize(500,300);
        setLocationRelativeTo(null);
        setResizable(false);
        setTitle("Crear a partir de textos");

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

        llista = new JList<>(dades);
        llista.setSelectionMode(ListSelectionModel.MULTIPLE_INTERVAL_SELECTION);

        JScrollPane scroll = new JScrollPane(llista);
        JPanel laminadeLista = new JPanel(new BorderLayout());
        laminadeLista.add(scroll);

        laminadeLista.setBounds(20,100,330,150);
        add(laminadeLista);

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
                List<String> a = llista.getSelectedValuesList();
                CtrlPresentacio.crearAmbTextos(nom.getText(), a);
                setVisible(false);
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(null, ex.getMessage(), "ERROR", JOptionPane.ERROR_MESSAGE);
            }
        };

        ActionListener enrere = e -> {
            CtrlPresentacio.vistaElements("Llistes de freqüència", null);
            setVisible(false);
        };

        bCrear.addActionListener(crear);
        bEnrere.addActionListener(enrere);
    }
}
