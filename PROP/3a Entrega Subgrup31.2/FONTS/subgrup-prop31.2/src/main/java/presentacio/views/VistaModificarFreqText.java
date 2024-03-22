package presentacio.views;

import presentacio.CtrlPresentacio;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;
import java.net.URL;
import java.util.Objects;

/**
 * Aquesta vista permet modificar una llista de frequencia o un text.
 */
public class VistaModificarFreqText extends JFrame{
    /**
     * Constructora de la classe.
     * @param nom nom de l'element a modificar
     * @param tipus tipus de l'element a modificar (llista de frequencia o text)
     * @param dades dades de l'element a modificar
     */
    public VistaModificarFreqText(String nom, String tipus, String dades){
        setSize(700,500);
        setLocationRelativeTo(null);
        setResizable(false);
        setTitle("Modifica " + nom);

        ImageIcon arrow = null;
        URL imgURL = VistaTeclats.class.getClassLoader().getResource("arrow.png");
        if(imgURL != null) arrow = new ImageIcon(imgURL);
        else JOptionPane.showMessageDialog(this, "Icon image not found.");

        JLabel linst = new JLabel();
        if (Objects.equals(tipus, "Textos")) linst.setText("Escriu el text");
        else linst.setText("Escriu la llista de freqüències en el format 'paraula:frequencia', una per cada línia i sense espais");
        linst.setBounds(20,50,700,20);
        add(linst);

        JTextArea textArea = new JTextArea(dades);
        textArea.setWrapStyleWord(true);
        textArea.setLineWrap(true);
        JPanel laminaArea = new JPanel(new BorderLayout());
        JScrollPane scrollPane = new JScrollPane(textArea);
        laminaArea.add(scrollPane);
        laminaArea.setBounds(20,80,getSize().width-40,getSize().height-220);
        add(laminaArea);

        JButton bModificar = new JButton("Modificar");
        bModificar.setBounds(getSize().width-120, getSize().height-75, 100, 30);
        add(bModificar);

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
                CtrlPresentacio.modificarAlfTextLl(nom, textArea.getText(), tipus);
                setVisible(false);
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(null, ex.getMessage(), "ERROR", JOptionPane.ERROR_MESSAGE);
            }
        };

        ActionListener enrere = e -> {
            try {
                CtrlPresentacio.vistaElements(tipus, nom);
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(null, ex.getMessage(), "ERROR", JOptionPane.ERROR_MESSAGE);
                CtrlPresentacio.vistaElements(tipus, nom);
            }
            setVisible(false);
        };

        bModificar.addActionListener(crear);
        bEnrere.addActionListener(enrere);
    }
}
