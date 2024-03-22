#include "Estudiant.hh"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const Estudiant& a, const Estudiant& b) {
    if (a.consultar_nota() != b.consultar_nota()) return a.consultar_nota() > b.consultar_nota();
    return a.consultar_DNI() < b.consultar_DNI();
}

void imprimir_vector(const vector<Estudiant>& vest){
    int size = vest.size();
    for (int i = 0; i < size; ++i){
        vest[i].escriure();
    }
}

int main() {
    int m, n, s;
    cin >> m >> n >> s;
    vector<bool> assig(n, false);
    int nassig;
    for (int i = 0; i < s; ++i){
        cin >> nassig;
        assig[nassig-1] = true;
    }
    vector<Estudiant> vest(m);
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
        vest[i] = est;
    }
    sort(vest.begin(),vest.end(),cmp);
    imprimir_vector(vest);
}
