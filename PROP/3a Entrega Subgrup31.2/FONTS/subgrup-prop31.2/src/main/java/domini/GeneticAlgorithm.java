package domini;

import java.util.*;
import java.util.Random;

/**
 * Aquesta classe representa l'algorisme genètic per trobar una distribució optimitzada per al teclat.
 */
public class GeneticAlgorithm implements CreadorTeclat
{

    /**
     * -----------[GENETIC ALGORTITHM]-----------
     * Un cromosoma representa una possble solucio!
     */

    /**
     * Nombre màxim d'individus a la població.
     */
    private final int N = 80;
    /**
     * Llista que emmagatzema la població de cromosomes.
     */
    private List<Cromosoma> poblacio;

    /**
     * Constructora de la classe GeneticAlgorithm.
     */
    public GeneticAlgorithm(){}


    /**
     * Inicialitza la població inicial amb valors aleatoris.
     *
     * @param midaProb Grandària del problema (nombre de lletres a distribuir).
     */
    private void poblacioInicial(int midaProb)
    {
        poblacio = new ArrayList<>();

        //Inicializamos #modaPobl cromosomas randomizados
        for(int i = 0; i < N; ++i){
            Cromosoma cr = new Cromosoma();
            List<Integer> tira = new ArrayList<>();

            for(int k = 0; k < midaProb; ++k){
                tira.add(k);
            }

            Collections.shuffle(tira);
            cr.setGens(tira);
            poblacio.add(cr);
        }

    }


    /**
     * Calcula el cost de cada cromosoma de la població basant-se en les matrius de distància i tràfic.
     *
     * @param matDist Matriu de distàncies entre lletres del teclat.
     * @param matTrafic Matriu de tràfic entre lletres.
     */
    private void calculaFit(int[][] matDist, int[][] matTrafic)
    {

        for(Cromosoma cr : poblacio){
            int cost = 0;
            Set<Pair<Integer, Integer>> visited = new HashSet<>();

            List<Integer> tira = cr.getGens();

            for(int i = 0; i < tira.size(); ++i){

                int a = tira.get(i);

                for(int j = 0; j < tira.size(); ++j){

                    if(visited.contains(new Pair<>(i, j))) continue;

                    int b = tira.get(j);

                    // Distancia(a,b) * trafic[a][b]
                    cost += matDist[i][j] * matTrafic[a][b];

                    visited.add(new Pair<>(i, j));
                }
            }

            cr.setCost(cost);
        }

    }

    /**
     * Funció de selecció que retorna el millor cromosoma de la població (Tournament Selection).
     *
     * @return Cromosoma seleccionat com a millor.
     */
    private Cromosoma selectionFunc()
    {
        Collections.shuffle(poblacio);

        List<Cromosoma> poblSelect = new ArrayList<>();
        for(int i = 0; i <= 5; ++i){
            poblSelect.add(poblacio.get(i));
        }

        poblSelect.sort(new CompCromosoma());

        return poblSelect.get(0);
    }

    /**
     * Identifica els duplicats en una llista d'enters.
     *
     * @param l Llista d'enters.
     * @return Conjunt d'enters duplicats.
     */
    private Set<Integer> duplicats(List<Integer> l)
    {
        Set<Integer> duplicats = new HashSet<>();

        List<Boolean> dup = new ArrayList<>(Collections.nCopies(l.size(), false));

        for(Integer i : l){
            if(dup.get(i)){
                duplicats.add(i);
            }
            else dup.set(i, true);
        }
        return duplicats;
    }

    /**
     * Realitza el crossover entre dos cromosomes, generant dos fills (Uniform Crossover).
     *
     * @param p1 Primer cromosoma pare.
     * @param p2 Segon cromosoma pare.
     * @return Parella de cromosomes fills.
     */
    private Pair<Cromosoma, Cromosoma> crossoverFunc(Cromosoma p1, Cromosoma p2)
    {
        List<Integer> genesp1 = p1.getGens();
        List<Integer> genesp2 = p2.getGens();

        List<Integer> genesFill1 = new ArrayList<>();
        List<Integer> genesFill2 = new ArrayList<>();

        Random random = new Random();

        //Generamos un punto aleatorio de crossover
        int indice = random.nextInt(genesp1.size());

        //Creamos el primer hijo usando los genes hasta el indice del padre1
        for(int i = 0; i < indice; ++i){
            genesFill1.add(genesp1.get(i));
        }

        for(int i = indice; i < genesp2.size(); ++i){
                genesFill1.add(genesp2.get(i));
        }


        //Creamos el segundo hijo con el material genetico del padre2 hasta el indice.
        for(int i = 0; i < indice; ++i){
            genesFill2.add(genesp2.get(i));
        }

        for(int i = indice; i < genesp1.size(); ++i){
            genesFill2.add(genesp1.get(i));
        }


        //Handleamos duplicados
        Set<Integer> dupH1 = duplicats(genesFill1);
        Set<Integer> dupH2 = duplicats(genesFill2);

        for(Integer dup : dupH1){
            genesFill1.remove(dup);
            genesFill2.add(dup);
        }

        for(Integer dup : dupH2){
            genesFill2.remove(dup);
            genesFill1.add(dup);
        }

        Cromosoma fill1 = new Cromosoma(genesFill1);
        Cromosoma fill2 = new Cromosoma(genesFill2);

        return new Pair<>(fill1, fill2);
    }

    /**
     * Realitza una mutació en un cromosoma, intercanviant dos gens de posició aleatòria (Swap Mutation).
     *
     * @param c Cromosoma a mutar.
     * @return Cromosoma mutat.
     */
    private Cromosoma mutacioFun(Cromosoma c){
        Random rand = new Random();

        List<Integer> tira = c.getGens();

        int idx1 = rand.nextInt(tira.size());
        int idx2 = rand.nextInt(tira.size());
        while(idx1 == idx2) idx2 = rand.nextInt(tira.size());

        int tmp = tira.get(idx1);
        c.getGens().set(idx1, tira.get(idx2));
        c.getGens().set(idx2, tmp);

        return c;
    }

    /**
     * Implementa l'algorisme genètic per trobar una solució optimitzada per a la distribució del teclat.
     *
     * @param alfabet Alfabet de lletres a distribuir.
     * @param matDist Matriu de distàncies entre lletres del teclat.
     * @param matTrafic Matriu de tràfic entre lletres.
     * @return Llista d'índexs que representa la distribució optimitzada.
     */
    private List<Integer> algoritmeGenetic(String alfabet, int[][] matDist, int[][] matTrafic){

        poblacioInicial(alfabet.length());

        Cromosoma solucio = null;

        List<Cromosoma> nova_generacio = new ArrayList<>();

        int iteracions = 1000;
        int n = 0;

        while(n < iteracions) {

            //Calculamos los costes de cada cromosoma
            calculaFit(matDist, matTrafic);

            //Rordenamos la poblacion en funcion del coste de cada cromosoma;
            poblacio.sort(new CompCromosoma());

            Cromosoma millorSol = poblacio.get(0);

            if(solucio == null) solucio = millorSol;
            else{
                if(millorSol.getCost() < solucio.getCost()) solucio = millorSol;
            }

            while(nova_generacio.size() < poblacio.size()){

                //Escogemos a los padres
                Cromosoma p1 = selectionFunc();
                Cromosoma p2 = selectionFunc();

                //Crossover entre los padres
                Pair<Cromosoma, Cromosoma> fills = crossoverFunc(p1, p2);

                //Mutamos a los hijos
                Cromosoma f1 = mutacioFun(fills.first);
                Cromosoma f2 = mutacioFun(fills.second);

                nova_generacio.add(f1);
                nova_generacio.add(f2);
            }

            poblacio = nova_generacio;
            nova_generacio = new ArrayList<>();
            ++n;
        }

        return solucio.getGens();
    }

    /**
     * Crea una distribució de lletres per al teclat utilitzant l'algorisme genètic.
     *
     * @param alfabet Alfabet de lletres a distribuir.
     * @param matDist Matriu de distàncies entre lletres del teclat.
     * @param matTrafic Matriu de tràfic entre lletres.
     * @return Distribució de lletres optimitzada pel teclat.
     */
    @Override
    public char[] crearDistribucio(String alfabet, int[][] matDist, int[][] matTrafic)
    {
        int mida = alfabet.length();
        List<Integer> solucio = algoritmeGenetic(alfabet, matDist, matTrafic);

        char[] distibucioResultant = new char[mida];
        for (int i = 0; i < mida; ++i)
            distibucioResultant[i] = alfabet.charAt(solucio.get(i));

        return distibucioResultant;
    }

}
