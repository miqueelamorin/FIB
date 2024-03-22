package domini;

import java.util.Comparator;

/**
 * Aquesta Classe representa un comparador de cromosomes.
 */
public class CompCromosoma implements Comparator<Cromosoma> {

    /**
     * Compara dos cromosomes basant-se en els seus costos.
     * @param n1 Primer cromosoma a comparar.
     * @param n2 Segon cromosoma a comparar.
     * @return Un valor negatiu si n1 és més barat que n2, un valor positiu si n1 és més car que n2,
     *         i 0 si tenen el mateix cost.
     */
    @Override
    public int compare(Cromosoma n1, Cromosoma n2) {
        Integer c1 = n1.getCost();
        Integer c2 = n2.getCost();
        return c1.compareTo(c2);
    }
}
