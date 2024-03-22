package domini;

import java.util.*;

/**
 * Aquesta Classe representa un algorisme de Branch and Bound
 */
public class BranchAndBound implements CreadorTeclat{
    private int[][] matDist;
    private int[][] matTrafic;

    /**
     * Constructora de la classe BranchAndBound
     */
    public BranchAndBound(){}


    /**
     * Genera una copia de una matriu d'enters donada.
     * @param mat matriu d'enters de la qual en volem fer una còpia.
     * @return Retorna una còpia de la matriu "mat".
     */
    private Integer[][] crearCopiaMatriu(Integer[][] mat) {
        Integer[][] copy = new Integer[mat.length][mat.length];
        for (int i = 0; i < mat.length; ++i) {
            copy[i] = Arrays.copyOf(mat[i], mat[i].length);
        }
        return copy;
    }

    /**
     * Calcula el producte escalar entre dos vectors donats.
     * @param v1 Primer vector del producte escalar.
     * @param v2 Segon vector del producte escalar.
     * @return Retorna el producte escalar entre "v1" i "v2".
     */
    private int producteEscalar(List<Integer> v1, List<Integer> v2) {
        int result = 0;
        for (int i = 0; i < v1.size(); ++i) {
            result += v1.get(i) * v2.get(i);
        }
        return result;
    }

    /**
     * Suma dues matrius donades.
     * @param m1 Matriu d'enters a la qual se li sumarà "m2"
     * @param m2 Matriu d'enters que es sumarà a "m1".
     */
    private void sumarMatrius(Integer[][] m1, Integer[][] m2) {
        for (int i = 0; i < m1.length; ++i) {
            for (int j = 0; j < m1[0].length; ++j) {
                m1[i][j] += m2[i][j];
            }
        }
    }

    /**
     * Calcula el primer terme del mètode de Gilmore-Lawler per calcular una cota.
     * @param sol Solució parcial trobada.
     * @return Retorna el primer terme.
     */
    private Integer calcularT1(List<Integer> sol){
        int t1 = 0;
        for (int i = 0; i < sol.size(); ++i) {
            for (int j = i; j < sol.size(); ++j) {
                t1 += matTrafic[sol.get(i)][sol.get(j)] * matDist[i][j];
            }
        }
        return t1;
    }

    /**
     * Genera la matriu C1 del mètode de Gilmore-Lawler relacionada amb els costos entre les instalacions emplaçades i les no emplaçades
     * @param sol Solució parcial trobada.
     * @param instPend Instalacions pendets de emplaçar.
     * @param m Numero d'instalacions emplaçades fins el moment.
     * @param N Numero total de instalacions.
     * @return Retorna la matriu C1.
     */
    private Integer[][] generarC1(List<Integer> sol, List<Integer> instPend, Integer m, Integer N) {
        Integer[][] c1 = new Integer[N - m][N - m];
        for (int i = 0; i < instPend.size(); ++i) {
            for (int j = 0; j < sol.size(); ++j) {
                for (int k = 0; k < N - m; ++k) {
                    if (c1[i][k] == null)
                        c1[i][k] = matTrafic[instPend.get(i)][sol.get(j)] * matDist[m + k][j];
                    else
                        c1[i][k] += matTrafic[instPend.get(i)][sol.get(j)] * matDist[m + k][j];
                }
            }
        }
        return c1;
    }

    /**
     * Genera el vector T del mètode de Gilmore-Lawler per una instalació donada.
     * @param act Instalació per la qual s'està calculant el vector T.
     * @param instPend Llista amb les instalacions pendents d'emplaçar.
     * @return Retorna una llista que conté el tràfic des de "act" a la resta d'instalacions no emplaçades.
     */
    private List<Integer> generarT(Integer act, List<Integer> instPend) {
        List<Integer> T = new ArrayList<>();
        for (Integer integer : instPend) {
            if (!Objects.equals(act, integer))
                T.add(matTrafic[act][integer]);
        }
        return T;
    }

    /**
     * Genera el vector D del mètode de Gilmore-Lawler per una posició donada.
     * @param pact Posició per la qual s'està calculant el vector D.
     * @param m Index de la primera posició lliure.
     * @param N Numero de posicions total.
     * @return Retorna una llista que conté les distàncies des de "pact" a la resta de posicions lliures.
     */
    private List<Integer> generarD(Integer pact, Integer m, Integer N) {
        List<Integer> D = new ArrayList<>();
        for (int i = m; i < N; ++i) {
            if (pact != i)
                D.add(matDist[pact][i]);
        }
        return D;
    }

    /**
     * Genera la matriu C2 del mètode de Gilmore-Lawler relacionada amb els costos entre les instalacions no emplaçades
     * @param instPend Instalacions pendets de emplaçar.
     * @param m Número d'instalacions emplaçades fins al moment.
     * @param N Número total de instalacions.
     * @return Retorna la matriu C2.
     */
    private Integer[][] generarC2(List<Integer> instPend, Integer m, Integer N) {
        Integer[][] c2 = new Integer[N - m][N - m];
        for (int i = 0; i < instPend.size(); ++i) {
            List<Integer> T = generarT(instPend.get(i), instPend);
            Collections.sort(T);
            for (int k = 0; k < N - m; ++k) {
                List<Integer> D = generarD(m + k, m, N);
                D.sort(Collections.reverseOrder());
                c2[i][k] = producteEscalar(T, D);
            }
        }
        return c2;
    }

    /**
     * Calcula el segon i tercer terme del mètode de Gilmore-Lawler per calcular la cota.
     * @param sol Solució parcial trobada.
     * @param instPend Instalacions pendets de emplaçar.
     * @param m Numero d'instalacions emplaçades fins el moment.
     * @param N Numero total de instalacions.
     * @return Retorna la suma del segon i tercer terme de la cota de Gilmore-Lawler
     */
    private Integer calcularT2T3(List<Integer> sol, List<Integer> instPend, Integer m, Integer N) {
        Integer[][] c1 = generarC1(sol, instPend, m, N);
        Integer[][] c2 = generarC2(instPend, m, N);

        sumarMatrius(c1, c2);
        Integer[][] c1copy = crearCopiaMatriu(c1);

        int t2t3 = 0;
        int[] assignacio = HungarianAlgorithm.trobarAssignacioOptima(c1copy);
        for (int i = 0; i < c1.length; ++i)
            t2t3 += c1[i][assignacio[i]];

        return t2t3;
    }

    /**
     * Donada una solució parcial trobada calcula la cota de la millor solució obtenible a partir de la mateixa.
     * @param sol Solució parcial trobada.
     * @param instPend Instalacions pendets de emplaçar.
     * @param m Numero d'instalacions emplaçades fins el moment.
     * @param N Numero total d'instalacions.
     * @return Retorna la cota de la solució parcial.
     */
    private Integer calcularCota(List<Integer> sol, List<Integer> instPend, Integer m, Integer N) {
        Integer t1 = calcularT1(sol);
        Integer t2t3 = calcularT2T3(sol, instPend, m, N);
        return t1 + t2t3;
    }

    /**
     * Calcula la assignaicó més òptima utilitzant un algoritme de branch and bound amb una estratègia eager.
     * @param sol Una solució parcial trobada.
     * @param instPend Instalacions pendents de emplaçar.
     * @param m Numero de instalacions emplaçades
     * @param N Numero total de instalacions.
     */
    private void branchAndBound(List<Integer> sol, List<Integer> instPend, Integer m, Integer N) {
        if (m < N) {
            PriorityQueue<Node> pq = new PriorityQueue<>(new CompNode());
            for (Integer inst = 0; inst < N; ++inst) {
                if (!sol.contains(inst)) {
                    instPend.remove(inst);
                    sol.add(inst);
                    Integer cota = calcularCota(sol, instPend, m + 1, N);
                    pq.add(new Node(inst, cota));
                    instPend.add(inst);
                    sol.remove(inst);
                }
            }
            Node millorSol = pq.peek();
            if (millorSol != null) {
                sol.add(millorSol.getInstalacio());
                instPend.remove(millorSol.getInstalacio());
            }
            branchAndBound(sol, instPend, m + 1, N);
        }
    }

    /**
     * Mètode principal per generar una distribuió a partir de les distàncies entre ubicaions i el tràfic entre instalacions.
     * @param alfabet Alfabet amb els caràcters que contindrà la distribució.
     * @param matDist Matriu que conté les distàncies entre posicions.
     * @param matTrafic Matriu que conté el trèfic entre cada parell de caràcters.
     * @return Retorna un vector de caràcters amb la millor distribució trobada.
     */
    public char[] crearDistribucio(String alfabet, int[][] matDist, int[][] matTrafic) {
        this.matDist = matDist;
        this.matTrafic = matTrafic;

        int N = alfabet.length();
        List<Integer> sol = new ArrayList<>(N);
        List<Integer> instPend = new ArrayList<>(N);
        for (int i = 0; i < N; ++i)
            instPend.add(i);

        branchAndBound(sol, instPend, 0, N);

        char[] distibucioResultant = new char[N];
        for (int i = 0; i < N; ++i)
            distibucioResultant[i] = alfabet.charAt(sol.get(i));

        return distibucioResultant;
    }
}
