package domini;

import java.util.Map;

/**
 * Classe ParellsLletres
 */
public class ParellsLletres {
    private int[][] trafic;
    private final ParaulesFrequencia pf;
    private final Alfabet a;


    /**
     * Constructora de ParellsLletres
     * @param a Alfabet
     * @param pf ParaulesFrequencia
     */
    public ParellsLletres(Alfabet a, ParaulesFrequencia pf) {
        //CtrlTeclat ct = new CtrlTeclat();
        String caractersAlfabet = a.getCaracters();
        Map<String,Integer> llistaFreq = pf.getLlistaFreq();
        this.a = a;
        this.pf = pf;
        trafic = calculaTrafic(caractersAlfabet, llistaFreq);
    }

    /**
     * Getter de l'alfabet
     * @return Alfabet
     */
    public Alfabet getAlfabet(){return a;}

    /**
     * Getter de les paraulesfreq
     * @return ParaulesFrequencia
     */
    public ParaulesFrequencia getParaulesFreq(){return pf;}

    /**
     * Getter de trafic
     * @return matriu de trafic
     */
    public int[][] getTrafic() { return trafic; }

    /**
     * Calcula el trafic de l'alfabet i la llista de paraules donats
     * @param caractersAlfabet String amb els caracters de l'alfabet
     * @param llistaFreq Map amb les paraules i la seva frequencia
     * @return matriu de trafic
     */
    private int[][] calculaTrafic(String caractersAlfabet, Map<String, Integer> llistaFreq){
        int n = caractersAlfabet.length();
        trafic = new int[n][n];

        for (Map.Entry<String, Integer> entry : llistaFreq.entrySet()) {
            String key = entry.getKey();

            for (int i = 0; i < key.length()-1; i++) {

                char a = key.charAt(i);
                char b = key.charAt(i+1);
                int indexa = caractersAlfabet.indexOf(a);
                int indexb = caractersAlfabet.indexOf(b);

                if (indexa != -1 && indexb != -1) {
                    trafic[indexa][indexb] += entry.getValue();
                    if (a != b) trafic[indexb][indexa] += entry.getValue();
                }
            }
        }
        return trafic;
    }
}
