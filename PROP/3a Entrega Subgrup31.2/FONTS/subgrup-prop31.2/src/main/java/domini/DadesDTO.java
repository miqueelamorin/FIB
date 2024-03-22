package domini;
import java.io.Serializable;
import java.util.*;

/**
 * Classe que representa un objecte de transferència de dades (DTO).
 * Conté diferents mapes per emmagatzemar alfabets, paraules de freqüència, textos, teclats i parells de lletres.
 */
public class DadesDTO implements Serializable {

    /**
     * Mapa que emmagatzema els alfabets.
     */
    private Map<String, Alfabet> alfabets;

    /**
     * Mapa que emmagatzema les paraules de freqüència.
     */
    private Map<String, ParaulesFrequencia> paraulesFrequencia;

    /**
     * Mapa que emmagatzema els textos.
     */
    private Map<String, Text> textos;

    /**
     * Mapa que emmagatzema els teclats.
     */
    private Map<String, Teclat> teclats;

    /**
     * Mapa que emmagatzema els parells de lletres.
     */
    private Map<Pair<String, String>, ParellsLletres> parellsLletres;

    /**
     * Constructor que inicialitza els mapes.
     */
    public DadesDTO(){
        alfabets = new HashMap<>();
        paraulesFrequencia = new HashMap<>();
        textos = new HashMap<>();
        teclats = new HashMap<>();
        parellsLletres = new HashMap<>();
    }

    /**
     * Obté el mapa d'alfabets.
     *
     * @return Mapa d'alfabets.
     */
    public Map<String, Alfabet> getAlfabets() {
        return alfabets;
    }

    /**
     * Estableix el mapa d'alfabets.
     *
     * @param alfabets Nou mapa d'alfabets.
     */
    public void setAlfabets(Map<String, Alfabet> alfabets) {
        this.alfabets = alfabets;
    }

    /**
     * Obté el mapa de paraules de freqüència.
     *
     * @return Mapa de paraules de freqüència.
     */
    public Map<String, ParaulesFrequencia> getParaulesFrequencia() {
        return paraulesFrequencia;
    }

    /**
     * Estableix el mapa de paraules de freqüència.
     *
     * @param paraulesFrequencia Nou mapa de paraules de freqüència.
     */
    public void setParaulesFrequencia(Map<String, ParaulesFrequencia> paraulesFrequencia) {
        this.paraulesFrequencia = paraulesFrequencia;
    }

    /**
     * Obté el mapa de textos.
     *
     * @return Mapa de textos.
     */
    public Map<String, Text> getTextos() {
        return textos;
    }

    /**
     * Estableix el mapa de textos.
     *
     * @param textos Nou mapa de textos.
     */
    public void setTextos(Map<String, Text> textos) {
        this.textos = textos;
    }

    /**
     * Obté el mapa de teclats.
     *
     * @return Mapa de teclats.
     */
    public Map<String, Teclat> getTeclats() {
        return teclats;
    }

    /**
     * Estableix el mapa de teclats.
     *
     * @param teclats Nou mapa de teclats.
     */
    public void setTeclats(Map<String, Teclat> teclats) {
        this.teclats = teclats;
    }

    /**
     * Obté el mapa de parells de lletres.
     *
     * @return Mapa de parells de lletres.
     */
    public Map<Pair<String, String>, ParellsLletres> getParellsLletres() {
        return parellsLletres;
    }

    /**
     * Estableix el mapa de parells de lletres.
     *
     * @param parellsLletres Nou mapa de parells de lletres.
     */
    public void setParellsLletres(Map<Pair<String, String>, ParellsLletres> parellsLletres) {
        this.parellsLletres = parellsLletres;
    }
}
