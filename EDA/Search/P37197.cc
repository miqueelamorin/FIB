#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

typedef vector < vector <int> > Graph;

Graph read(int vertices, map<char,int>& traduccio){
    int edges;
    cin >> edges;
    Graph g(vertices, vector<int>(vertices,false));
    for (int i = 0; i < edges; ++i){
        string especie;
        cin >> especie;
        int especie1 = traduccio[especie[0]];
        int especie2 = traduccio[especie[1]];
        g[especie1][especie2] = true;
        g[especie2][especie1] = true;
    }
    return g;
}

void escriure(const vector<int>& s, const vector<char>& t){
    for (int i = 0; i < s.size(); ++i) {
        cout << t[s[i]];
    }
    cout << endl;
}

void backtracking(int idx, const Graph& incomp, const vector<char>& destraduccio, vector<int>& used, vector<int>& solution){
    if (idx == solution.size()) escriure(solution,destraduccio);
    else{
        for (int i = 0; i < destraduccio.size(); ++i){
            if (not used[i] and (idx == 0 or not incomp[solution[idx-1]][i])){
                used[i] = true;
                solution[idx] = i;
                backtracking(idx+1,incomp,destraduccio,used,solution);
                used[i] = false;
            } 
        }
    }
}

int main(){
    int vertices;
    cin >> vertices;

    map<char,int> traduccio;
    vector<char> destraduccio(vertices);
    for (int i = 0; i < vertices; ++i) {
        char especie;
        cin >> especie;
        traduccio[especie] = i;
        destraduccio[i] = especie;
    }

    Graph incomp = read(vertices, traduccio);

    vector<int> used(vertices, false);
    vector<int> solution(vertices);
    backtracking(0,incomp,destraduccio,used,solution);
}