package presentacio.views;
import domini.Pair;
import presentacio.CtrlPresentacio;

import javax.swing.*;
import javax.swing.filechooser.FileNameExtensionFilter;
import javax.swing.filechooser.FileSystemView;
import java.awt.*;
import java.awt.event.ActionListener;
import java.io.File;
import java.net.URL;

/**
 * Aquesta vista permet importar un alfabet, una llista de frequencia o un text.
 */
public class VistaImportar extends JFrame {
    /**
     * Lamina de la vista.
     */
    private final JPanel lamina = new JPanel();
    /**
     * Camp de text.
     */
    private JTextField textField;
    /**
     * Nom de l'element a importar.
     */
    private JTextField nom;

    /**
     * Constructora de la classe.
     * @param tipus tipus de l'element a importar (alfabet, llista de frequencia o text)
     */
    public VistaImportar(String tipus){
        setSize(500,300);
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

        nom = new JTextField();
        nom.setBounds(230,50,210,20);
        add(nom);

        JButton bImp = new JButton("Seleccionar Fitxer");
        bImp.setBounds(20, 100, 150, 30);
        add(bImp);

        JButton bCrear = new JButton("Crear");
        bCrear.setBounds(getSize().width-120, getSize().height-75, 100, 30);
        add(bCrear);

        JButton bEnrere = new JButton(arrow);
        bEnrere.setBounds(10,10, 30,30);
        add(bEnrere);

        add(lamina);
        setVisible(true);
        setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
        addWindowListener(new WindowEventHandlerImpl());

        ActionListener crear = e -> {
            try {
                CtrlPresentacio.crearAlfTextLl(nom.getText(), textField.getText(), false, tipus);
                setVisible(false);
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(null, ex.getMessage(), "ERROR", JOptionPane.ERROR_MESSAGE);
            }
        };

        ActionListener enrere = e -> {
            CtrlPresentacio.vistaElements(tipus, null);
            setVisible(false);
        };

        ActionListener imp = e-> {
            remove(nom);

            Pair<String, String> p = importar();
            textField = new JTextField(p.getFirst());
            textField.setEditable(false);
            JPanel laminaField = new JPanel(new BorderLayout());
            JScrollPane scrollPane = new JScrollPane(textField);
            laminaField.add(scrollPane);
            laminaField.setBounds(20,140,460,50);

            nom = new JTextField(p.getSecond());
            nom.setBounds(230,50,210,20);
            add(nom);

            add(laminaField);
            add(lamina);
            setVisible(true);
        };

        bImp.addActionListener(imp);
        bCrear.addActionListener(crear);
        bEnrere.addActionListener(enrere);
    }

    private Pair<String, String> importar(){
        JFileChooser chooser = new JFileChooser(FileSystemView.getFileSystemView().getHomeDirectory());
        chooser.setDialogTitle("Selecciona directori");
        chooser.setFileFilter(new FileNameExtensionFilter("fitxers de text", "txt", "rtd"));
        chooser.setAcceptAllFileFilterUsed(false);
        chooser.setCurrentDirectory(new File(System.getProperty("user.dir") + "/data/dades"));
        int returnValue = chooser.showOpenDialog(null);
        String path = null;
        String nom = null;
        if (returnValue == JFileChooser.APPROVE_OPTION) {
            File arxiu = chooser.getSelectedFile();
            path = arxiu.getAbsolutePath();
            nom = arxiu.getName();
        }
        return new Pair<>(path, nom);
    }
}
