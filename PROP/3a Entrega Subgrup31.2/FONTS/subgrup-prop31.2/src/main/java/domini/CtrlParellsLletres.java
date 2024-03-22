package domini;

/**
 * Aquesta classe és un controlador de la classe ParellsLletres
 */
public class CtrlParellsLletres {
    private static CtrlParellsLletres instancia;


    /**
     * Singleton de CtrlParellsLletres.
     * @return Instancia de la classe CtrlParellsLletres.
     */
    public static CtrlParellsLletres getInstance(){
        if(instancia == null){
            instancia = new CtrlParellsLletres();
        }
        return instancia;
    }

    /**
     * Constructora de CtrlParellsLletres.
     */
    private CtrlParellsLletres(){}

    /**
     * Crea un objecte de la classe ParellsLletres.
     * @param a Alfabet del ParellsLletres.
     * @param pf ParaulesFrequencia del ParellsLletres.
     * @return Objecte de la classe ParellsLletres.
     */
    public ParellsLletres crearParellLletres (Alfabet  a, ParaulesFrequencia pf) {
        return new ParellsLletres(a, pf);
    }
}
