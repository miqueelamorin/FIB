#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int> > Matrix;

int mult(const Matrix& a, const Matrix& b, int f, int c)
{
    int size = a.size();
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += a[f][i] * b[i][c];
    }
    return sum;
}

Matrix product(const Matrix& a, const Matrix& b)
{
    int size = a.size();
    Matrix axb(size, vector<int>(size));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            axb[i][j] = mult(a, b, i, j);
        }   
    }
    return axb;
}

int main()
{
    int n;
    while (cin >> n) {
        Matrix A(n, vector<int>(n));
        Matrix B(n, vector<int>(n));
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                cin >> A[i][j];
            }   
        }
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                cin >> B[i][j];
            }
        }
        Matrix C = product(A,B);
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                cout << C[i][j] << " ";
            }
            cout << endl;
        }   
        cout << endl;
    }

}