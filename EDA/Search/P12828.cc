#include <iostream>
#include <vector>
using namespace std;

void escriu(const vector<int>& A){
    cout << A[0];
    for (int i=1; i < A.size(); ++i) cout << ' ' << A[i];
    cout << endl;
}

void binari(vector<int>& A, int i) {
    if (i == A.size()) escriu(A); 
    else {
        A[i] = 0; 
        binari(A,i+1);
        A[i] = 1; 
        binari(A,i+1); 
    }
}

int main() { 
    int n;
    cin >> n;
    vector<int> A(n); 
    binari(A,0);
}