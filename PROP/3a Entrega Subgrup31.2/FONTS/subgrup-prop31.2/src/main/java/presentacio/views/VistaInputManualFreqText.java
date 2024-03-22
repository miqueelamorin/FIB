package presentacio.views;

import presentacio.CtrlPresentacio;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;
import java.net.URL;
import java.util.Objects;

/**
 * Aquesta vista permet crear manualment una llista de frequencia o un text.
 */
public class VistaInputManualFreqText extends JFrame{
    /**
     * Constructora de la classe.
     * @param tipus tipus de l'element a crear (llista de frequencia o text)
     */
    public VistaInputManualFreqText(String tipus){
        setSize(700,500);
        setLocationRelativeTo(null);
        setResizable(false);
        setTitle("Creació " + tipus);

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

        JLabel linst = new JLabel();
        if (Objects.equals(tipus, "Textos")) linst.setText("Escriu el text");
        else linst.setText("Escriu la llista de freqüències en el format 'paraula:frequencia', una per cada línia i sense espais");
        linst.setBounds(20,80,700,20);
        add(linst);

        JTextArea textArea = new JTextArea();
        textArea.setWrapStyleWord(true);
        textArea.setLineWrap(true);
        JPanel laminaArea = new JPanel(new BorderLayout());
        JScrollPane scrollPane = new JScrollPane(textArea);
        laminaArea.add(scrollPane);
        laminaArea.setBounds(20,100,getSize().width-40,300);
        add(laminaArea);

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
                CtrlPresentacio.crearAlfTextLl(nom.getText(), textArea.getText(), true, tipus);
                setVisible(false);
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(null, ex.getMessage(), "ERROR", JOptionPane.ERROR_MESSAGE);
            }
        };

        ActionListener enrere = e -> {
            CtrlPresentacio.vistaElements(tipus, null);
            setVisible(false);
        };

        bCrear.addActionListener(crear);
        bEnrere.addActionListener(enrere);
    }
}
