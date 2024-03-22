package domini;

/**
 * Aquesta Classe és l'encarregada de gestionar un Teclat
 **/
public final class Teclat {

    private char[] tecles;
    private final ParellsLletres parellsLletres;
    private final CreadorTeclat algoritme;
    private int amplada;
    private int altura;

    private final String nom;


    /**
     * Constructora de la Classe
     * @param nom  Nom del Teclat
     * @param amplada Amplada del Teclat
     * @param altura Altura del Teclat
     * @param pl Parells de Lletres del Teclat
     * @param alg Algorisme de Creació del Teclat
     * @throws Exception En cas de que hi hagi algun error
     */
    public Teclat (String nom, Integer amplada, Integer altura, ParellsLletres pl, CreadorTeclat alg) throws Exception {
        this.nom = nom;
        this.algoritme = alg;
        this.amplada = amplada;
        this.altura = altura;
        parellsLletres = pl;
        String caracters = pl.getAlfabet().getCaracters();
        if (amplada*altura != caracters.length()) throw new Exception("El layout no correspon amb el numero de lletres");
        tecles = calculaTecles(amplada, altura, caracters);
    }

    /**
     * Retorna el nom del Teclat
     * @return Nom del Teclat
     */
    public String getNom(){ return nom; }

    /**
     * Calcula la distribució del Teclat
     * @param amplada Amplada del Teclat
     * @param altura Altura del Teclat
     * @param caractersAlfabet Caràcters de l'alfabet
     * @return Algorisme de Creació del Teclat
     */
    private char[] calculaTecles(Integer amplada, Integer altura, String caractersAlfabet){
        int[][] trafic = parellsLletres.getTrafic();

        Posicio[] posicions = generarPosicions(amplada, altura);
        int[][] matDist = crearMatDist(posicions);

        return algoritme.crearDistribucio(caractersAlfabet, matDist, trafic);
    }

    /**
     * Genera les Posicions de les tecles del Teclat
     * @param amplada Amplada del Teclat
     * @param altura Altura del Teclat
     * @return Posicions del Teclat
     */
    private static Posicio[] generarPosicions(int amplada, int altura) {
        Posicio[] posicions = new Posicio[amplada * altura];
        for (int i = 0; i < altura; ++i) {
            for (int j = 0; j < amplada; ++j) {
                posicions[i * amplada + j] = new Posicio(i, j);
            }
        }
        return posicions;
    }

    /**
     * Calcula la Distància entre dues posicions
     * @param p1 Posició 1
     * @param p2 Posició 2
     * @return Distància entre dues posicions
     */
    private static int calcularDist(Posicio p1, Posicio p2) {
        return Math.abs(p1.getI() - p2.getI()) + Math.abs(p1.getJ() - p2.getJ());
    }

    /**
     * Crea la Matriu de Distàncies
     * @param posicions Posicions del Teclat
     * @return Matriu de Distàncies
     */
    private static int[][] crearMatDist(Posicio[] posicions) {
        int[][] distPos = new int[posicions.length][posicions.length];
        for (int i = 0; i < distPos.length; ++i) {
            for (int j = i; j < distPos[0].length; ++j) {
                int dist = calcularDist(posicions[i], posicions[j]);
                distPos[i][j] = dist;
                distPos[j][i] = dist;
            }
        }
        return distPos;
    }

    /**
     * Retorna la distribució del Teclat
     * @return Distribució del Teclat
     */
    public char[][] getTecles(){
        char[][] mat = new char[altura][amplada];
        for (int i = 0; i < altura; ++i){
            System.arraycopy(tecles, i * amplada, mat[i], 0, amplada);
        }
        return mat;
    }

    /**
     * Modifica el Layout del Teclat
     * @param amplada Amplada del Teclat
     * @param altura Altura del Teclat
     * @throws Exception En cas de que hi hagi algun error
     */
    public void modificarLayoutTeclat(Integer amplada, Integer altura) throws Exception {
        if (amplada*altura != this.amplada*this.altura) throw new Exception("El layout no correspon amb el numero de lletres");
        this.amplada = amplada;
        this.altura = altura;
        StringBuilder sb = new StringBuilder();
        for(char c : tecles) sb.append(c);
        tecles = calculaTecles(amplada, altura, sb.toString());
    }

    /**
     * Modifica les Tecles del Teclat
     * @param p1 Posició 1
     * @param p2 Posició 2
     * @throws Exception En cas de que hi hagi algun error
     */
    public void canviarTeclesTeclat(Posicio p1, Posicio p2) throws Exception {
        int pos1 = p1.getI() * amplada + p1.getJ();
        int pos2 = p2.getI() * amplada + p2.getJ();
        int total = (altura * amplada) - 1;
        if (pos1 > total | pos1 < 0 | pos2 > total | pos2 < 0) throw new Exception("Tecla invàlida");
        char temp = tecles[pos1];
        tecles[pos1] = tecles[pos2];
        tecles[pos2] = temp;
    }
}