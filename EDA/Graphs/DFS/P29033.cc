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

bool buscar_color(const Graph& g, int u, vector <int>& color, int antec, int col, vector <bool>& visited){
    bool imposs = false;

    if (visited[u]) {
        imposs = (color[u] == color[antec]);
    }
    else {
        color[u] = col%2;
        visited[u] = true;
        for (int i = 0; i < g[u].size() and not imposs; ++i) {
            if (g[u][i] != antec) imposs = buscar_color(g, g[u][i], color, u, col+1, visited);
        }

    }
    return imposs;
}

bool dfs(const Graph& g){
    vector<int> color(g.size(), -1);
    vector<bool> visited(g.size(), false);
    int i = 0;
    bool impossible = false;

    while (i < g.size() and not impossible) {
        if (not visited[i]){
            impossible = buscar_color(g, i, color, -1, 0, visited);
        }
        ++i;
    }
    return impossible;
}

int main (){
    int n, m;
    while(cin >> n >> m){
        Graph g(n);
        llegir(g, n, m);

        if (dfs(g)) cout << "no" << endl;
        else cout << "yes" << endl;
    }
}
