#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector< vector<int > > Graph;

Graph llegir(int n, int m, vector<int>& degrees){
    Graph G(n);
    int vertex, vertex2;
    for (int i = 0; i < m; ++i){
        cin >> vertex >> vertex2;
        G[vertex].push_back(vertex2);
        ++degrees[vertex2];
    }
    return G;
}

void escriure(vector <int> ordenacio){
    cout << ordenacio[0];
    for (int i = 1; i < ordenacio.size(); ++i) cout << ' ' << ordenacio[i];
    cout << endl;
}

void topological_rec(const Graph& G, vector<int>& visitat, vector<int>& degrees,vector<int>& ordre, int pos){
    if (pos == G.size()) escriure(ordre);
    else{
        for (int v = 0; v < G.size(); ++v) {
            if (degrees[v] == 0) {// and not visitat[v]) {
                ordre[pos] = v;
                //visitat[v] = true;
                --degrees[v];
                for (int i = 0; i < G[v].size(); ++i) --degrees[G[v][i]];
                topological_rec(G,visitat,degrees,ordre,pos+1);
                //visitat[v] = false;
                ++degrees[v];
                for (int i = 0; i < G[v].size(); ++i) ++degrees[G[v][i]];
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector <int> degrees(n,0); 
    Graph G = llegir(n,m,degrees);

    vector <int> visitat(n, false);
    vector <int> ordre(n);

    topological_rec(G,visitat,degrees,ordre,0);
}