/* Pre: cert */
/* Post: el resultat indica el nombre d'aparicions de x en el p.i. */
int freq(const T& x) const{
    int count = 0;
    contador(x, primer_node, count);
    return count;
}

static void contador(const T& x, node_arbreGen* m, int& count){
    if (m != NULL){
        if (m->info == x) ++count;
        int ari = m->seg.size();
        for (int i = 0; i < ari; ++i) {
            contador(x, m->seg[i], count);
        }
    }
}
