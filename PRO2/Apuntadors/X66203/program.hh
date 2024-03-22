
static void recursivo(node_arbreNari* node, int &max, int N) {
    if (node != NULL) {
        if (node->info > max) max = node->info;
        for (int i = 0; i < N; ++i){
            recursivo(node->seg[i], max, N);
        }
    }
}


/* Pre: el p.i. no és buit */
/* Post: el resultat indica el valor més gran que conté el p.i. */ 
T maxim() const{
    T max = primer_node->info;
    recursivo(primer_node, max, N);
    return max;
}
