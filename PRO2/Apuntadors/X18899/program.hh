static void recursivo(node_arbreNari* node, node_arbreNari* &new_node, int N) {
    if (node == NULL) new_node = NULL;
    else {
        new_node = new node_arbreNari;
        new_node->info = node->info;
        new_node->seg = vector<node_arbreNari*> (N);
        
        for (int i = 0; i < N; ++i) {
            recursivo(node->seg[i], new_node->seg[i], N);
            if (new_node->seg[i] != NULL) new_node->info += new_node->seg[i]->info;
        }
    }
}




/* Pre: cert */
/* Post: asum és un arbre amb la mateixa estructura que el p.i.
         i cada node és la suma del node corresponent al p.i
         i tots els seus descendents al p.i. */ 
void arbsuma(ArbreNari& asum) const{
    recursivo(primer_node, asum.primer_node, N);    
}

