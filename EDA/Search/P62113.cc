#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void escribir(vector<int> &solucion, int tope, int x) {
    cout << x << " = ";
    bool primer = true;
    for (int i = 0; i < tope; i++) {
        if (solucion[i] != 0) {
            if (primer) {
                primer = false;
                if (i%2 != 0) cout << solucion[i] << 'p';
                else cout << solucion[i];
            }
            else {
                if (i%2 != 0) cout << " + " << solucion[i] << 'p';
                else cout << " + " << solucion[i];
            }
        }
    }
    cout << endl;
}

void moneda(int idx, int v_act, int v_final, vector<int> &numeros, vector<int> &solucion) {
    int n = numeros.size();
    if (v_act == v_final) escribir(solucion, idx, v_final);
    else if (idx < 2*n && v_act < v_final) {     //si it no mida total   //si valor actual < canvi
            int aux = solucion[idx];  //agafem lultim valor
            solucion[idx] = numeros[idx/2];     //el canviem per l'altre valor
            v_act += numeros[idx/2];          //ho sumem al valor actual
            moneda(idx + 1, v_act, v_final, numeros, solucion);
            v_act -= numeros[idx/2];          //el restem
            solucion[idx] = aux;              //restaurem valor
            moneda(idx + 1, v_act, v_final, numeros, solucion);
    }
}

int main () {
    int x, n;
    while (cin >> x >> n) {
        vector<int> numeros(n);
        for (int i = 0; i < n; i++) cin >> numeros[i];
        sort(numeros.begin(), numeros.end());
        vector<int> solucion(2*n);
        moneda(0, 0, x, numeros, solucion);
        cout << "----------" << endl;
    }
}
