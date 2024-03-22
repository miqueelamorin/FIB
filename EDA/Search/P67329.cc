#include <iostream>
#include <vector>
#include <string>
using namespace std;

void write(const vector<char> v){
    for (char w : v) cout << w;
    cout << endl;
}

void backtracking(int idx, vector<char>& sol, const vector<char>& DNA){
    if (idx == sol.size()) write(sol);
    else{
        for (int i = 0; i < DNA.size(); ++i){
            sol[idx] = DNA[i];
            backtracking(idx+1,sol,DNA);
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<char> DNA{'A','C','G','T'};
    vector<char> sol(n);
    backtracking(0,sol,DNA);
}