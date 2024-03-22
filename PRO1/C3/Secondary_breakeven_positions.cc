#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> Fila;
typedef vector<Fila> Matriz;

// Pre: f > 0, c > 0; there is an integer matrix in the input channel
// Post: returns the integer matrix read from the input channel
Matriz read_matriz(int f, int c) {
    Matriz m(f, Fila(c));
    for (int i = 0; i < f; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> m[i][j];
        }
    }
    return m;
}

int sum_submatriz(const Matriz& m, int i0, int j0, int i1, int j1) {
    int sum = 0;
    for (int i = i0; i <= i1; ++i) {
        for (int j = j0; j <= j1; ++j) {
            sum += m[i][j];
        }
    } 
    return sum;
}

int main() {
    int f, c;
    cin >> f >> c;
    Matriz m = read_matriz(f, c);
    int i, j;
    while (cin >> i >> j) {
        int dret = sum_submatriz(m,0,j,i,c-1);
        int esq = sum_submatriz(m,i,0,f-1,j);
        if (dret == esq) cout << "si: " << dret << endl;
        else cout << "no: " << dret << ", " << esq << endl;
    }
}