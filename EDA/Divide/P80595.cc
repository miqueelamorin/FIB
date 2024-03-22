#include <iostream>
#include <vector>
using namespace std;

int inv(vector<int>& v, int esq, int dre){
    if (esq >= dre) return 0;
    int m = (esq+dre)/2;
    int inv1 = inv(v, esq, m);
    int inv2 = inv(v, m+1, dre);

    vector<int> w(dre-esq+1);
    int i = esq;
    int j = m+1;
    int k = 0;
    int inv3 = 0;
    while(i <= m and j <= dre) {
        if(v[i] <= v[j]) w[k++] = v[i++];
        else {
            w[k++] = v[j++];
            inv3 += m+1 - i;
            }
    }

    while(i <= m) w[k++] = v[i++];
    while (j <= dre) w[k++] = v[j++];
    for(k = 0; k < dre-esq+1; ++k) v[esq+k] = w[k];
    return inv1+inv2+inv3;
}

int main() {
    int n;
    while(cin >> n){
        vector<int> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];
        cout << inv(v, 0, n-1) << endl;
    }
}
