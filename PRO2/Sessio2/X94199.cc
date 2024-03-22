#include "Estudiant.hh"
#include <vector>

void simplificar_vector(vector<Estudiant>& v, int& pos){
    /* Pre: v=V, v.size() > 0 i les notes d'un mateix estudiant son consecutives */
    /* Post: pos+1 es el nombre d'estudiants diferents de V; cada estudiant de V
    nomes hi apareix un cop a v[0..pos], amb la nota mes alta i en el mateix
    ordre que a V */

    pos = 0;
    int size = v.size();
    for (int i=0; i<size; i++){
        if (v[i].te_nota()){
            if (v[i].consultar_DNI() == v[pos].consultar_DNI()){
                if (v[i].consultar_nota() > v[pos].consultar_nota()){
                    v[pos]=v[i];
                }
            }
            else {
                pos++;
                v[pos]=v[i];

            }
        }
        else{
            if (v[i].consultar_DNI()!=v[pos].consultar_DNI()){
                v[pos]=v[i];
                pos++;
            }
        }
    }
}
