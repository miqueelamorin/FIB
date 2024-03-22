#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<int> Row;
typedef vector<Row> Matrix;

Matrix leer_matrix(int f, int c){
    Matrix m(f, Row(c));
    for(int i = 0; i < f; ++i){
        for(int j = 0; j < c; ++j){
            cin >> m[i][j];
        }
    }
    return m;
}

void Rows_and_columns(Matrix& m){
    string x;
    while (cin >> x){
        if (x == "row"){
           int y;
           cin >> y;
           cout << "row " << y << ':';
           int aux = m[0].size();
           for (int i = 0; i < aux; ++i) cout << ' ' << m[y - 1][i];
           cout << endl;
        }
        else if (x == "column"){
            int y;
            cin >> y;
            cout << "column " << y << ':';
            int aux = m.size();
            for (int i = 0; i < aux; ++i) cout << ' ' << m[i][y - 1];
            cout << endl;
        }
        else if (x == "element"){
            int y, z;
            cin >> y >> z;
            cout << "element " << y << ' ' << z << ": " << m[y - 1][z - 1] << endl;
        }
    }
}

int main () {
    int f, c;
    cin >> f >> c;
    Matrix M = leer_matrix(f, c);
    Rows_and_columns(M); 
}