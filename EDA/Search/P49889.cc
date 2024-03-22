#include <iostream>
#include <vector>
#include <map>
using namespace std;

void escriu(const vector<char>& A){
    cout << A[0];
    for (int i=1; i < A.size(); ++i) cout << A[i];
    cout << endl;
}

void escriu_permutacions(vector<char>& A, int idx, vector<bool>& usatc, vector<bool>& usatv, const vector<char>& vowels, const vector<char>& consonants, bool vowel) {
    if (idx == A.size()) escriu(A); 
    else {
        if (vowel){
            for (int i = 0; i < consonants.size(); ++i){ 
                if (not usatc[i]){
                    A[idx] = consonants[i];
                    usatc[i] = true;
                    escriu_permutacions(A,idx+1,usatc,usatv,vowels,consonants,false); 
                    usatc[i] = false; // restaurem sota backtrack
                }
            }
        }
        else{
            for (int i = 0; i < vowels.size(); ++i){ 
                if (not usatv[i]){
                    A[idx] = vowels[i];
                    usatv[i] = true;
                    escriu_permutacions(A,idx+1,usatc,usatv,vowels,consonants,true); 
                    usatv[i] = false; // restaurem sota backtrack
                }
            }
        }
    }
}

int main() {
    int n; 
    cin >> n;
    vector<char> A(2*n);
    vector<char> vowels(n);
    vector<char> consonants(n);
    vector <bool> usatv(n,false);
    vector <bool> usatc(n,false);
    for (int i = 0; i < n; ++i) cin >> consonants[i];
    for (int i = 0; i < n; ++i) cin >> vowels[i];
    escriu_permutacions(A, 0, usatv, usatc, vowels, consonants, true); 
}