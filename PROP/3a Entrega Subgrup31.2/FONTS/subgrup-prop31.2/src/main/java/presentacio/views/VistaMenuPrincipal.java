package presentacio.views;

import presentacio.CtrlPresentacio;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;

/**
 * Aquesta vista és el menú principal del programa.
 */
public class VistaMenuPrincipal extends JFrame {
    /**
     * Constructora de la classe.
     */
    public VistaMenuPrincipal() {
        setSize(500,300);
        setLocationRelativeTo(null);
        setResizable(false);
        setTitle("Gestor de Teclats PROP");

        JLabel titolVista = new JLabel("GESTOR DE TECLATS");
        titolVista.setFont(titolVista.getFont().deriveFont(Font.BOLD, 16f));
        titolVista.setBounds(165, 20, 300, 30);
        add(titolVista);

        JButton bTeclats = new JButton("Teclats");
        bTeclats.setBounds(65, 80, 150, 30);
        add(bTeclats);

        JButton bTextos = new JButton("Textos");
        bTextos.setBounds(285, 80, 150, 30);
        add(bTextos);

        JButton bLlistes = new JButton("Llistes");
        bLlistes.setBounds(65, 150, 150, 30);
        add(bLlistes);

        JButton bAlfabets = new JButton("Alfabets");
        bAlfabets.setBounds(285, 150, 150, 30);
        add(bAlfabets);

        JButton bSortir = new JButton("Sortir");
        bSortir.setBounds(210, 215, 80, 30);
        add(bSortir);

        JPanel lamina = new JPanel();
        add(lamina);
        setVisible(true);
        setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
        addWindowListener(new WindowEventHandlerImpl());

        ActionListener sortir = e -> {
            try {
                CtrlPresentacio.guardarDades();
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(null, ex.getMessage(), "ERROR", JOptionPane.ERROR_MESSAGE);
            }
            System.exit(0);
        };

        ActionListener llistarTeclats = e -> {
            CtrlPresentacio.vistaElements("Teclats", null);
            setVisible(false);
        };

        ActionListener llistarTextos = e -> {
            CtrlPresentacio.vistaElements("Textos", null);
            setVisible(false);
        };

        ActionListener llistarAlfabets = e -> {
            CtrlPresentacio.vistaElements("Alfabets", null);
            setVisible(false);
        };

        ActionListener llistarLlistes = e -> {
            CtrlPresentacio.vistaElements("Llistes de freqüència", null);
            setVisible(false);
        };

        bTeclats.addActionListener(llistarTeclats);
        bTextos.addActionListener(llistarTextos);
        bAlfabets.addActionListener(llistarAlfabets);
        bLlistes.addActionListener(llistarLlistes);
        bSortir.addActionListener(sortir);
    }
}
