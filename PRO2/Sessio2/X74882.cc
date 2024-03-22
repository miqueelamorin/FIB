#include "Cjt_estudiants.hh"
#include <iostream>
using namespace std;

void actualitzar(Cjt_estudiants& conj1, const Cjt_estudiants& conj2) {
    int size = conj1.mida();
    for (int i = 1; i <= size; ++i) {
        if (conj2.consultar_iessim(i).te_nota()){
            if (conj1.consultar_iessim(i).te_nota()){
                if (conj1.consultar_iessim(i).consultar_nota() < conj2.consultar_iessim(i).consultar_nota()) {
                    conj1.modificar_iessim(i, conj2.consultar_iessim(i));
                }
            }
            else conj1.modificar_iessim(i, conj2.consultar_iessim(i));
        }
    }


}

int main() {
    Cjt_estudiants conj1;
    Cjt_estudiants conj2;
    conj1.llegir();
    conj2.llegir();
    actualitzar(conj1, conj2);
    conj1.escriure();
}
