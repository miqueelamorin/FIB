package domini;

/**
 * Aquesta Classe és l'encarregada de gestionar els Textos
 **/
public class CtrlText {
    private static CtrlText instancia;

    /**
     * Singleton de la Classe
     * @return Instancia de la Classe
     */
    public static CtrlText getInstance() {
        if (instancia == null) {
            instancia = new CtrlText();
        }
        return instancia;
    }

    /**
     * Constructora de la Classe
     */
    private CtrlText() {}

    /**
     * Modifica el Contingut del Text
     * @param t Text a modificar
     * @param text Text a afegir
     */
    public void modificarText(Text t, String text) {
        t.setContingut(text);
    }

    /**
     * Crea un Text i el retorna
     * @param nom Nom del Text
     * @param contingut Contingut del Text
     * @return Retorna un Text
     */
    public Text crearText(String nom, String contingut) {
        return new Text(nom, contingut);
    }
}
