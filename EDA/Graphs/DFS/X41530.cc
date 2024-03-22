#include <vector>
#include <iostream>

using namespace std;

typedef vector< vector<int > > Graph;

void llegir(Graph& g, int n, int m){
    int x, y;

    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
}

bool buscar_cicle(const Graph& g, int u, vector <bool>& visitat, int antec){
    bool ciclo;
    if (visitat[u]) ciclo = true;
    else {
        visitat[u] = true;
        ciclo = false;
        for (int i = 0; i < g[u].size() and not ciclo; ++i) {
            if (g[u][i] != antec) ciclo = buscar_cicle(g, g[u][i], visitat, u);
        }
    }
    return ciclo;
}

int dfs(const Graph& g){
    int narbres = 0;
    vector<bool> visitat(g.size(), false);
    bool cicle = false;
    int i = 0;

    while (i < g.size() and not cicle) {
        if (not visitat[i]) {
            if (buscar_cicle(g, i, visitat, -1)) cicle = true;
            else ++narbres;
        }
        ++i;
    }
    if (cicle) narbres = -1;
    return narbres;
}

int main (){
    int n, m;
    while(cin >> n >> m){
        Graph g(n);
        llegir(g, n, m);
        int narbr = dfs(g);
        if (narbr == -1) cout << "no" << endl;
        else cout << narbr << endl;
    }
}
