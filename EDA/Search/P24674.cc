#include <iostream>
#include <vector>
#include <map>
using namespace std;

void escriu(const vector<string>& A){
    cout << '(' << A[0];
    for (int i=1; i < A.size(); ++i) cout << ',' << A[i];
    cout << ')' << endl;
}

void escriu_permutacions2(vector<string>& A, int idx, vector<bool>& usat, const vector<string>& input) {
    if (idx == A.size()) escriu(A); 
    else {
        for (int i = 0; i < input.size(); ++i){ 
            if (not usat[i]) {
                A[idx] = input[i];
                usat[i] = true; 
                escriu_permutacions2(A,idx+1,usat,input); 
                usat[i] = false; // restaurem sota backtrack
            } 
        }
    } 
}

int main() {
    int n; 
    cin >> n;
    vector<string> A(n);
    vector<string> input(n);
    vector <bool> usat(n,false);
    for (int i = 0; i < n; ++i) cin >> input[i];
    escriu_permutacions2(A,0,usat,input); 
}