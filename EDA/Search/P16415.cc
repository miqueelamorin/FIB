#include <iostream>
#include <vector>
using namespace std;

int reines (int i,vector<int>& t,vector<int>& mc,vector<int>& md1,vector<int>& md2, int n) {
    if (i == n) return 1;
    else {
        int res = 0;
        for (int j = 0; j < n; ++j){
            if (not mc[j] and not md1[i+j] and not md2[i-j + n-1]){
                t[i] = j;
                mc[j] = md1[i+j] = md2[i-j + n-1] = true;
                res += reines (i+1,t,mc,md1,md2, n);
                mc[j] = md1[i+j] = md2[i-j + n-1] = false;
            }
        }
        return res;
    }
}
    
int main (){
    int n;
    cin >> n;
    vector<int> t(n);
    vector<int> mc(n, false);
    vector<int> md1(2*n-1, false);
    vector<int> md2(2*n-1, false);
    cout << reines(0,t,mc,md1,md2, n) << endl;
}