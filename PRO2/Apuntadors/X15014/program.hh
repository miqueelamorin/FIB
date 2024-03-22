
static void recursivo(node_arbre* node, node_arbre* &new_node, int &suma) {
    if (node == NULL) {
        suma = 0;
        new_node = NULL;
    }
    else {
        suma = node->info;

        int suma_e, suma_d;
        node_arbre *nE, *nD;
        nE = nD = NULL;

        recursivo(node->segE, nE, suma_e);
        recursivo(node->segD, nD, suma_d);

        suma += suma_e + suma_d;
        new_node = new node_arbre;

        new_node->info = suma;
        new_node->segE = nE;
        new_node->segD = nD;
    }
}

/* Pre: cert */
/* Post: l'arbre asum és l'arbre suma del p.i. */
void arb_sumes(Arbre<int> &asum) const{
    int suma = 0;
    recursivo(primer_node, asum.primer_node, suma);
}

