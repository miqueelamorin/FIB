package domini;

/**
 * Classe Node
 */
public class Node {
    private final Integer instalacio;
    private final Integer cota;

    /**
     * Constructora de Node
     * @param instalacio Instalacio del Node
     * @param cota Cota del Node
     */
    public Node(Integer instalacio, Integer cota) {
        this.instalacio = instalacio;
        this.cota = cota;
    }

    /**
     * Getter de instalacio
     * @return Instalacio del Node
     */
    public Integer getInstalacio() {
        return instalacio;
    }

    /**
     * Getter de cota
     * @return Cota del Node
     */
    public Integer getCota() {
        return cota;
    }

    /**
     * Funcio toString
     * @return String del la cota del Node
     */
    public String toString() {
        return String.valueOf(cota);
    }
}
