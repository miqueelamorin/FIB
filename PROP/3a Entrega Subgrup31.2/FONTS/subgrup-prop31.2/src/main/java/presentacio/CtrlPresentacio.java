package presentacio;
import domini.CtrlDomini;
import domini.Pair;
import domini.Text;
import presentacio.views.*;

import java.util.*;

/**
 * Aquesta Classe és l'encarregada de gestionar la Presentació
 **/
public class CtrlPresentacio {
    private final static CtrlDomini cd;

    static {
        try {
            cd = CtrlDomini.getInstance();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    /**
     * Constructora de la Classe i inicialitza la Vista Principal
     */
    public static void iniPresentacio() {
        new VistaMenuPrincipal();
    }

    /**
     * Carrega la vista de l'Element especificat
     * @param tipus Tipus dels Elements
     * @param seleccio Element seleccionat per mostrar
     */
    public static void vistaElements(String tipus, String seleccio){
        String[] dades;

        if (Objects.equals(tipus, "Teclats")) {
            dades = cd.getNomsTeclat().toArray(new String[0]);
            new VistaTeclats(dades, seleccio);
        }
        else if (Objects.equals(tipus, "Alfabets")) {
            dades = cd.getNomsAlfabet().toArray(new String[0]);
            new VistaAlfabets(dades, seleccio);
        }
        else if (Objects.equals(tipus, "Textos")) {
            dades = cd.getNomsText().toArray(new String[0]);
            new VistaTextosFreq(tipus, dades, seleccio);
        }
        else if (Objects.equals(tipus, "Llistes de freqüència")) {
            dades = cd.getNomsParaulesFrequencia().toArray(new String[0]);
            new VistaTextosFreq(tipus, dades, seleccio);
        }
    }

    /**
     * Obté la llista de frequencies formatejada per mostrar
     * @param nom Nom de la Llista de Frequencia
     * @return Retorna la Llista de Frequencia formatejada per mostrar
     * @throws Exception En cas de que hi hagi algun error
     */
    private static String getStringFrequencies(String nom) throws Exception {
        StringBuilder dades = new StringBuilder();
        Map<String, Integer> a = cd.getParaulesFrequencia(nom).getLlistaFreq();
        for (Map.Entry<String, Integer> e : a.entrySet()) {
            dades.append(e.getKey()).append(":").append(e.getValue()).append("\n");
        }
        return dades.toString();
    }

    /**
     * Obté els layouts possibles del Teclat
     * @param alfabet Alfabet del Teclat a crear o modificar
     * @param caracters Caràcters de l'Alfabet
     * @return Retorna els Layouts possibles del Teclat
     * @throws Exception En cas de que hi hagi algun error
     */
    public static String[] getLayouts(String alfabet, String caracters) throws Exception {
        ArrayList<Pair<Integer, Integer>> l = cd.calculaLayouts(alfabet, caracters);

        String[] layouts = new String[l.size()];
        for (int i = 0; i < layouts.length; ++i){
            Pair<Integer, Integer> p = l.get(i);
            String s = "(" + p.getFirst() + "x" + p.getSecond() + ")";
            layouts[i] = s;
        }
        return layouts;
    }

    /**
     * Crea un Teclat amb els paràmetres especificats
     * @param nom Nom del Teclat
     * @param layout Layout del Teclat
     * @param alfabet Alfabet
     * @param llista Llista de Frequencia
     * @param alg Algorisme de Creació del Teclat
     * @throws Exception En cas de que hi hagi algun error
     */
    public static void crearTeclat(String nom, String alfabet, String llista, String layout, String alg) throws Exception {
        cd.afegirTeclat(nom,layout,alfabet,llista,alg);
        char[][] key = CtrlPresentacio.getTeclat(nom);
        new VistaTeclat(key,nom);
    }

    /**
     * Elimina l'Element especificat
     * @param nom Nom de l'Element
     * @param tipus Tipus de l'Element (Teclats, Alfabets, Textos, Llistes de Frequencia)
     * @throws Exception En cas de que hi hagi algun error
     */
    public static void eliminarElement(String nom, String tipus) throws Exception {
        if (Objects.equals(tipus, "Teclats")) cd.eliminarTeclat(nom);
        else if (Objects.equals(tipus, "Alfabets")) cd.eliminarAlfabet(nom);
        else if (Objects.equals(tipus, "Textos")) cd.eliminarText(nom);
        else if (Objects.equals(tipus, "Llistes de freqüència")) cd.eliminarParaulesFrequencia(nom);
        vistaElements(tipus, null);
    }

    /**
     * Crea un Element (ALfabet, Llista o Text) amb els paràmetres especificats
     * @param nom Nom de l'Element a crear
     * @param tipus Tipus de l'Element (Alfabets, Textos, Llistes de Frequencia)
     * @param cont Contingut de l'Element
     * @param manual Indica si l'Element s'ha creat manualment o importat
     * @throws Exception En cas de que hi hagi algun error
     */
    public static void crearAlfTextLl(String nom, String cont, boolean manual, String tipus) throws Exception {
        if (Objects.equals(tipus, "Alfabets")){
            if (manual) cd.afegirAlfabet(nom, cont);
            else cd.afegirAlfabetImportat(nom, cont);
        }
        else if (Objects.equals(tipus, "Textos")){
            if (manual) cd.afegirText(nom, cont);
            else cd.afegirTextImportat(nom, cont);
        }
        else {
            if (manual) cd.afegirParaulesFrequencia(nom, cont);
            else cd.afegirParaulesFrequenciaImportat(nom, cont);
        }
        vistaElements(tipus, nom);
    }

    /**
     * Crea una Llista de Frequencia a partir dels Textos especificats
     * @param nom Nom de la Llista de Frequencia a crear
     * @param textos Textos per crear la Llista de Frequencia
     * @throws Exception En cas de que hi hagi algun error
     */
    public static void crearAmbTextos(String nom, List<String> textos) throws Exception {
        Set<String> t = new HashSet<>(textos);
        cd.afegirParaulesFrequenciaTextos(nom, t);
        vistaElements("Llistes de freqüència", nom);
    }

    /**
     * Modifica un Element (ALfabet, Llista o Text) amb els paràmetres especificats
     * @param nom Nom de l'Element a modificar
     * @param text Contingut de l'Element
     * @param tipus Tipus de l'Element (Alfabets, Textos, Llistes de Frequencia)
     * @throws Exception En cas de que hi hagi algun error
     */
    public static void modificarAlfTextLl(String nom, String text, String tipus) throws Exception {
        if (Objects.equals(tipus, "Alfabets")) cd.modificarAlfabet(nom, text);
        else if (Objects.equals(tipus, "Textos")) cd.modificarText(nom, text);
        else if (Objects.equals(tipus, "Llistes de freqüència")) cd.modificarParaulesFrequencia(nom, text);
        vistaElements(tipus, nom);
    }

    /**
     * Retorna si l'algorisme és factible o no en termes de lentitud
     * @param alfabet Alfabet del Teclat a crear o modificar
     * @param alg Algorisme de Creació del Teclat
     * @return Retorna si l'algorisme és factible o no en termes de lentitud
     * @throws Exception En cas de que hi hagi algun error
     */
    public static boolean algorimeFactible(String alfabet, String alg) throws Exception {
        if (Objects.equals(alg, "Branch And Bound")){
            String alf = cd.getCaractersAlfabet(alfabet);
            return (alf.length() < 13);
        }
        return true;
    }

    /**
     * Carrega la vista corresponent de modificació del Teclat
     * @param nom Nom del Teclat a modificar
     * @param sel Selecció de la Vista (0: Layout, 1: Tecles, 2: Vista Teclat)
     * @throws Exception En cas de que hi hagi algun error
     */
    public static void modificarTeclat(String nom, int sel) throws Exception {
        char[][] key = getTeclat(nom);

        if (sel == 0) {
            StringBuilder alfabet = new StringBuilder();
            for (char[] c : key) {
                for (char d : c) {
                    alfabet.append(d);
                }
            }
            new VistaModificarTeclatLayout(nom, key, alfabet.toString());
        }
        else if (sel == 1) {
            Character[] alfabet = new Character[key.length*key[0].length];
            int i = 0;
            for (char[] c : key) {
                for (char d : c) {
                    alfabet[i] = d;
                    ++i;
                }
            }
            new VistaModificarTeclatTecles(nom, key, alfabet);
        }
        else new VistaTeclat(key, nom);
    }

    /**
     * Modifica el Layout del Teclat
     * @param nom Nom del Teclat
     * @param layout Nou layout del Teclat
     * @throws Exception En cas de que hi hagi algun error
     */
    public static void modificarTeclatLayout(String nom, String layout) throws Exception {
        cd.modificarTeclat(nom, layout);
        char[][] key = getTeclat(nom);
        new VistaTeclat(key, nom);
    }

    /**
     * Modifica les Tecles del Teclat
     * @param nom Nom del teclat
     * @param l1 caracter de la posició 1
     * @param l2 caracter de la posició 2
     * @param key Teclat
     * @throws Exception En cas de que hi hagi algun error
     */
    public static void modificarTeclatTecles(String nom, char l1, char l2, char[][] key) throws Exception{
        int i1 = 0;
        int j1 = 0;
        int i2 = 0;
        int j2 = 0;

        for (int i = 0; i < key.length; ++i){
            for (int j = 0; j < key[0].length; ++j){
                if (key[i][j] == l1) {
                    i1 = i;
                    j1 = j;
                }
                else if (key[i][j] == l2) {
                    i2 = i;
                    j2 = j;
                }
            }
        }

        cd.canviarTecles(nom, i1, j1, i2, j2);
        new VistaTeclat(getTeclat(nom), nom);
    }

    /**
     * Obté els caràcters de l'Alfabet
     * @param elem Nom de l'Alfabet
     * @return Retorna els caràcters de l'Alfabet
     * @throws Exception En cas de que hi hagi algun error
     */
    public static String getAlfabet(String elem) throws Exception {
        return cd.getCaractersAlfabet(elem);
    }

    /**
     * Modifica l'Alfabet amb els caràcters especificats
     * @param elem Nom de l'Alfabet a modificar
     * @throws Exception En cas de que hi hagi algun error
     */
    public static void modificarAlfabet(String elem) throws Exception {
        String dades = cd.getCaractersAlfabet(elem);
        new VistaModificarAlf(elem, dades);
    }

    /**
     * Carrega la vista corresponent de creació de l'Alfabet
     * @param sel Selecció de la Vista (0: Manual, 1: Importar, 2: Crear amb Textos)
     * @param seleccioprevia Selecció anterior de l'Element
     */
    public static void vistaCrearAlfabet(int sel, String seleccioprevia) {
        if (sel == 0) new VistaInputManualAlf();
        else if (sel == 1) new VistaImportar("Alfabets");
        else vistaElements("Alfabets", seleccioprevia);
    }

    /**
     * Carrega la vista corresponent de creació del Text o de la Llista de Frequencia
     * @param sel Selecció de la Vista (0: Manual, 1: Importar, 2: Crear amb Textos)
     * @param tipus Tipus de l'Element (Textos, Llistes de Frequencia)
     * @param seleccioprevia Selecció anterior de l'Element
     */
    public static void vistaCrearTextosFreq(int sel, String tipus, String seleccioprevia) {
        if (sel == 0) new VistaInputManualFreqText(tipus);
        else if (sel == 1) new VistaImportar(tipus);
        else if (sel == 2){
            String[] dades = cd.getNomsText().toArray(new String[0]);
            new VistaCrearFreqAmbTextos(dades);
        }
        else vistaElements(tipus, seleccioprevia);
    }


    /**
     * Obté els contingut del Text o de la Llista de Frequencia
     * @param elem Nom de l'Element
     * @param tipus Tipus de l'Element (Textos, Llistes de Frequencia)
     * @return Retorna el Contingut de l'Element ja bé sigui un Text o una Llista de Frequencia
     * @throws Exception En cas de que hi hagi algun error
     */
    public static String getTextosFreq(String elem, String tipus) throws Exception {
        if ((Objects.equals(tipus, "Textos"))) return cd.getContingutText(elem);
        else return getStringFrequencies(elem);
    }

    /**
     * Obté el Teclat amb el nom especificat
     * @param elem Nom del Teclat
     * @return Retorna el Teclat amb el nom elem
     * @throws Exception En cas de que hi hagi algun error
     */
    public static char[][] getTeclat(String elem) throws Exception {
        return cd.getDistribucioTeclat(elem);
    }

    /**
     * Carrga la vista corresponent a la modificació del Text
     * @param elem Nom del Text a modificar
     * @throws Exception En cas de que hi hagi algun error
     */
    public static void modificarTextos(String elem) throws Exception {
        String dades = cd.getContingutText(elem);
        new VistaModificarFreqText(elem, "Textos", dades);
    }

    /**
     * Carrega la vista corresponent a la creació del Teclat
     */
    public static void vistaCrearTeclat() {
        String[] llistes = cd.getNomsParaulesFrequencia().toArray(new String[0]);
        String[] alfabets = cd.getNomsAlfabet().toArray(new String[0]);
        new VistaCrearTeclat(llistes, alfabets);
    }

    /**
     * Carrega la vista corresponent a la modificació de la Llista de Frequencia
     * @param elem Nom de l'Element
     * @param sel Selecció de la Vista (0: Eliminar Text, 1: Afegir Text, 2: Editar Llista)
     * @param seleccioanterior Selecció anterior de l'Element
     * @throws Exception En cas de que hi hagi algun error
     */
    public static void vistaEditarFreq(String elem, int sel, String seleccioanterior) throws Exception {
        String[] dades;
        Set<Text> txts = cd.getParaulesFrequencia(elem).getTextos();
        if (sel == 0) {
            if (txts.isEmpty()) throw new Exception("La llista s'ha creat amb manualment, no es pot modificar amb textos");
            Set<String> txtsT = cd.getNomsText();
            dades = new String[txts.size()];
            int i = 0;
            for (Text t : txts){
                if (txtsT.contains(t.getNom())) {
                    dades[i] = t.getNom();
                    ++i;
                }
            }
            new VistaEditarTextosDeFreq(elem, dades, sel);
        }
        else if (sel == 1) {
            if (txts.isEmpty()) throw new Exception("La llista s'ha creat amb manualment, no es pot modificar amb textos");
            dades = cd.getTextosPerAfegir(elem).toArray(new String[0]);
            new VistaEditarTextosDeFreq(elem, dades, sel);
        }
        else if (sel == 2) {
            if (!txts.isEmpty()) throw new Exception("La llista s'ha creat amb textos, no es pot modificar manualment");
            String d = getStringFrequencies(elem);
            new VistaModificarFreqText(elem, "Llistes de freqüència", d);
        }
        else vistaElements("Llistes de freqüència", seleccioanterior);
    }

    /**
     * Modifica els Textos associats a la Llista de Frequencia
     * @param nomLl Nom de la Llista de Frequencia
     * @param nomText Nom del Text
     * @param op Opció de la Vista (0: Eliminar, 1: Afegir)
     * @throws Exception En cas de que hi hagi algun error
     */
    public static void editarTextosDeFrequencia(String nomLl, String nomText, int op) throws Exception {
        if (op == 0) cd.eliminarTextLlista(nomLl, nomText);
        else if (op == 1) cd.afegirTextALlista(nomLl, nomText);
        vistaElements("Llistes de freqüència", nomLl);
    }

    /**
     * Guarda les dades a l'hora de tancar el programa
     * @throws Exception En cas de que hi hagi algun error
     **/
    public static void guardarDades() throws Exception {
        cd.guardarDades();
    }
}

