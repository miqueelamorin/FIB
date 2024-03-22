#include "Estudiant.hh"
#include <vector>
using namespace std;
 
 pair<int,int>  max_min_vest(const vector<Estudiant>& v) {
 /* Pre: v no conte repeticions de dni  */
 /* Post: si existeix a v algun estudiant amb nota, la primera component del
    resultat es la posicio de l'estudiant de nota maxima de v i la segona
    component es la posicio de l'estudiant de nota minima de v (si hi ha
    empats, s'obte en cada cas la posicio de l'estudiant amb minim DNI); si no
    hi ha cap estudiant amb nota, totes dues components valen -1 */
    pair<int,int> pos(-1, -1);
    int size = v.size();
    for (int i = 0; i < size; ++i) {
        if (v[i].te_nota()){
            if (pos.first == -1) pos.first = pos.second = i;
        
            else {
                double nota = v[i].consultar_nota();
                if (nota > v[pos.first].consultar_nota()) pos.first = i;
                else if (nota == v[pos.first].consultar_nota() and v[i].consultar_DNI() < v[pos.first].consultar_DNI()) pos.first = i;
                if (nota < v[pos.second].consultar_nota()) pos.second = i;
                else if (nota == v[pos.second].consultar_nota() and v[i].consultar_DNI() < v[pos.second].consultar_DNI()) pos.second = i;
            } 
        }
    }
    return pos;
}
