package domini;

/**
 * Classe Pair
 * @param <T> Tipus del primer element
 * @param <U> Tipus del segon element
 */
public class Pair<T, U> {
    /**
     * Atributs de Pair
     */
    T first;
    /**
     * Atributs de Pair
     */
    U second;

    /**
     * Constructora de Pair
     * @param first Primer element
     * @param second Segon element
     */
    public Pair(T first, U second) {
        this.first = first;
        this.second = second;
    }

    /**
     * Getter de first
     * @return Primer element del Pair
     */
    public T getFirst() { return first; }

    /**
     * Getter de second
     * @return Segon element del Pair
     */
    public U getSecond() { return second; }
}