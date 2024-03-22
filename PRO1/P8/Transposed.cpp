#include <vector>
#include <iostream>
using namespace std;

typedef vector< vector<int> > Matrix;

void swap(int& x, int& y){
    int z = y;
    y = x;
    x = z;
}

void transpose(Matrix& M){
    int n = M.size();
    for (int i = 0; i < n - 1; ++i){
        for (int j = i + 1; j < n; ++j){
           swap(M[i][j],M[j][i]);
           
        }
    }
    
}


int main ()
{
    int n;
    while (cin >> n) {
        vector< vector<int> > M(n, vector<int>(n));
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                cin >> M[i][j];
        }   }
        transpose(M);
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                cout << M[i][j] << " ";
            }
            cout << endl;
        }   
        cout << endl;
    }
}
