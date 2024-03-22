/* Pre: cert */
/* Post: el resultat és una llista que conté els mateixos
elements que el p.i. tal que tots els més petits o iguals
que x al p.i. precedeixen als més grans que x al p.i. però
sempre respectant l'ordre que hi havia entre ells al p.i.
L'element actual de la llista retornada és el primer dels
més grans que x, si existeix, sinó es situa a la detra del
tot. El p.i. no es modifica */
Llista reorganitzar_out(const T& x) const{
    Llista l;
    if (longitud == 0) return l;
    l.longitud = longitud;
    l.act = l.ultim_node = l.primer_node = NULL;
    node_llista* aux = NULL;
    node_llista* act = primer_node;
    while (act != NULL) {
        if (act -> info <= x) {
            if (l.primer_node == NULL) {
                aux = l.primer_node = new node_llista;
                l.primer_node -> ant = NULL;
            }
            else {
                aux -> seg = new node_llista;
                aux -> seg -> ant = aux;
                aux = aux -> seg;
            }
            aux -> info = act -> info;
        }
        else {
            if (l.ultim_node == NULL) {
                l.ultim_node = l.act = new node_llista;
                l.act -> ant = NULL;
            }
            else {
                l.ultim_node -> seg = new node_llista;
                l.ultim_node -> seg -> ant = l.ultim_node;
                l.ultim_node = l.ultim_node -> seg;
            }
            l.ultim_node -> info = act -> info;
        }
        act = act-> seg;
    }

    if (l.primer_node == NULL) l.primer_node = l.act;
    else if (l.act == NULL) l.ultim_node = aux;
    else {
        aux -> seg = l.act;
        l.act -> ant = aux;
    }

    l.ultim_node -> seg = NULL;
    return l;
}
