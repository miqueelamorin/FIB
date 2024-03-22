package domini;

import java.util.Set;

/**
 * Aquesta classe representa el controlador de la classe ParaulesFrequencia
 */
public class CtrlParaulesFrequencia {
    private static CtrlParaulesFrequencia instancia;

    /**
     * Singleton de la classe CtrlParaulesFrequencia.
     * @return Instancia de la classe CtrlParaulesFrequencia.
     */
    public static CtrlParaulesFrequencia getInstance(){
        if(instancia == null){
            instancia = new CtrlParaulesFrequencia();
        }
        return instancia;
    }

    /**
     * Constructora de la classe CtrlParaulesFrequencia.
     */
    private CtrlParaulesFrequencia(){}

    /**
     * Crea una instancia de la classe ParaulesFrequencia.
     * @param nom Nom de la llista de paraules.
     * @param text Paraules i les seves freqüències.
     * @return Instancia de la classe ParaulesFrequencia.
     * @throws Exception En cas de que el nom de la llista de paraules sigui buit.
     */
    public ParaulesFrequencia crearParaulesFrequencia(String nom, String text) throws Exception {
        return new ParaulesFrequencia(nom, text);
    }

    /**
     * Crea una instancia de la classe ParaulesFrequencia.
     * @param nom Nom de la llista de paraules.
     * @param t Conjunt de textos.
     * @return Instancia de la classe ParaulesFrequencia.
     */
    public ParaulesFrequencia crearParaulesFrequenciaText(String nom, Set<Text> t) {
        return new ParaulesFrequencia(nom, t);
    }

    /**
     * Modifica la llista de paraules.
     * @param p Instancia de la classe ParaulesFrequencia.
     * @param llista Llista de paraules.
     * @throws Exception En cas que la llista de paraules sigui buida.
     */
    public void modificarParaulesFrequencies(ParaulesFrequencia p, String llista) throws Exception {
        p.setLlistaFreq(llista);
    }

    /**
     * Afegeix un text a la llista de paraules.
     * @param p Instancia de la classe ParaulesFrequencia.
     * @param t Instancia de la classe Text.
     * @return Nom de la llista de paraules.
     * @throws Exception En cas que el text ja estigui a la llista de paraules.
     */
    public ParaulesFrequencia afegirTextALlista(ParaulesFrequencia p, Text t) throws Exception {
        p.afegirText(t);
        return p;
    }

    /**
     * Elimina un text de la llista de paraules.
     * @param p Instancia de la classe ParaulesFrequencia.
     * @param t Instancia de la classe Text.
     * @return Nom de la llista de paraules.
     * @throws Exception En cas que el text no estigui a la llista de paraules.
     */
    public ParaulesFrequencia eliminarTextDeLlista(ParaulesFrequencia p, Text t) throws Exception {
        p.eliminaText(t);
        return p;
    }
}
