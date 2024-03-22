package domini;

/**
 * Classe que representa una posicio
 */
public class Posicio {
    private Integer i;
    private Integer j;


    /**
     * Constructora de Posicio
     * @param i i de la posicio
     * @param j j de la posicio
     */
    public Posicio(Integer i, Integer j) {
        this.i = i;
        this.j = j;
    }

    /**
     * Getter de i
     * @return i de la posicio
     */
    public Integer getI() {
        return i;
    }

    /**
     * Setter de i
     * @param i i de la posicio
     */
    public void setI(Integer i) {
        this.i = i;
    }

    /**
     * Getter de j
     * @return j de la posicio
     */
    public Integer getJ() {
        return j;
    }

    /**
     * Setter de j
     * @param j j de la posicio
     */
    public void setJ(Integer j) {
        this.j = j;
    }
}
