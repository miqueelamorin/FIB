#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const string letters = "xyz";

void xyz(int n, int c, string& sol, int consecutive, int idx){
    if (idx == n) cout << sol << endl;
    else{
        for (int i = 0; i < 3; ++i){
            if(idx == 0 or sol[idx-1] != letters[i]){
                sol[idx] = letters[i];
                xyz(n,c,sol,1,idx+1);
            }
            else if(consecutive < c){
                sol[idx] = letters[i];
                xyz(n,c,sol,consecutive+1,idx+1);
            }
        }
    }
}

int main(){
    int n, c;
    while(cin >> n >> c){
        string sol(n,' ');
        xyz(n,c,sol,0,0);
        cout << "--------------------" << endl;
    }
}