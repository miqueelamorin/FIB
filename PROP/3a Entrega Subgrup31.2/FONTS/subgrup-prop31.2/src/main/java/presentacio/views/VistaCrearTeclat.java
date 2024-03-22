package presentacio.views;

import presentacio.CtrlPresentacio;

import javax.swing.*;
import java.awt.event.ActionListener;
import java.net.URL;

/**
 * Aquesta vista permet crear un teclat.
 */
public class VistaCrearTeclat extends JFrame {
    /**
     * Lamina de la vista.
     */
    private final JPanel lamina = new JPanel();
    /**
     * Seleccionador de layouts.
     */
    private JComboBox<String> layouts = new JComboBox<>();
    /**
     * Algoritme seleccionat.
     */
    private String alg;

    /**
     * Constructora de la classe.
     * @param llistes noms de les llistes de frequencia
     * @param alfabets noms dels alfabets
     */
    public VistaCrearTeclat(String[] llistes, String[] alfabets){

        ImageIcon arrow = null;
        URL imgURL = VistaTeclats.class.getClassLoader().getResource("arrow.png");
        if(imgURL != null) arrow = new ImageIcon(imgURL);
        else JOptionPane.showMessageDialog(this, "Icon image not found.");

        ImageIcon add = null;
        imgURL = VistaTeclats.class.getClassLoader().getResource("+.png");
        if(imgURL != null) add = new ImageIcon(imgURL);
        else JOptionPane.showMessageDialog(this, "Icon image not found.");

        setSize(500,400);
        setLocationRelativeTo(null);
        setResizable(false);
        setTitle("Creació de Teclat");

        JLabel lnom = new JLabel("Posa-li un nom:");
        lnom.setBounds(20,50,210,20);
        add(lnom);

        JTextField nom = new JTextField();
        nom.setBounds(230,50,210,20);
        add(nom);

        JLabel lalfabets = new JLabel("Escull un Alfabet:");
        lalfabets.setBounds(20,100,210,20);
        add(lalfabets);

        JLabel lllistes = new JLabel("Escull una Llista de Frequencies:");
        lllistes.setBounds(20,150,210,20);
        add(lllistes);

        JComboBox<String> llistaAlfabets = new JComboBox<>(alfabets);
        llistaAlfabets.setSelectedItem(null);
        llistaAlfabets.setBounds(230,95,200,30);
        add(llistaAlfabets);

        JComboBox<String> llistaLlistes = new JComboBox<>(llistes);
        llistaLlistes.setSelectedItem(null);
        llistaLlistes.setBounds(230,145,200,30);
        add(llistaLlistes);

        layouts.setEnabled(false);
        layouts.setBounds(230,195,200,30);
        add(layouts);

        JLabel llayouts = new JLabel("Escull un Layout:");
        llayouts.setBounds(20,200,210,20);
        add(llayouts);

        JLabel lalgoritme = new JLabel("Escull un Algoritme:");
        lalgoritme.setBounds(20,250,210,20);
        add(lalgoritme);

        JRadioButton bnb = new JRadioButton("Branch And Bound");
        bnb.setBounds(230,245,200,30);
        add(bnb);

        JRadioButton gen = new JRadioButton("Genetic");
        gen.setBounds(230,265,200,30);
        add(gen);

        JButton bCrearAlf = new JButton(add);
        bCrearAlf.setBounds(450, 95, 30, 30);
        add(bCrearAlf);

        JButton bCrearLl = new JButton(add);
        bCrearLl.setBounds(450, 145, 30, 30);
        add(bCrearLl);

        JButton bCrear = new JButton("Crear");
        bCrear.setBounds(getSize().width-120, getSize().height-70, 100, 30);
        add(bCrear);

        JButton bEnrere = new JButton(arrow);
        bEnrere.setBounds(10,10, 30,30);
        add(bEnrere);

        add(lamina);
        setVisible(true);
        setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
        addWindowListener(new WindowEventHandlerImpl());

        ActionListener seleccionarAlfabet = e -> {
            remove(layouts);
            String nomAlfabet = (String) llistaAlfabets.getSelectedItem();
            String[] a = new String[0];
            try {
                a = CtrlPresentacio.getLayouts(nomAlfabet, null);
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(null, ex.getMessage(), "ERROR", JOptionPane.ERROR_MESSAGE);
            }
            layouts = new JComboBox<>(a);
            layouts.setEnabled(true);
            layouts.setBounds(230,195,200,30);
            layouts.setSelectedItem(null);
            add(layouts);
            add(lamina);
            setVisible(true);
        };

        ActionListener crear = e -> {
            String nomT = nom.getText();
            String alfabet = (String)llistaAlfabets.getSelectedItem();
            String llista = (String)llistaLlistes.getSelectedItem();
            String layout = (String)layouts.getSelectedItem();
            try{
                boolean b = CtrlPresentacio.algorimeFactible(alfabet, alg);
                int opt = -1;
                if (!b) opt = JOptionPane.showConfirmDialog(null,
                        "L'algoritme Branch And Bound requereix molt temps d'execució per aquesta mida de teclat, vols canviar-lo pel Genetic Algorithm?",
                        "Advertència",
                        JOptionPane.YES_NO_OPTION);
                if (opt == 0) {
                    gen.setSelected(true);
                    bnb.setSelected(false);
                    alg = gen.getText();
                }
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(null, "Selecciona un Alfabet", "ERROR", JOptionPane.ERROR_MESSAGE);
            }

            try {
                CtrlPresentacio.crearTeclat(nomT, alfabet, llista, layout, alg);
                setVisible(false);
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(null, ex.getMessage(), "ERROR", JOptionPane.ERROR_MESSAGE);
            }
        };

        ActionListener enrere = e -> {
            CtrlPresentacio.vistaElements("Teclats", null);
            setVisible(false);
        };

        ActionListener crearLl = e -> {
            int sel  = JOptionPane.showOptionDialog(
                    null,
                    "Selecciona una opció",
                    "Crear llista de frequencia",
                    JOptionPane.YES_NO_OPTION,
                    JOptionPane.QUESTION_MESSAGE,
                    null,
                    new Object[] { "Crear", "Importar", "Textos"},
                    null);
            CtrlPresentacio.vistaCrearTextosFreq(sel, "Llistes de freqüència", null);
            setVisible(false);
        };

        ActionListener crearAlf = e -> {
            int sel  = JOptionPane.showOptionDialog(
                    null,
                    "Selecciona una opció",
                    "Crear alfabet",
                    JOptionPane.YES_NO_OPTION,
                    JOptionPane.QUESTION_MESSAGE,
                    null,
                    new Object[] { "Crear", "Importar"},
                    null);
            CtrlPresentacio.vistaCrearAlfabet(sel, null);
            setVisible(false);
        };

        ActionListener selecBnb = e -> {
            alg = bnb.getText();
            gen.setSelected(false);
        };

        ActionListener selecGen = e -> {
            alg = gen.getText();
            bnb.setSelected(false);
        };

        bCrearAlf.addActionListener(crearAlf);
        bCrearLl.addActionListener(crearLl);
        bCrear.addActionListener(crear);
        llistaAlfabets.addActionListener(seleccionarAlfabet);
        bEnrere.addActionListener(enrere);
        bnb.addActionListener(selecBnb);
        gen.addActionListener(selecGen);
    }
}
