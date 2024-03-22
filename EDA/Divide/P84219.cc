#include <iostream>
#include <vector>
using namespace std;

int first_occurrence_rec(double x, const vector<double>& v, int i, int j){
    if (i > j) return -1;
    int m = (i+j)/2;
    if (v[m] == x) {
        if (m == 0 or v[m-1] != x) return m;
        else return first_occurrence_rec(x,v,i,m - 1);
    }
    else if (x < v[m]) return first_occurrence_rec(x,v,i,m - 1);
    else return first_occurrence_rec(x,v,m + 1,j);
}

int first_occurrence(double x, const vector<double>& v){
    return first_occurrence_rec(x,v,0,v.size()-1);
}

int main() {
    int n;
    while (cin >> n) {
        vector<double> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int t;
        cin >> t;
        while (t--) {
            double x;
            cin >> x;
            cout << first_occurrence(x, V) << endl;
        }
    }
}
