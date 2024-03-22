#include <iostream>
#include <vector>
using namespace std;


void insereix(vector<double>& v){
    int i = v.size() - 1;
    double x = v[i];
    int j = i;
    while (j > 0 and v[j - 1] > x) {
        v[j] = v[j - 1];
        --j;
    }
    v[j] = x;   
}


int main() {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(4);
    int n;
    while (cin >> n) {
        vector<double> V(n);
        for (int i=0; i<n; ++i) {
            cin >> V[i];
        }
        insereix(V);
        for (int i=0; i<n; ++i) {
            cout << " " << V[i];
        }
        cout << endl;
    }
}
