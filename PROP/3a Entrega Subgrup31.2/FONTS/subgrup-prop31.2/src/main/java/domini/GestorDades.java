package domini;

import java.util.HashMap;
import java.util.Map;
import java.util.Set;

/**
 * Classe que gestiona les dades relacionades amb els teclats, alfabets, paraules de freqüència, parells de lletres i textos.
 */
public class GestorDades {

    /**
     * Instància única del GestorDades (patró Singleton).
     */
    private static GestorDades instancia;

    /**
     * Mapa que emmagatzema els teclats.
     */
    Map<String, Teclat> teclats;

    /**
     * Mapa que emmagatzema les paraules de freqüència.
     */
    Map<String, ParaulesFrequencia> paraulesFreq;

    /**
     * Mapa que emmagatzema els alfabets.
     */
    Map<String, Alfabet> alfabets;

    /**
     * Mapa que emmagatzema els parells de lletres.
     */
    Map<Pair<String,String>, ParellsLletres> parells;

    /**
     * Mapa que emmagatzema els textos.
     */
    Map<String, Text> textos;

    /**
     * Mètode per obtenir l'única instància del GestorDades (Singleton).
     *
     * @return Instància única del GestorDades.
     * @throws Exception Si hi ha problemes en crear la instància.
     */
    public static GestorDades getInstance() throws Exception {
        if(instancia == null){
            instancia = new GestorDades();
        }
        return instancia;
    }

    /**
     * Constructor privat del GestorDades. Inicialitza els mapes i crida als mètodes d'inicialització.
     */
    private GestorDades() {
        textos = new HashMap<>();
        alfabets = new HashMap<>();
        teclats = new HashMap<>();
        paraulesFreq = new HashMap<>();
        parells = new HashMap<>();
    }

    /**
     * Guarda les dades de l'aplicació en una instància de DadesDTO.
     *
     * @param info Instància de DadesDTO per emmagatzemar les dades.
     */
    public void guardarDades(DadesDTO info) {
        alfabets = info.getAlfabets();
        paraulesFreq = info.getParaulesFrequencia();
        textos = info.getTextos();
        teclats = info.getTeclats();
        parells = info.getParellsLletres();
    }

    /**
     * Carrega les dades de l'aplicació des d'una instància de DadesDTO.
     *
     * @return Instància de DadesDTO amb les dades carregades.
     */
    public DadesDTO carregarDades() {
        DadesDTO info = new DadesDTO();
        info.setAlfabets(alfabets);
        info.setParaulesFrequencia(paraulesFreq);
        info.setParellsLletres(parells);
        info.setTeclats(teclats);
        info.setTextos(textos);
        return info;
    }

    /**
     * Comprova si existeix un alfabet amb el nom donat.
     *
     * @param nom Nom de l'alfabet a comprovar.
     * @return Cert si l'alfabet existeix, fals altrament.
     */
    public boolean existAlfabet(String nom) {
        return alfabets.containsKey(nom);
    }

    /**
     * Obté un alfabet amb el nom donat.
     *
     * @param nom Nom de l'alfabet a obtenir.
     * @return Alfabet corresponent al nom donat.
     */
    public Alfabet getAlfabet(String nom) {
        return alfabets.get(nom);
    }

    /**
     * Obté els noms de tots els alfabets emmagatzemats.
     *
     * @return Conjunt de noms d'alfabets.
     */
    public Set<String> getNomsAlfabet(){
        return alfabets.keySet();
    }

    /**
     * Afegeix un alfabet amb el nom i l'alfabet donats.
     *
     * @param nom Nom de l'alfabet a afegir.
     * @param al Alfabet a afegir.
     */
    public void afegirAlfabet(String nom, Alfabet al) {
        alfabets.put(nom, al);
    }

    /**
     * Elimina un alfabet amb el nom donat.
     *
     * @param nom Nom de l'alfabet a eliminar.
     */
    public void eliminarAlfabet(String nom) {
        alfabets.remove(nom);
    }

    // Altres mètodes per a altres tipus de dades (textos, paraulesFreq, parellsLletres, teclats)...

    /**
     * Comprova si existeix un teclat amb el nom donat.
     *
     * @param nom Nom del teclat a comprovar.
     * @return Cert si el teclat existeix, fals altrament.
     */
    public boolean existTeclat(String nom) {
        return teclats.containsKey(nom);
    }

    /**
     * Obté un teclat amb el nom donat.
     *
     * @param nom Nom del teclat a obtenir.
     * @return Teclat corresponent al nom donat.
     */
    public Teclat getTeclat(String nom) {
        return teclats.get(nom);
    }

    /**
     * Obté els noms de tots els teclats emmagatzemats.
     *
     * @return Conjunt de noms de teclats.
     */
    public Set<String> getNomsTeclat(){
        return teclats.keySet();
    }

    /**
     * Afegeix un teclat amb el nom i el teclat donats.
     *
     * @param nom Nom del teclat a afegir.
     * @param t Teclat a afegir.
     */
    public void afegirTeclat(String nom, Teclat t) {
        teclats.put(nom, t);
    }

    /**
     * Elimina un teclat amb el nom donat.
     *
     * @param nom Nom del teclat a eliminar.
     */
    public void eliminarTeclat(String nom) {
        teclats.remove(nom);
    }

    /**
     * Comprova si existeix un text amb el nom donat.
     *
     * @param nom Nom del text a comprovar.
     * @return Cert si el text existeix, fals altrament.
     */
    public boolean existText(String nom) {
        return textos.containsKey(nom);
    }

    /**
     * Obté un text amb el nom donat.
     *
     * @param nom Nom del text a obtenir.
     * @return Text corresponent al nom donat.
     */
    public Text getText(String nom){
        return textos.get(nom);
    }

    /**
     * Obté els noms de tots els textos emmagatzemats.
     *
     * @return Conjunt de noms de textos.
     */
    public Set<String> getNomsText(){
        return textos.keySet();
    }

    /**
     * Afegeix un text amb el nom i el text donats.
     *
     * @param nom Nom del text a afegir.
     * @param t Text a afegir.
     */
    public void afegirText(String nom, Text t) {
        textos.put(nom, t);
    }

    /**
     * Elimina un text amb el nom donat.
     *
     * @param nom Nom del text a eliminar.
     */
    public void eliminarText(String nom){
        textos.remove(nom);
    }

    /**
     * Comprova si existeixen parells de lletres amb els noms d'alfabet i llista donats.
     *
     * @param nomAlfabet Nom de l'alfabet del parell.
     * @param nomLlista Nom de la llista del parell.
     * @return Cert si el parell de lletres existeix, fals altrament.
     */
    public boolean existParellsLletres(String nomAlfabet, String nomLlista) {
        Pair<String, String> clau = new Pair<>(nomAlfabet, nomLlista);
        return parells.containsKey(clau);
    }

    /**
     * Obté un parell de lletres amb els noms d'alfabet i llista donats.
     *
     * @param nomAlfabet Nom de l'alfabet del parell.
     * @param nomLlista Nom de la llista del parell.
     * @return Parell de lletres corresponent als noms donats.
     */
    public ParellsLletres getParellLletres(String nomAlfabet, String nomLlista) {
        Pair<String, String> clau = new Pair<>(nomAlfabet, nomLlista);
        return parells.get(clau);
    }

    /**
     * Afegeix un parell de lletres amb els noms d'alfabet, llista i parell donats.
     *
     * @param nomAlfabet Nom de l'alfabet del parell.
     * @param nomParaulesFreq Nom de la llista del parell.
     * @param pl Parell de lletres a afegir.
     */
    public void afegirParellLletres (String  nomAlfabet, String nomParaulesFreq, ParellsLletres pl) {
        Pair<String, String> clau = new Pair<>(nomAlfabet, nomParaulesFreq);
        parells.put(clau, pl);
    }

    /**
     * Comprova si existeix una llista de paraules de freqüència amb el nom donat.
     *
     * @param nom Nom de la llista de paraules de freqüència a comprovar.
     * @return Cert si la llista de paraules de freqüència existeix, fals altrament.
     */
    public boolean existParaulesFrequencies(String nom) {
        return paraulesFreq.containsKey(nom);
    }

    /**
     * Obté una llista de paraules de freqüència amb el nom donat.
     *
     * @param nom Nom de la llista de paraules de freqüència a obtenir.
     * @return Llista de paraules de freqüència corresponent al nom donat.
     */
    public ParaulesFrequencia getParaulesFrequencia(String nom) {
        return paraulesFreq.get(nom);
    }

    /**
     * Obté els noms de totes les llistes de paraules de freqüència emmagatzemades.
     *
     * @return Conjunt de noms de llistes de paraules de freqüència.
     */
    public Set<String> getNomsParaulesFrequencia(){
        return paraulesFreq.keySet();
    }

    /**
     * Afegeix una llista de paraules de freqüència amb el nom i la llista donats.
     *
     * @param pf Llista de paraules de freqüència a afegir.
     * @throws Exception Si la llista ja existeix.
     */
    public void afegirParaulesFrequencia(ParaulesFrequencia pf) throws Exception {
        if (paraulesFreq.containsKey(pf.getNom())) throw new Exception("La llista ja existeix");
        paraulesFreq.put(pf.getNom(), pf);
    }

    /**
     * Modifica una llista de paraules de freqüència amb la llista donada.
     *
     * @param pf Llista de paraules de freqüència a modificar.
     */
    public void modificaParaulesFrequencia(ParaulesFrequencia pf){
        paraulesFreq.put(pf.getNom(), pf);
    }

    /**
     * Elimina una llista de paraules de freqüència amb el nom donat.
     *
     * @param nom Nom de la llista de paraules de freqüència a eliminar.
     * @throws Exception Si la llista no existeix.
     */
    public void eliminarParaulesFrequencia(String nom) throws Exception {
        if (!paraulesFreq.containsKey(nom)) throw new Exception("La llista no existeix");
        paraulesFreq.remove(nom);
    }
}

