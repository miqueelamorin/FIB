#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector < vector <int> > Graph;

Graph llegir(int vertices, vector<int>& degrees){
    int edges;
    cin >> edges;
    int vertex, adjacent;
    Graph g(vertices);
    for (int i = 0; i < edges; ++i){
        cin >> vertex >> adjacent;
        g[vertex].push_back(adjacent);
        ++degrees[adjacent];
    }
    return g;
}

bool es_ciclic(const Graph& g, vector<int>& degrees){
    queue<int> cua; 

    for (int i = 0; i < g.size(); ++i) if (degrees[i] == 0) cua.push(i);
    int tractats = 0;

    while(not cua.empty()){
        int act = cua.front();
        ++tractats;
        cua.pop();
        for (int nou : g[act]){
            --degrees[nou];
            if (degrees[nou] == 0) cua.push(nou);
        }
    }
    return (tractats != g.size());
}


int main(){
    int vertices;
    while(cin >> vertices){
        vector <int> degrees(vertices);
        Graph g = llegir(vertices, degrees);
        cout << (es_ciclic(g,degrees) ? "yes" : "no") << endl;
    }
}