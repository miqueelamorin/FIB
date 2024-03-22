package domini;

import java.util.Comparator;

/**
 * Classe CompNode
 */
public class CompNode implements Comparator<Node> {

    /**
     * Comparador de Node
     * @param n1 Primer Node
     * @param n2 Segon Node
     * @return 0 si son iguals, 1 si n1 es mes gran que n2, -1 si n1 es mes petit que n2
     */
    @Override
    public int compare(Node n1, Node n2) {
        Integer c1 = n1.getCota();
        Integer c2 = n2.getCota();
        return c1.compareTo(c2);
    }
}
