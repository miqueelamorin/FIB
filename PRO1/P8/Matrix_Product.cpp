#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int> > Matrix;

int mult(const Matrix& a, const Matrix& b, int f, int c)
{
    int size = a[0].size();
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += a[f][i] * b[i][c];
    }
    return sum;
}

Matrix product(const Matrix& a, const Matrix& b)
{
    int rows = a.size();
    int columns = b[0].size();
    Matrix axb(rows, vector<int>(columns));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            axb[i][j] = mult(a, b, i, j);
        }   
    }
    return axb;
}

int main()
{
    int p, q, r;
    while (cin >> p >> q >> r) {
        Matrix A(p,vector<int>(q));
        Matrix B(q,vector<int>(r));
        for (int i=0; i<p; ++i) {
            for (int j=0; j<q; ++j) {
                cin >> A[i][j];
        }   }
        for (int i=0; i<q; ++i) {
            for (int j=0; j<r; ++j) {
                cin >> B[i][j];
        }   }
        Matrix C = product(A,B);
        for (int i=0; i<p; ++i) {
            for (int j=0; j<r; ++j) {
                cout << C[i][j] << " ";
            }
            cout << endl;
        }   
        cout << endl;
    }
}