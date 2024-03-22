#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> Row;
typedef vector<Row> Matrix;

Matrix read_mat(int f, int c) {
    Matrix mat(f, Row(c));
    for (int i = 0; i < f; ++i)
        for (int j = 0; j < c; ++j) 
            cin >> mat[i][j];
    return mat;
}

bool diagonal(const Matrix& m, int fpos, int cpos){
    int rows = m.size();
    int columns = m[0].size();
    int prev = m[fpos][cpos];
    int i = fpos + 1;
    int j = cpos + 1;
    while (i < rows and j < columns) {
        if (m[i][j] <= prev) return false;
        prev = m[i][j];
        ++i;
        ++j;
    }
    prev = m[fpos][cpos];
    i = fpos - 1;
    j = cpos + 1;
    while (i >= 0 and j < columns) {
        if (m[i][j] <= prev) return false;
        prev = m[i][j];
        --i;
        ++j;
    }
    prev = m[fpos][cpos];
    i = fpos + 1;
    j = cpos - 1;
    while (i < rows and j >= 0) {
        if (m[i][j] <= prev) return false;
        prev = m[i][j];
        ++i;
        --j;
    }
    prev = m[fpos][cpos];
    i = fpos - 1;
    j = cpos - 1;
    while (i >= 0 and j >= 0) {
        if (m[i][j] <= prev) return false;
        prev = m[i][j];
        --i;
        --j;
    }
    return true;
}

int main() {
    int f, c;
    while (cin >> f >> c) {
        Matrix m = read_mat(f, c);
        int fpos, cpos;
        cin >> fpos >> cpos;
        if (diagonal(m, fpos, cpos)) cout << "si" << endl;
        else cout << "no" << endl;
    }
}