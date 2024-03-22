#include <iostream>
#include <vector>
using namespace std;

vector<int> operator *(const vector<int>& perm1, const vector<int>& perm2){
    vector<int> result(perm1.size());
    for (int i = 0; i < perm1.size(); ++i){
        result[i] = perm2[perm1[i]];
    }
    return result;
}

vector<int> power_perm(const vector<int>& perm, int k){
    if (k == 1) return perm;
    vector<int> result(perm.size());
    if (k == 0) {
        for (int i = 0; i < perm.size(); ++i) result[i] = i;
        return result;
    }
    
    result = power_perm(perm,k/2);
    if (k%2 == 0) return result*result;
    else return result*result*perm;

}

void imprimir(const vector<int> v){
    cout << v[0];
    for (int i = 1; i < v.size(); ++i) cout << ' ' << v[i];
    cout << endl;
}

int main(){
    int n;
    
    while(cin >> n){
        vector<int> perm(n);
        for (int i = 0; i < n; ++i) cin >> perm[i]; 
        int k;
        cin >> k;
        imprimir(power_perm(perm,k));
    }
}