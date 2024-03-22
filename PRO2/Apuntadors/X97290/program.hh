/* Pre: cert */
/* Post: si m és NULL, el resultat, u i a són NULL; en cas
    contrari, el resultat apunta al primer node d'una cadena de
    nodes que són còpia de la cadena que té el node apuntat per m
    com a primer, u apunta a l'últim node, a és o bé NULL si oact
    no apunta a cap node de la cadena que comença amb m o bé apunta
    al node còpia del node apuntat per oact */
node_llista* copia_node_llista_it (node_llista* m, node_llista* oact,
        node_llista* &u, node_llista* &a){
    if (m == NULL){
        u = a = NULL;
        return NULL;
    }
    node_llista *first, *aux;
    first = aux = new node_llista;
    first->info = m->info;
    first->ant = NULL;
    m = m->seg;

    while (m != NULL){
        aux->seg = new node_llista;
        aux->seg->ant = aux;
        aux = aux->seg;
        aux->info = m->info;

        if (oact == m) a = aux;
        m = m->seg;
    }
    u = aux;
    return first;
}

/* Pre: cert */
/* Post: El p.i. passa a ser una còpia d'original i qualsevol
    contingut anterior del p.i. ha estat esborrat (excepte si el
    p.i. i original ja eren el mateix objecte) */
Llista& operator=(const Llista& original){
    if (this != &original){
        longitud = original.longitud;
        esborra_node_llista_it(primer_node);
        primer_node = copia_node_llista_it(original.primer_node, original.act, ultim_node, act);
    }
    return *this;
}
