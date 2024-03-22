package domini;

import java.util.Arrays;
import java.util.Objects;

/**
 * Classe que representa l'hungarian algorithm
 **/
public class HungarianAlgorithm {
    /**
     * Aquesta funció ens permet saber el valor mínim d'una fila de la matriu de costos.
     * @param fila Índex d'una columna de la matriu.
     * @param matCost Matriu de costos.
     * @return Retorna el valor mínim de la fila "fila" da la matriu "matCost"
     */
    private static Integer valorMinimFila(Integer fila, Integer[][] matCost) {
        Integer min = Integer.MAX_VALUE;
        for (Integer val : matCost[fila]) {
            if (val < min)
                min = val;
        }
        return min;
    }

    /**
     * Valor mínim d'una columna de la matriu de costos.
     * @param col Índex d'una columna de la matriu.
     * @param matCost Matriu de costos.
     * @return Retorna el valor mínim de la columna "col" da la matriu "matCost"
     */
    private static Integer valorMinimColumna(Integer col, Integer[][] matCost) {
        Integer min = Integer.MAX_VALUE;
        for (Integer[] fila : matCost) {
            if (fila[col] < min)
                min = fila[col];
        }
        return min;
    }

    /**
     * Aquesta funció ens permet saber el número de zeros assignats en una assignació.
     * @param assig Un vector d'enters que representa una possible assignació.
     * @return Retorna el numero de files amb un zero assignat.
     */
    private static Integer numZerosAssignats(int[] assig) {
        Integer num = 0;
        for (int val : assig)
            if (val != -1)
                ++num;
        return num;
    }

    /**
     * Obtenim el mínim número no cobert de la matriu de costos.
     * @param matCost Matriu de costos.
     * @param filesMarcades Vector de booleans que representa les files marcades.
     * @param colsMarcades Vector de booleans que representa les columnes marcades.
     * @return Retorna el valor minim no cobert per cap línia.
     */
    private static int obtenirMinimNumNoCobert(Integer[][] matCost, boolean[] filesMarcades, boolean[] colsMarcades) {
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < matCost.length; ++i)
            for (int j = 0; j < matCost[i].length; ++j)
                if (filesMarcades[i] && !colsMarcades[j] && matCost[i][j] < min)
                    min = matCost[i][j];
        return min;
    }

    /**
     * Comprova si la matriu conté algun zero no cobert per una linia.
     * @param costMatrix Matriu de costos.
     * @param filesMarcades Vector de booleans que representa les files marcades.
     * @param colsMarcades Vector de booleans que representa les columens marcades.
     * @return Retorna "true" si la matriu conté algun zero no cobert per una linia, "false" en cas contrari.
     */
    private static boolean conteZerosNoCoberts(Integer[][] costMatrix, boolean[] filesMarcades, boolean[] colsMarcades) {
        for (int i = 0; i < costMatrix.length; ++i)
            for (int j = 0; j < costMatrix[0].length; ++j)
                if (costMatrix[i][j] == 0 && !(!filesMarcades[i] || colsMarcades[j]))
                    return true;
        return false;
    }

    /**
     * Funció recursiva que troba una assignació òptima per al Linear Assignment Problem.
     * @param matCost Matriu de costos.
     * @param colsCobertes Vector de booleans que ens serveix per guardar les columnes que ja estan cobertes per una linia.
     * @param assigActual Vector d'enters que representa una possible assignació.
     * @param millorAssignacio Vector d'enters que representa la millor assignació trobada fins al moment.
     * @param f Índex de la fila a la qual ens trobem en una determinada iteració del backtracking.
     * @param N Mida d'un costat de la matriu.
     * @return Retorna "true" si s'ha trobat una assignació òptima, "false" en cas contrari.
     */
    private static boolean trobarMillorAssignacioPossible(
            Integer[][] matCost,
            boolean[] colsCobertes,
            int[] assigActual,
            int[] millorAssignacio,
            Integer f,
            Integer N
    ) {
        if (Objects.equals(f, N)) {
            int numAssigs = numZerosAssignats(assigActual);
            if (numAssigs > numZerosAssignats(millorAssignacio))
                System.arraycopy(assigActual, 0, millorAssignacio, 0, assigActual.length);
            return numAssigs == N;
        }
        else {
            for (int i = 0; i < matCost[f].length; ++i) {
                if (matCost[f][i] == 0 && !colsCobertes[i]) {
                    colsCobertes[i] = true;
                    assigActual[f] = i;
                    if (trobarMillorAssignacioPossible(matCost, colsCobertes, assigActual, millorAssignacio, f + 1, N))
                        return true;
                    colsCobertes[i] = false;
                    assigActual[f] = -1;
                }
            }
            return trobarMillorAssignacioPossible(matCost, colsCobertes, assigActual, millorAssignacio, f + 1, N);
        }
    }

    /**
     * Calcula les linies minimes d'una matriu de costos.
     * @param matCost Matriu de costos.
     * @param filesMarcades Vector de booleans que utilitzem per marcar les files.
     * @param colsMarcades Vector de booleans que utilitzem per marcar les columnes.
     * @param millorAssignacio Vector d'enters on guardarem la millor assignació trobada.
     * @param N Mida d'un costat de la matriu de costos.
     * @return Retorna "true" si s'ha trobat una solució òptima, "false" en cas contrari.
     */
    private static boolean calcularLiniesMinimes(
            Integer[][] matCost,
            boolean[] filesMarcades,
            boolean[] colsMarcades,
            int[] millorAssignacio,
            Integer N
    ) {
        boolean[] colsCobertes = new boolean[N];
        int[] assignacioActual = new int[N];
        Arrays.fill(assignacioActual, -1);

        if (trobarMillorAssignacioPossible(matCost, colsCobertes, assignacioActual, millorAssignacio, 0, N))
            return true;

        // Marquem files sense assignacio
        for (int i = 0; i < N; ++i)
            if (millorAssignacio[i] == -1)
                filesMarcades[i] = true;

        while (conteZerosNoCoberts(matCost, filesMarcades, colsMarcades)) {
            // Marquem cols que tenen algun 0 en alguna fila marcada
            for (int i = 0; i < N; ++i)
                if (filesMarcades[i])
                    for (int j = 0; j < N; ++j)
                        if (matCost[i][j] == 0)
                            colsMarcades[j] = true;

            // Marquem files que tenen el seu 0 a alguna columna marcada
            for (int i = 0; i < N; ++i)
                if (millorAssignacio[i] != -1 && colsMarcades[millorAssignacio[i]])
                    filesMarcades[i] = true;
        }
        return false;
    }

    /**
     * Busca una assignació òptima per al Linear Assignment Problem.
     * @param matCost Matriu de costos.
     * @return Retorna la solució del Linear Assignment Problem aplicat a la matriu "matCost".
     */
    public static int[] trobarAssignacioOptima(Integer[][] matCost) {
        int N = matCost.length;
        // Restem el valor mínim d'una fila a la resta d'elements de la fila
        for (int i = 0; i < N; ++i) {
            Integer minFila = valorMinimFila(i, matCost);
            for (int j = 0; j < N; ++j)
                matCost[i][j] -= minFila;
        }

        // Restem el valor mínim d'una columna a la resta d'elements de la columna
        for (int i = 0; i < N; ++i) {
            Integer minCol = valorMinimColumna(i, matCost);
            for (int j = 0; j < N; ++j) {
                matCost[j][i] -= minCol;
            }
        }

        while (true) {
            boolean[] filesMarcades = new boolean[N];
            boolean[] colsMarcades = new boolean[N];
            int[] assignacio = new int[N];
            Arrays.fill(assignacio, -1);

            if (calcularLiniesMinimes(matCost, filesMarcades, colsMarcades, assignacio, N))
                return assignacio;

            int minNumNoCobert = obtenirMinimNumNoCobert(matCost, filesMarcades, colsMarcades);

            // Restem aquest número de tots els valors no coberts i el sumem als elements que estan doblement coberts
            for (int i = 0; i < matCost.length; ++i)
                for (int j = 0; j < matCost[0].length; ++j) {
                    if (filesMarcades[i] && !colsMarcades[j])
                        matCost[i][j] -= minNumNoCobert;
                    if (!filesMarcades[i] && colsMarcades[j])
                        matCost[i][j] += minNumNoCobert;
                }
        }
    }
}
