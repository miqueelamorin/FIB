#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int> > Matrix;

Matrix pow (const Matrix& M, int n, int m){
    Matrix M0(2, vector<int> (2));
    if (n == 0) {
        M0[0][0] = M0[1][1] = 1;
        M0[0][1] = M0[1][0] = 0;
        return M0;
    }
    else if (n == 1){
        M0[0][0] = M0[0][0]%m;
        M0[1][1] = M0[1][1]%m;
        M0[0][1] = M0[0][1]%m;
        M0[1][0] = M0[1][0]%m;
        return M0;
    }
    else {
        Matrix r (2, vector<int>(2));
        r = pow(M, n/2, m);
        M0[0][0] = ((r[0][0] * r[0][0])%m + (r[0][1] * r[1][0])%m)%m;
        M0[0][1] = ((r[0][0] * r[0][1])%m + (r[0][1] * r[1][1])%m)%m;
        M0[1][0] = ((r[0][0] * r[1][0])%m + (r[1][0] * r[1][1])%m)%m;
        M0[1][1] = ((r[1][0] * r[0][1])%m + (r[1][1] * r[1][1])%m)%m;

        if (n%2 == 0) return M0;
        else {
            M0[0][0] = ((M0[0][0] * M[0][0])%m + (M0[0][1] * M[1][0])%m)%m;
            M0[0][1] = ((M0[0][0] * M[0][1])%m + (M0[0][1] * M[1][1])%m)%m;
            M0[1][0] = ((M0[0][0] * M[1][0])%m + (M0[1][0] * M[1][1])%m)%m;
            M0[1][1] = ((M0[1][0] * M[0][1])%m + (M0[1][1] * M[1][1])%m)%m;
            return M0;
        }
    }
}

int main() {
    Matrix M(2, vector<int> (2));
    
    while (cin >> M[0][0]){
        cin >> M[0][1] >> M[1][0] >> M[1][1];
        int n, m;
        cin >> n >> m;

        M = pow(M, n, m);

        cout << M[0][0] << ' ' << M[0][1] << endl;
        cout << M[1][0] << ' ' << M[1][1] << endl;
        cout << "----------" << endl;
    }
}
