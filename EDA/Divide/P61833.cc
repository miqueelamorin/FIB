#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int> > Matrix;

void pow (Matrix& M, const Matrix& M0, int n, int m){
    if (n == 0) {
        M[0][0] = M[1][1] = 1;
        M[0][1] = M[1][0] = 0;
    }
    else if (n == 1){
        M[0][0] = M[0][0]%m;
        M[1][1] = M[1][1]%m;
        M[0][1] = M[0][1]%m;
        M[1][0] = M[1][0]%m;
    }
    else {
        pow(M, M0, n/2, m);
        Matrix r (2, vector<int>(2));
        r[0][0] = ((M[0][0] * M[0][0])%m + (M[0][1] * M[1][0])%m)%m;
        r[0][1] = ((M[0][0] * M[0][1])%m + (M[0][1] * M[1][1])%m)%m;
        r[1][0] = ((M[0][0] * M[1][0])%m + (M[1][0] * M[1][1])%m)%m;
        r[1][1] = ((M[1][0] * M[0][1])%m + (M[1][1] * M[1][1])%m)%m;

        if (n%2 == 0) M = r;
        else {
            vector< vector<int> > s (2, vector<int>(2));
            s[0][0] = ((r[0][0] * M0[0][0])%m + (r[0][1] * M0[1][0])%m)%m;
            s[0][1] = ((r[0][0] * M0[0][1])%m + (r[0][1] * M0[1][1])%m)%m;
            s[1][0] = ((r[0][0] * M0[1][0])%m + (r[1][0] * M0[1][1])%m)%m;
            s[1][1] = ((r[1][0] * M0[0][1])%m + (r[1][1] * M0[1][1])%m)%m;
            M = s;
        }
    }
}

int main() {
    Matrix M(2, vector<int> (2));
    
    while (cin >> M[0][0]){
        cin >> M[0][1] >> M[1][0] >> M[1][1];
        int n, m;
        cin >> n >> m;
        Matrix M0(2, vector<int> (2));
        M0 = M;

        pow(M, M0, n, m);

        cout << M[0][0] << ' ' << M[0][1] << endl;
        cout << M[1][0] << ' ' << M[1][1] << endl;
        cout << "----------" << endl;
    }
}
