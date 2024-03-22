#include <vector>
#include <iostream>
#include <queue>
#include <map>
using namespace std;

typedef vector< vector <int> > Graph;

Graph read_graph(int vertices, map<string,int>& translate){
    int edges;
    cin >> edges;
    Graph g(vertices);
    for (int i = 0; i < edges; ++i){
        string task1, task2;
        cin >> task1 >> task2;
        g[translate[task1]].push_back(translate[task2]);
    }
    return g;
}

void imprimir(const vector<int>& v, const vector<string>& de_translate){
    for (int i = 0; i < v.size(); ++i) cout << de_translate[v[i]];
    cout << endl;
}

void ordenar_topologicament(Graph& g, const vector<string> de_translate){
    int n = g.size();
    vector<int> result;
    priority_queue<int, vector<int>, greater<int>> cua;
    vector<int> graus(n,0);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < g[i].size(); ++j) ++graus[g[i][j]];
    
    for (int i = 0; i < n; ++i) if (graus[i] == 0) cua.push(i);
    
    while(not cua.empty()){
        int vertex = cua.top();
        cua.pop();
        result.push_back(vertex);
        for (int i = 0; i < g[vertex].size(); ++i){
            --graus[g[vertex][i]];
            if (graus[g[vertex][i]] == 0) cua.push(g[vertex][i]);
        }
    }
    if (result.size() != n) cout << "NO VALID ORDERING" << endl; 
    else imprimir(result, de_translate);
}

int main(){
    int vertices;
    while (cin >> vertices){
        map<string,int> translate;
        vector <string> de_translate(vertices);
        for (int i = 0; i < vertices; ++i) {
            string task;
            cin >> task;
            translate[task] = 0;
        }
        int i = 0;
        for (auto& it : translate) {
            it.second = i;
            de_translate[i] = it.first;
            ++i;
        }
        Graph g = read_graph(vertices, translate);
        ordenar_topologicament(g, de_translate);
    }
}
