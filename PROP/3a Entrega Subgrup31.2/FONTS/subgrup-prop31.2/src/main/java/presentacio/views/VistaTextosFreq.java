package presentacio.views;

import presentacio.CtrlPresentacio;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;
import java.net.URL;
import java.util.Objects;


/**
 * Aquesta vista permet veure els textos i llistes de freqüència disponibles, crear-ne de noves i seleccionar-ne una.
 */
public class VistaTextosFreq extends JFrame {
    /**
     * Area de text
     */
    private JTextArea textArea;
    /**
     * Lamina de la vista
     */
    private final JPanel lamina = new JPanel();
    /**
     * Llista de textos o llistes de frequencia
     */
    private JPanel laminaArea;
    /**
     * Botons de modificar
     */
    private final JButton bModificar = new JButton("Modificar");
    /**
     * Botons d'eliminar
     */
    private final JButton bEliminar = new JButton("Eliminar");

    /**
     * Constructora de la classe.
     * @param tipus tipus de l'element (textos o llistes de frequencia)
     * @param dades llista de textos o llistes de frequencia
     * @param seleccionat element seleccionat anteriorment
     */
    public VistaTextosFreq(String tipus, String[] dades, String seleccionat){
        setSize(700,500);
        setLocationRelativeTo(null);
        setResizable(false);
        setTitle(tipus);

        ImageIcon arrow = null;
        URL imgURL = VistaTeclats.class.getClassLoader().getResource("arrow.png");
        if(imgURL != null) arrow = new ImageIcon(imgURL);
        else JOptionPane.showMessageDialog(this, "Icon image not found.");

        ImageIcon add = null;
        imgURL = VistaTeclats.class.getClassLoader().getResource("+.png");
        if(imgURL != null) add = new ImageIcon(imgURL);
        else JOptionPane.showMessageDialog(this, "Icon image not found.");

        JComboBox<String> llista = new JComboBox<>(dades);
        llista.setBounds(20,50,150,40);
        llista.setSelectedItem(seleccionat);
        add(llista);

        bModificar.setBounds(getSize().width-120, getSize().height-75, 100, 30);

        JButton bEnrere = new JButton(arrow);
        bEnrere.setBounds(10,10, 30,30);
        add(bEnrere);

        bEliminar.setBounds(getSize().width-230, getSize().height-75, 100, 30);

        JButton bCrear = new JButton(add);
        bCrear.setBounds(180, 55, 30, 30);
        add(bCrear);

        mostrar(seleccionat, tipus, true);

        setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
        addWindowListener(new WindowEventHandlerImpl());

        ActionListener crear = e -> {
            try {
                Object[] a;
                if (Objects.equals(tipus, "Llistes de freqüència")) a = new Object[]{"Manualment", "Importar", "Textos"};
                else a = new Object[]{"Manualment", "Importar"};
                int sel  = JOptionPane.showOptionDialog(
                        null,
                        "Selecciona una opció",
                        "Crear " + tipus,
                        JOptionPane.YES_NO_OPTION,
                        JOptionPane.QUESTION_MESSAGE,
                        null,
                        a,
                        null);
                CtrlPresentacio.vistaCrearTextosFreq(sel, tipus, (String) llista.getSelectedItem());
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

        ActionListener seleccionar = e ->{
            String elem = (String) llista.getSelectedItem();
            mostrar(elem, tipus, false);
        };

        ActionListener modificar = e -> {
            String elem = (String) llista.getSelectedItem();
            try {

                if (Objects.equals(tipus, "Llistes de freqüència")) {
                    int sel = JOptionPane.showOptionDialog(
                            null,
                            "Selecciona una opció",
                            "Modificar " + tipus,
                            JOptionPane.DEFAULT_OPTION,
                            JOptionPane.QUESTION_MESSAGE,
                            null,
                            new Object[]{"Eliminar Text", "Afegir Text", "Editar Llista"},
                            null);
                    CtrlPresentacio.vistaEditarFreq(elem, sel, (String) llista.getSelectedItem());
                }
                else CtrlPresentacio.modificarTextos(elem);
                setVisible(false);
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(null, ex.getMessage(), "ERROR", JOptionPane.ERROR_MESSAGE);
                CtrlPresentacio.vistaElements("Llistes de freqüència", elem);
            }
            setVisible(false);
        };

        ActionListener eliminar = e ->{
            String elem = (String) llista.getSelectedItem();
            int a = JOptionPane.showConfirmDialog(null, "Vols eliminar " + elem + "?", "Eliminació", JOptionPane.YES_NO_OPTION);
            if (a == JOptionPane.YES_OPTION) {
                try {
                    CtrlPresentacio.eliminarElement(elem, tipus);
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
     * Mostra el contingut del text o llista de freqüències seleccionat
     * @param nom  nom de l'element seleccionat
     * @param first indica si és la primera vegada que es crida a la funció
     */
    private void mostrar(String nom, String tipus, boolean first){
        try {
            if (!first){
                remove(laminaArea);
                remove(textArea);
            }
            if (nom == null){
                textArea = new JTextArea();
                bModificar.setEnabled(false);
                bEliminar.setEnabled(false);
            }
            else {
                String cont = CtrlPresentacio.getTextosFreq(nom, tipus);
                textArea = new JTextArea(cont);
                bModificar.setEnabled(true);
                bEliminar.setEnabled(true);
            }
            textArea.setEditable(false);
            textArea.setWrapStyleWord(true);
            textArea.setLineWrap(true);
            laminaArea = new JPanel(new BorderLayout());
            JScrollPane scrollPane = new JScrollPane(textArea);
            laminaArea.add(scrollPane);
            laminaArea.setBounds(20,100,getSize().width-40,300);
            add(laminaArea);
            add(bEliminar);
            add(bModificar);
            add(lamina);
            setVisible(true);
        } catch (Exception ex) {
            JOptionPane.showMessageDialog(null, ex.getMessage(), "ERROR", JOptionPane.ERROR_MESSAGE);
        }
    }
}
