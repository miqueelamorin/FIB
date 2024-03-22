/* Pre: cert */
/* Post: el resultat indica si x es troba al p.i. o no */
bool buscar(const T& x) const{
    return buscar_valor(x, primer_node);
}

static bool buscar_valor(const T& x, node_arbreGen* m){
    if (m == NULL) return false;
    else {
        if (m->info == x) return true;
        int ari = m->seg.size();
        for (int i = 0; i < ari; ++i) {
            if (buscar_valor(x, m->seg[i])) return true;
        }
        return false;
    }
}
