#include <vector>
#include <iostream>
using namespace std;

typedef vector<vector<int> > Matrix;

void min_max(const Matrix& mat, int& minimum, int& maximum){
    int f = mat.size();
    int c = mat[0].size();
    minimum = maximum = mat[0][0];
    for(int i = 0; i < f; ++i){
        for(int j = 0; j < c; ++j){
            if(mat[i][j] < minimum) minimum =  mat[i][j];
            if(mat[i][j] > maximum) maximum =  mat[i][j];
        }
    }
}

void leer_matrix(Matrix& m, int f, int c){
    m = Matrix(f, vector<int>(c));
    for (int i = 0; i < f; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> m[i][j];
            }
    }
}

void Control_C401B(Matrix& m){
    int f, c;
    int max, min;
    int diferencia = -1;
    int numerolinea = 0, maxlinea = 0;
    while (cin >> f >> c) {
        leer_matrix(m,f,c);
        min_max(m, min, max);
        ++numerolinea;
        
        if (max - min > diferencia){
            diferencia = max - min;
            maxlinea = numerolinea;
        }
    }
    cout << "la diferencia maxima es " << diferencia << endl;
    cout << "la primera matriu amb aquesta diferencia es la " << maxlinea << endl;
}

int main ()
{
    Matrix m;
    Control_C401B(m);
}
