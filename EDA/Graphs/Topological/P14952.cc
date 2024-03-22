#include <vector>
#include <iostream>
#include <queue>

using namespace std;

typedef vector< vector<int> > Graph;

void llegir(Graph& g, int n, int m){
    int x, y;

    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        g[x].push_back(y);
    }
}

void ordenar_topologicament(const Graph& g, vector<int>& L){
    int n = int(g.size());
    priority_queue<int, vector<int>, greater<int>> cua;

    vector<int> ge(n, 0);

    for (int u = 0; u < n; ++u) {
        for (int i = 0; i < g[u].size(); ++i) {
            ++ge[g[u][i]];
        }
    }

    for (int u = 0; u < n; ++u) {
        if (ge[u] == 0) {
            cua.push(u);
        }
    }

    while (not cua.empty()) {
        int u = cua.top();
        cua.pop();
        L.push_back(u);
        for (int i = 0; i < g[u].size(); ++i) {
            int v = g[u][i];
            --ge[v];
            if (ge[v] == 0) {
                 cua.push(v);
            }
        }
    }
}

void imprimir(const vector<int>& ordre){
    for (int i = 0; i < ordre.size(); ++i) {
        if (i != 0) cout << ' ';
        cout << ordre[i];
    }
    cout << endl;
}

int main (){
    int n, m;
    while(cin >> n >> m){
        Graph g(n);
        llegir(g, n, m);

        vector <int> ordre;
        ordenar_topologicament(g, ordre);
        imprimir(ordre);
    }
}
