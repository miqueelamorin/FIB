#include <iostream>
#include <vector>
using namespace std;

void escriu (const vector<int>& t, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) cout << (t[i] == j ? "Q" : ".");
        cout << endl;
    }
}

bool reines (int i,vector<int>& t,vector<int>& mc,vector<int>& md1,vector<int>& md2, int n) {
    if (i == n) {
        escriu(t,n); 
        return true;
    }
    else {
        for (int j = 0; j < n; ++j){
            if (not mc[j] and not md1[i+j] and not md2[i-j + n-1]){
                t[i] = j;
                mc[j] = md1[i+j] = md2[i-j + n-1] = true;
                if (reines(i+1,t,mc,md1,md2, n)) return true;
                mc[j] = md1[i+j] = md2[i-j + n-1] = false;
            }
        }
        return false;
    }
}
    
int main (){
    int n;
    cin >> n;
    vector<int> t(n);
    vector<int> mc(n, false);
    vector<int> md1(2*n-1, false);
    vector<int> md2(2*n-1, false);
    if (not reines(0,t,mc,md1,md2, n)) cout << "NO SOLUTION" << endl;;
}