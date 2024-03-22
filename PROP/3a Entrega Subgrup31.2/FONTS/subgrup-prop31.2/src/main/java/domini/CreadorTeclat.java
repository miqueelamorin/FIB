package domini;


/**
 * Aquesta Classe és una interficie que representa un creador de teclats
 */
public interface CreadorTeclat {
    /**
     * Crear una distribució de teclat a partir d'un alfabet i les seves matrius de distàncies i tràfic.
     * @param alfabet Alfabet del qual volem crear la distribució.
     * @param matDist Matriu de distàncies entre els caràcters de l'alfabet.
     * @param matTrafic Matriu de tràfic entre els caràcters de l'alfabet.
     * @return Retorna un array de caràcters que representa la distribució del teclat.
     */
    char[] crearDistribucio(String alfabet, int[][] matDist, int[][] matTrafic);
}
