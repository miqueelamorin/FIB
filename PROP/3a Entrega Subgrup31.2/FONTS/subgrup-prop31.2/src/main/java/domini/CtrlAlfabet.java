package domini;


import java.util.Set;

/**
 * Aquesta Classe representa un controlador d'alfabets
 */
public class CtrlAlfabet {
    private static CtrlAlfabet instancia;

    /**
     * Singleton de CtrlAlfabet
     * @return Instància del controlador
     */
    public static CtrlAlfabet getInstance(){
        if(instancia == null){
            instancia = new CtrlAlfabet();
        }
        return instancia;
    }

    /**
     * Constructora de CtrlAlfabet
     */
    private CtrlAlfabet(){}

    /**
     * Crea un alfabet
     * @param nom Nom de l'alfabet
     * @param alf Conjunt de caràcters de l'alfabet
     * @return Objecte de la classe Alfabet
     * @throws Exception En cas de que el conjunt de caràcters no sigui correcte
     */
    public Alfabet crearAlfabet(String nom, Set<Character> alf) throws Exception {
        return new Alfabet(nom, alf);
    }


    /**
     * Modifica el contingut d'un alfabet
     * @param a Alfabet a modificar
     * @param chars Conjunt de caràcters que formen l'alfabet
     * @throws Exception Si el conjunt de caràcters és buit
     */
    public void modificarAlfabet(Alfabet a, Set<Character> chars) throws Exception {
        a.setCaracters(chars);
    }
}