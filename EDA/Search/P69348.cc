#include <iostream>
#include <vector>
using namespace std;

void escriu(const vector<int>& A){
    cout << '(' << A[0];
    for (int i=1; i < A.size(); ++i) cout << ',' << A[i];
    cout << ')' << endl;
}

void escriu_permutacions2(int n, vector<int>& A, int idx, vector<bool>& usat) {
    if (idx == A.size()) escriu(A); 
    else {
        for (int k = 1; k <= n; ++k) { 
            if (not usat[k]) {
                A[idx] = k;
                usat[k] = true; 
                escriu_permutacions2(n,A,idx+1,usat); 
                usat[k] = false; // restaurem sota backtrack
            } 
        }
    } 
}

int main() {
    int n; cin >> n;
    vector<int> A(n);
    vector<bool> usat(n+1,false); 
    escriu_permutacions2(n,A,0,usat); 
}