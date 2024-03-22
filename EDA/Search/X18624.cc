#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool no_vocal(char letter){
    return (letter != 'a' and letter != 'e' and letter != 'i' and letter != 'o' and letter != 'u');
}

void ruins(int n, const vector<char>& letters, vector<char>& sol){
    if (sol.size()==n){
        for (char l : sol) cout << l;
        cout << endl;
    }
    else{
        for (int i = 0; i < letters.size(); ++i){ 
            if (sol.size() == 0 or (no_vocal(letters[i]) or no_vocal(sol.back()))){
                sol.push_back(letters[i]);
                ruins(n,letters,sol);
                sol.pop_back();
            }
        }
    }
}

int main(){
    int n, m;
    while (cin >> n >> m){
        vector<char> letters(m);
        for (int i = 0; i < m; ++i) cin >> letters[i];
        sort(letters.begin(),letters.end());
        vector<char> sol;
        ruins(n,letters,sol);
        cout << "----------" << endl;
    }
}