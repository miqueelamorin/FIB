#include <iostream>
#include <vector>
using namespace std;

int fixed_points(vector<int>& v, int a, int esq, int dre) {
    if (esq > dre) return -1;
    int m = (esq+dre)/2;
    if (v[m] < m + 1 - a) return fixed_points(v,a,m+1,dre);
	if (v[m] > m + 1 - a) return fixed_points(v,a,esq,m-1);
	if (m > 0 and v[m-1] == m - a) return fixed_points(v,a,esq,m-1);
	return m + 1;

}

int main() {
    int nseq = 1;
    int n;
    while (cin >> n){
        vector<int> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];

        int m, a;
        cin >> m;

        cout << "Sequence #" << nseq << endl;
        for (int i = 0; i < m; ++i){
            cin >> a;
            int fp = fixed_points(v,a,0,n);
            if (fp == -1) cout << "no fixed point for " << a << endl;
            else cout << "fixed point for " << a << ": " << fp << endl;

        }
        cout << endl;
        ++nseq;
    }
}
