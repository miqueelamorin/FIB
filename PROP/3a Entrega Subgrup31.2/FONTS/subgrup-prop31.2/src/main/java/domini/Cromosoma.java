package domini;

import java.util.ArrayList;
import java.util.List;

/**
 * Classe que representa un cromosoma.
 */
public class Cromosoma {

    /**
     * Llista que emmagatzema els gens del cromosoma.
     */
    private List<Integer> gens;

    /**
     * Cost associat al cromosoma.
     */
    private int cost;

    /**
     * Constructor que inicialitza el cromosoma amb una llista de gens.
     *
     * @param gens Llista de gens del cromosoma.
     */
    public Cromosoma(List<Integer> gens) {
        this.gens = gens;
        this.cost = 0;
    }

    /**
     * Constructor per defecte que inicialitza el cromosoma sense gens.
     */
    public Cromosoma() {
        gens = new ArrayList<>();
        cost = 0;
    }

    /**
     * Obté la llista de gens del cromosoma.
     *
     * @return Llista de gens del cromosoma.
     */
    public List<Integer> getGens() {
        return gens;
    }

    /**
     * Obté el cost associat al cromosoma.
     *
     * @return Cost del cromosoma.
     */
    public int getCost() {
        return cost;
    }

    /**
     * Estableix el cost associat al cromosoma.
     *
     * @param cost Nou cost del cromosoma.
     */
    public void setCost(int cost) {
        this.cost = cost;
    }

    /**
     * Estableix la llista de gens del cromosoma.
     *
     * @param gens Nova llista de gens del cromosoma.
     */
    public void setGens(List<Integer> gens) {
        this.gens = gens;
    }

    /**
     * Representació en cadena del cromosoma.
     *
     * @return Cadena que representa el cromosoma.
     */
    @Override
    public String toString() {
        return String.valueOf(gens) +
                ':' +
                cost;
    }
}
