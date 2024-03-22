#include <iostream>
#include <vector>
using namespace std;

bool seguent(char l, char candidata){
    return (l+1 == candidata);
}

void forbidden(int n, int idx, const string& letters, vector<int>& visited, string& sol){
    if (idx == n) cout << sol << endl;
    else {
        for (int i = 0; i < n; ++i){
            if (not visited[i] and not seguent(sol[idx-1], letters[i])){
                sol[idx] = letters[i];
                visited[i] = true;
                forbidden(n,idx+1,letters,visited,sol);
                visited[i] = false;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    string letters(n,' ');
    for (int i = 0; i < n; ++i) letters[i] = 'a' + i;
    vector<int> visited(n,false);
    string sol(n,' ');
    forbidden(n,0,letters,visited,sol);
}