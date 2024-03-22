#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void moneda(int idx, int v_act, int v_final, vector<int> &numeros, int& veces, vector<int> used_times) {
    if (v_act == v_final) ++veces;
    else{
        for (int i = idx; i < numeros.size(); ++i){
            if (used_times[i]<2 and v_act+numeros[i] <= v_final){
                ++used_times[i];
                v_act += numeros[i];
                moneda(i,v_act,v_final,numeros,veces,used_times);
                --used_times[i];
                v_act -= numeros[i];
            }
        }
    }
}

int main () {
    int x, n;
    while (cin >> x >> n) {
        vector<int> numeros(n);
        for (int i = 0; i < n; i++) cin >> numeros[i];
        
        int veces = 0;
        vector <int> used_times(n,0);
        moneda(0, 0, x, numeros, veces, used_times);
        cout << veces << endl;
    }
}