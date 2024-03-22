//

package domini;

/**
 * Aquesta Classe és l'encarregada de gestionar els Teclats
 */
public final class CtrlTeclat{
    private static CtrlTeclat instancia;

    /**
     * Singleton de la Classe
     * @return Instancia de la Classe
     */
    public static CtrlTeclat getInstance(){
        if(instancia == null){
            instancia = new CtrlTeclat();
        }
        return instancia;
    }

    /**
     * Constructora de la Classe
     */
    private CtrlTeclat(){}


    /**
     * Crear un Teclat i el retorna
     * @param nom  Nom del Teclat
     * @param amplada Amplada del Teclat
     * @param altura Altura del Teclat
     * @param pl Parells de Lletres del Teclat
     * @param alg Algorisme de Creació del Teclat
     * @return Retorna un Teclat
     * @throws Exception En cas de que hi hagi algun error
     */
    public Teclat crearTeclat(String nom, Integer amplada, Integer altura, ParellsLletres pl, CreadorTeclat alg) throws Exception {
        return new Teclat(nom, amplada, altura, pl, alg);
    }

    /**
     * Modifica el Layout del Teclat
     * @param t Teclat a modificar
     * @param amplada Amplada del Teclat
     * @param altura Altura del Teclat
     * @throws Exception En cas de que hi hagi algun error
     */
    public void modificarTeclat(Teclat t, Integer amplada, Integer altura) throws Exception {
        t.modificarLayoutTeclat(amplada, altura);
    }

    /**
     * Modifica les Tecles del Teclat
     * @param t Teclat a modificar
     * @param p1 Posició 1
     * @param p2 Posició 2
     * @throws Exception En cas de que hi hagi algun error
     */
    public void canviarTeclesTeclat(Teclat t, Posicio p1, Posicio p2) throws Exception {
        t.canviarTeclesTeclat(p1, p2);
    }

}
