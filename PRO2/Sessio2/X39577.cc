#include "Estudiant.hh"
#include <iostream>
#include <vector>
using namespace std;


int main() {
    int m, n, s;
    cin >> m >> n >> s;
    vector<bool> assig(n, false);
    int nassig;
    for (int i = 0; i < s; ++i){
        cin >> nassig;
        assig[nassig-1] = true;
    }
    for (int i = 0; i < m; ++i) {
        int dni;
        cin >> dni;
        Estudiant est(dni);
        double suma = 0;
        for (int j = 0; j < n; ++j) {
            double nota;
            cin >> nota;
            if (assig[j]) suma += nota;
        }
        est.afegir_nota(suma/s);
        est.escriure();
    }
}
