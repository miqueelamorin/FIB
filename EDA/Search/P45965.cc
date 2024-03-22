#include <iostream>
#include <vector>
using namespace std;

void escriu(const vector<int>& A){
    cout << A[0];
    for (int i=1; i < A.size(); ++i) cout << ' ' << A[i];
    cout << endl;
}

void binari(vector<int>& A, int idx, int z, int u, int k) {
    if (idx == A.size()) escriu(A); 
    else {
        if (z < A.size() - k) A[idx] = 0, binari(A,idx+1,z+1,u,k);
        if (u < k) A[idx] = 1, binari(A,idx+1,z,u+1,k);
    } 
}

int main() { 
    int n, k;
    cin >> n >> k;
    vector<int> A(n); 
    binari(A,0,0,0,k);
}