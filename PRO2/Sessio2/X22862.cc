#include "Cjt_estudiants.hh"
#include <iostream>

using namespace std;

double redondear(double r)
{
  return int(10.*(r + 0.05)) / 10.0;
}


int main() {
    Cjt_estudiants conj;
    conj.llegir();
    cout << endl;
    int op;
    cin >> op;
    while (op != -6) {
        if (op == -1) {
            Estudiant est;
            est.llegir();
            if (conj.existeix_estudiant(est.consultar_DNI())) cout << "el estudiante " << est.consultar_DNI() << " ya estaba" << endl << endl;
            else if (conj.mida() > 4) cout << "el conjunto esta lleno" << endl << endl;
            else conj.afegir_estudiant(est);
        }

        else if (op == -2) {
            int dni;
            cin >> dni;
            if (not conj.existeix_estudiant(dni)) cout << "el estudiante " << dni << " no esta" << endl << endl;
            else if (conj.consultar_estudiant(dni).te_nota()) cout << "el estudiante " << dni << " tiene nota " << conj.consultar_estudiant(dni).consultar_nota() << endl << endl;
            else cout << "el estudiante " << dni << " no tiene nota" << endl << endl;
        }

        else if (op == -3) {
            Estudiant est;
            est.llegir();
            if (not conj.existeix_estudiant(est.consultar_DNI())) cout << "el estudiante " << est.consultar_DNI() << " no esta" << endl << endl;
            else conj.modificar_estudiant(est);
        }

        else if (op == -4) {
            int size = conj.mida();
            for (int i = 1; i <= size; ++i) {
                if (conj.consultar_iessim(i).te_nota()) {
                    Estudiant est(conj.consultar_iessim(i).consultar_DNI());
                    est.afegir_nota(redondear(conj.consultar_iessim(i).consultar_nota()));
                    conj.modificar_iessim(i, est);
                }
            }

        }

        else if (op == -5) conj.escriure(), cout << endl;
        cin >> op;
    }
}
