package presentacio.views;

import presentacio.CtrlPresentacio;

import javax.swing.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

/**
 * Aquesta classe implementa un WindowAdapter i s'encarrega de guardar les dades quan es tanca la finestra.
 */
public class WindowEventHandlerImpl extends WindowAdapter {

    /**
     * Guarda les dades i tanca el programa.
     * @param evt Event que s'ha produït.
     */
    public void windowClosing(WindowEvent evt) {
        try {
            String[] botons = {"Sí", "No"};
            int opcio = JOptionPane.showOptionDialog(null, "Vols sortir?", "Sortir", JOptionPane.DEFAULT_OPTION, JOptionPane.QUESTION_MESSAGE, null, botons, botons[0]);
            if (opcio == 0){
                CtrlPresentacio.guardarDades();
                System.exit(0);
            }
            else CtrlPresentacio.iniPresentacio();
        } catch (Exception ex) {
            JOptionPane.showMessageDialog(null, ex.getMessage(), "ERROR", JOptionPane.ERROR_MESSAGE);
        }
    }
}
