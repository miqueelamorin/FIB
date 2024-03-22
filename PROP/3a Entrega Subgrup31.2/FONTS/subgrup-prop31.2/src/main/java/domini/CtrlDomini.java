package domini;

import persistencia.CtrlPersistencia;

import java.io.*;
import java.util.*;


/**
 * Classe CtrlDomini
 */
public class CtrlDomini {
    private final CtrlAlfabet CtrlA;
    private final CtrlTeclat CtrlTcl;
    private final CtrlText CtrlTxt;
    private final CtrlParaulesFrequencia CtrlPF;
    private final CtrlParellsLletres CtrlPL;
    private final LectorFitxer lf;

    private final CtrlPersistencia CtrlPers;
    private static CtrlDomini instancia;
    private final GestorDades Datos;

    /**
     * Singleton de la classe
     * @return instancia de CtrlDomini
     * @throws Exception si no existeix instancia
     */
    public static CtrlDomini getInstance() throws Exception {
        if(instancia == null){
            instancia = new CtrlDomini();
        }
        return instancia;
    }

    /**
     * Creadora de la classe
     * @throws Exception si no existeix instancia
     */
    private CtrlDomini() throws Exception {
        CtrlA = CtrlAlfabet.getInstance();
        CtrlTcl = CtrlTeclat.getInstance();
        CtrlTxt = CtrlText.getInstance();
        CtrlPF = CtrlParaulesFrequencia.getInstance();
        CtrlPL = CtrlParellsLletres.getInstance();
        CtrlPers = CtrlPersistencia.getInstance();
        Datos = GestorDades.getInstance();
        lf = LectorFitxer.getInstance();

        DadesDTO dades = CtrlPers.carregarDades();
        Datos.guardarDades(dades);
    }

    /**
     * Guarda les dades
     * @throws IOException si no existeix instancia
     */
    public void guardarDades() throws IOException {
        DadesDTO dades = Datos.carregarDades();
        CtrlPers.guardarDades(dades);
    }

    /**
     * Get dels noms dels alfabets
     * @return retorna un Set amb els noms dels alfabets
     */
    public Set<String> getNomsAlfabet() {
        return Datos.getNomsAlfabet();
    }

    /**
     * Get els caracters de l'alfabet
     * @param nom nom de l'alfabet
     * @return retorna un String amb els caracters de l'alfabet
     * @throws Exception si no existeix instancia
     */
    public String getCaractersAlfabet(String nom) throws Exception {
        boolean exist = Datos.existAlfabet(nom);
        if (!exist) throw new Exception("L'alfabet no existeix");
        Alfabet al = Datos.getAlfabet(nom);
        return al.getCaracters();
    }

    /**
     * Modifier els caracters de l'alfabet
     * @param nom nom de l'alfabet
     * @param caracters caracters de l'alfabet
     * @throws Exception si no existeix instancia
     */
    public void modificarAlfabet(String nom, String caracters) throws Exception {
        boolean exist = Datos.existAlfabet(nom);
        if (!exist) throw new Exception("L'alfabet no existeix");
        Alfabet a = Datos.getAlfabet(nom);
        CtrlA.modificarAlfabet(a, stringToSet(caracters));
        Datos.afegirAlfabet(nom, a);
    }

    /**
     * Afegeix un alfabet
     * @param nom nom de l'alfabet
     * @param alf caracters de l'alfabet
     * @throws Exception si no existeix instancia
     */
    public void afegirAlfabet(String nom, String alf) throws Exception {
        if (Objects.equals(nom, "")) throw new Exception ("S'ha d'introduïr un nom");
        boolean exist = Datos.existAlfabet(nom);
        if (exist) throw new Exception ("L'Alfabet ja Existeix");
        Alfabet al = CtrlA.crearAlfabet(nom, stringToSet(alf));
        Datos.afegirAlfabet(nom, al);
    }

    /**
     * Converteix els caracters de l'alfabet a un Set
     * @param s String a convertir
     * @return Set de caracters
     */
    private Set<Character> stringToSet(String s){
        Set<Character> a = new HashSet<>();
        for(Character c : s.toCharArray()){
            if (c != ' ') a.add(c);
        }
        return a;
    }

    /**
     * Importa un alfabet
     * @param nom nom de l'alfabet
     * @param path path del fitxer a importar
     * @throws Exception si no existeix instancia
     */
    public void afegirAlfabetImportat(String nom, String path) throws Exception {
        String s = lf.importarFitxer(path);
        afegirAlfabet(nom, s);
    }

    /**
     * Elimina un alfabet
     * @param nom nom de l'alfabet
     * @throws Exception si no existeix instancia
     */
    public void eliminarAlfabet(String nom) throws Exception {
        boolean exist = Datos.existAlfabet(nom);
        if (!exist) throw new Exception("L'alfabet no existeix");
        Datos.eliminarAlfabet(nom);
    }

    /**
     * Get dels noms dels teclats
     * @return retorna un Set amb els noms dels teclats
     */
    public Set<String> getNomsTeclat() {
        return Datos.getNomsTeclat();
    }

    /**
     * Get el layout del teclat
     * @param nom nom del teclat
     * @return retorna un String amb el layout del teclat
     * @throws Exception si no existeix instancia
     */
    public char[][] getDistribucioTeclat(String nom) throws Exception {
        boolean exist = Datos.existTeclat(nom);
        if (!exist) throw new Exception("El teclat no existeix");
        Teclat t = Datos.getTeclat(nom);
        return t.getTecles();
    }

    /**
     * Afegir un teclat
     * @param nom nom del teclat
     * @param layout layout del teclat
     * @param nomAlfabet nom de l'alfabet
     * @param nomParaulesFreq nom de la llista de paraules de frequencia
     * @param alg algoritme a utilitzar
     * @throws Exception si no existeix instancia
     */
    public void afegirTeclat(String nom, String layout, String nomAlfabet, String nomParaulesFreq, String alg) throws Exception {
        if (Objects.equals(nom, "")) throw new Exception ("S'ha d'introduïr un nom");
        else if (Objects.equals(nomAlfabet, null)) throw new Exception ("S'ha de seleccionar un Alfabet");
        else if (Objects.equals(nomParaulesFreq, null)) throw new Exception ("S'ha de seleccionar una Llista");

        Pair<Integer, Integer> p = getLayout(layout);
        boolean exist = Datos.existTeclat(nom);
        if (exist) throw new Exception("El teclat ja existeix");
        ParellsLletres pl = getParellLletres(nomAlfabet, nomParaulesFreq);

        CreadorTeclat algoritme;

        if(alg.equals("Branch And Bound")) algoritme = new BranchAndBound();
        else algoritme = new GeneticAlgorithm();

        Teclat t = CtrlTcl.crearTeclat(nom, p.getSecond(), p.getFirst(), pl, algoritme);
        Datos.afegirTeclat(nom, t);
    }

    /**
     * Obtenir el layout del teclat a partir d'un String
     * @param l layout del teclat
     * @return retorna un Pair amb l'amplada i l'altura del layout
     * @throws Exception si no existeix instancia
     */
    public Pair<Integer, Integer> getLayout(String l) throws Exception {
        int amplada;
        int altura;
        try {
            int indexX = l.indexOf("x");
            altura = Integer.parseInt(l.substring(1,indexX));
            amplada = Integer.parseInt(l.substring(indexX+1, l.length()-1));
        }
        catch (Exception e){throw new Exception ("S'ha d'introduïr un Layout");}

        return new Pair<>(altura, amplada);
    }


    /**
     * Modificar un teclat
     * @param nom nom del teclat
     * @param layout layout del teclat
     * @throws Exception si no existeix instancia
     */
    public void modificarTeclat(String nom, String layout) throws Exception {
        if (Objects.equals(nom, "")) throw new Exception ("S'ha d'introduïr un nom");
        Pair<Integer, Integer> p = getLayout(layout);

        boolean exist = Datos.existTeclat(nom);
        if (!exist) throw new Exception("El teclat no existeix");
        Teclat t = Datos.getTeclat(nom);
        CtrlTcl.modificarTeclat(t, p.getSecond(), p.getFirst());
        Datos.afegirTeclat(nom, t);
    }

    /**
     * Canviar dues tecles d'un teclat
     * @param nom nom del teclat
     * @param i1 posicio i de la primera tecla
     * @param j1 posicio j de la primera tecla
     * @param i2 posicio i de la segona tecla
     * @param j2 posicio j de la segona tecla
     * @throws Exception si no existeix instancia
     */
    public void canviarTecles(String nom, int i1, int j1, int i2, int j2) throws Exception {
        boolean exist = Datos.existTeclat(nom);
        if(!exist) throw new Exception("El teclat no existeix");
        Teclat t = Datos.getTeclat(nom);
        Posicio p1 = new Posicio(i1,j1);
        Posicio p2 = new Posicio(i2, j2);
        CtrlTcl.canviarTeclesTeclat(t, p1, p2);
        Datos.afegirTeclat(nom, t);
    }

    /**
     * Eliminar un teclat
     * @param nom nom del teclat
     * @throws Exception si no existeix instancia
     */
    public void eliminarTeclat(String nom) throws Exception {
        boolean exist = Datos.existTeclat(nom);
        if (!exist) throw new Exception("El teclat no existeix");
        Datos.eliminarTeclat(nom);
    }


    /**
     * Get d'un text
     * @param nom nom del text
     * @return retorna un Text
     * @throws Exception si no existeix instancia
     */
    public Text getText(String nom) throws Exception {
        boolean exist = Datos.existText(nom);
        if (!exist) throw new Exception("El text no existeix");
        return Datos.getText(nom);
    }

    /**
     * Get dels noms dels textos
     * @return retorna un Set amb els noms dels textos
     */
    public Set<String> getNomsText() {
        return Datos.getNomsText();
    }

    /**
     * Get el contingut d'un text
     * @param nom nom del text
     * @return retorna el contingut del text
     * @throws Exception si no existeix instancia
     */
    public String getContingutText(String nom) throws Exception {
        boolean exist = Datos.existText(nom);
        if (!exist) throw new Exception("El text no existeix");
        Text t = Datos.getText(nom);
        return t.getContingut();
    }

    /**
     * Modificar el contingut d'un text
     * @param nom nom del text
     * @param text contingut del text
     * @throws Exception si no existeix instancia
     */
    public void modificarText(String nom, String text) throws Exception {
        boolean exist = Datos.existText(nom);
        if (!exist) throw new Exception("El text no existeix");
        Text t = Datos.getText(nom);
        CtrlTxt.modificarText(t, text);
        Datos.afegirText(nom, t);
    }

    /**
     * Importar un text
     * @param nom nom del text
     * @param path path del fitxer a importar
     * @throws Exception si no existeix instancia
     */
    public void afegirTextImportat(String nom, String path) throws Exception {
        if (Objects.equals(nom, "")) throw new Exception("S'ha d'introduïr un nom");
        String s = lf.importarFitxer(path);
        afegirText(nom, s);
    }

    /**
     * Afegir un text
     * @param nom nom del text
     * @param contingut contingut del text
     * @throws Exception si no existeix instancia
     */
    public void afegirText(String nom, String contingut) throws Exception{
        if (Objects.equals(nom, "")) throw new Exception("S'ha d'introduïr un nom");
        boolean exist = Datos.existText(nom);
        if (exist) throw new Exception("El text ja existeix");
        Text t = CtrlTxt.crearText(nom, contingut);
        Datos.afegirText(nom, t);
    }

    /**
     * Eliminar un text
     * @param nom nom del text
     * @throws Exception si no existeix instancia
     */
    public void eliminarText(String nom) throws Exception {
        if (Objects.equals(nom, "")) throw new Exception("S'ha d'introduïr un nom");
        boolean exist = Datos.existText(nom);
        if (!exist) throw new Exception("El text no existeix");
        Datos.eliminarText(nom);
    }

    /**
     * Get d'una llista de paraules de frequencia
     * @param nom nom de la llista de paraules de frequencia
     * @return retorna un ParaulesFrequencia
     * @throws Exception si no existeix instancia
     */
    public ParaulesFrequencia getParaulesFrequencia(String nom) throws Exception {
        boolean exist = Datos.existParaulesFrequencies(nom);
        if (!exist) throw new Exception("La llista no existeix");
        return Datos.getParaulesFrequencia(nom);
    }

    /**
     * Get dels noms de les llistes de paraules de frequencia
     * @return retorna un Set amb els noms de les llistes de paraules de frequencia
     */
    public Set<String> getNomsParaulesFrequencia() {
        return Datos.getNomsParaulesFrequencia();
    }

    /**
     * Modificar una llista de paraules de frequencia
     * @param nom nom de la llista de paraules de frequencia
     * @param llista llista de paraules de frequencia
     * @throws Exception si no existeix instancia
     */
    public void modificarParaulesFrequencia(String nom, String llista) throws Exception {
        if (Objects.equals(nom, "")) throw new Exception("S'ha d'introduïr un nom");
        boolean exist = Datos.existParaulesFrequencies(nom);
        if (!exist) throw new Exception("La llista no existeix");
        ParaulesFrequencia p = Datos.getParaulesFrequencia(nom);
        CtrlPF.modificarParaulesFrequencies(p, llista);
        Datos.modificaParaulesFrequencia(p);
    }

    /**
     * Crear una llista de paraules de frequencia amb textos
     * @param nom nom de la llista de paraules de frequencia
     * @param noms_t noms dels textos
     * @throws Exception si no existeix instancia
     */
    public void afegirParaulesFrequenciaTextos(String nom, Set<String> noms_t) throws Exception {
        if (Objects.equals(nom, "")) throw new Exception("S'ha d'introduïr un nom");
        boolean exist = Datos.existParaulesFrequencies(nom);
        if (exist) throw new Exception("La llista ja existeix");

        Set<Text> textos = new HashSet<>();
        for (String n : noms_t) {
            textos.add(Datos.getText(n));
        }
        ParaulesFrequencia pf = CtrlPF.crearParaulesFrequenciaText(nom, textos);
        Datos.afegirParaulesFrequencia(pf);
    }

    /**
     * Afegir un text a una llista de paraules de frequencia
     * @param nomLlista nom de la llista de paraules de frequencia
     * @param nomText nom del text
     * @throws Exception si no existeix instancia
     */
    public void afegirTextALlista(String nomLlista, String nomText) throws Exception {
        if (Objects.equals(nomLlista, "") || Objects.equals(nomText,"")) throw new Exception("S'ha d'introduïr un nom");
        ParaulesFrequencia p = CtrlPF.afegirTextALlista(getParaulesFrequencia(nomLlista), getText(nomText));
        Datos.modificaParaulesFrequencia(p);
    }

    /**
     * Get els noms dels textos que es poden afegir a una llista de paraules de frequencia
     * @param nomLl nom de la llista de paraules de frequencia
     * @return retorna un Set amb els noms dels textos que es poden afegir a la llista
     * @throws Exception si no existeix instancia
     */
    public Set<String> getTextosPerAfegir(String nomLl) throws Exception {
        if (Objects.equals(nomLl, "")) throw new Exception("S'ha d'introduïr un nom");
        Set<String> tTotal = Datos.getNomsText();
        Set<String> tTotalcp = new HashSet<>(tTotal);
        Set<Text> tLlista = Datos.getParaulesFrequencia(nomLl).getTextos();
        Set<String> ntLlista = new HashSet<>();
        if (!tLlista.isEmpty()){
            for (Text t : tLlista) ntLlista.add(t.getNom());
            tTotalcp.removeAll(ntLlista);
        }
        return tTotalcp;
    }

    /**
     * Eliminar un text d'una llista de paraules de frequencia
     * @param nomLlista nom de la llista de paraules de frequencia
     * @param nomText nom del text
     * @throws Exception si no existeix instancia
     */
    public void eliminarTextLlista(String nomLlista, String nomText) throws Exception {
        if (Objects.equals(nomLlista, "") || Objects.equals(nomText,"")) throw new Exception("S'ha d'introduïr un nom");
        ParaulesFrequencia p = CtrlPF.eliminarTextDeLlista(getParaulesFrequencia(nomLlista), getText(nomText));
        Datos.modificaParaulesFrequencia(p);
    }

    /**
     * Afegir una llista de paraules de frequencia
     * @param nom nom de la llista de paraules de frequencia
     * @param llista llista de paraules de frequencia
     * @throws Exception si no existeix instancia
     */
    public void afegirParaulesFrequencia(String nom, String llista) throws Exception {
        if (Objects.equals(nom, "")) throw new Exception("S'ha d'introduïr un nom");
        boolean exist = Datos.existParaulesFrequencies(nom);
        if (exist) throw new Exception("La llista ja existeix");
        if (llista.isEmpty()) throw new Exception("La llista no pot estar buida");

        ParaulesFrequencia pf = CtrlPF.crearParaulesFrequencia(nom, llista);
        Datos.afegirParaulesFrequencia(pf);
    }

    /**
     * Importar una llista de paraules de frequencia
     * @param nom nom de la llista de paraules de frequencia
     * @param path path del fitxer a importar
     * @throws Exception si no existeix instancia
     */
    public void afegirParaulesFrequenciaImportat(String nom, String path) throws Exception{
        if (Objects.equals(nom, "")) throw new Exception("S'ha d'introduïr un nom");
        String s = lf.importarFitxer(path);
        afegirParaulesFrequencia(nom, s);
    }

    /**
     * Eliminar una llista de paraules de frequencia
     * @param nom nom de la llista de paraules de frequencia
     * @throws Exception si no existeix instancia
     */
    public void eliminarParaulesFrequencia(String nom) throws Exception {
        boolean exist = Datos.existParaulesFrequencies(nom);
        if (!exist) throw new Exception("La llista no existeix");
        Datos.eliminarParaulesFrequencia(nom);
    }


    /**
     * Get d'un ParellsLletres
     * @param nomAlfabet nom de l'alfabet
     * @param nomLlista nom de la llista de paraules de frequencia
     * @return retorna un ParellsLletres
     */
    public ParellsLletres getParellLletres(String nomAlfabet, String nomLlista) {
        boolean exist = Datos.existParellsLletres(nomAlfabet, nomLlista);
        if (exist) return Datos.getParellLletres(nomAlfabet, nomLlista);

        Alfabet al = Datos.getAlfabet(nomAlfabet);
        ParaulesFrequencia pf = Datos.getParaulesFrequencia(nomLlista);
        ParellsLletres pl = CtrlPL.crearParellLletres(al, pf);
        Datos.afegirParellLletres(nomAlfabet, nomLlista, pl);
        return pl;
    }

    /**
     * Calcula els layouts possibles d'un alfabet
     * @param nom_a nom de l'alfabet
     * @param caracters caracters de l'alfabet
     * @return retorna un ArrayList de Pair amb els layouts possibles
     * @throws Exception si no existeix instancia
     */
    public ArrayList<Pair<Integer, Integer>> calculaLayouts(String nom_a, String caracters) throws Exception {
        ArrayList<Pair<Integer, Integer>> layouts = new ArrayList<>();
        int size;
        if (caracters == null) size = getCaractersAlfabet(nom_a).length();
        else size = caracters.length();
        for (int i = 1; i <= size; ++i){
            if (size % i == 0) {
                layouts.add(new Pair<>(i, size/i));
            }
        }
        return layouts;
    }
}