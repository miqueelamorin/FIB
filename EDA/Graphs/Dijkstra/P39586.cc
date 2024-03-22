#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;


typedef pair<int, int> ArcP;        // arc amb pes
typedef vector< vector<ArcP> > GrafP;  // graf amb pesos
const int infinit = INT_MAX;


void llegir(GrafP& G, int m){
    int x, y, p;

    for (int i = 0; i < m; ++i) {
        cin >> x >> y >> p;
        G[x].push_back(ArcP(p,y));
    }
}

void dijkstra(const GrafP& G, int ini, int fin, vector<int>& dist, vector<int>& ways){   
    priority_queue<ArcP, vector<ArcP>, greater<ArcP> > Q;
    Q.push({0,ini});
    dist[ini] = 0;
    ways[ini] = 1;
    
    int n = G.size();
    vector<bool> visitat(n, false);

    while (not Q.empty()) {
        int u = Q.top().second; 
        Q.pop();

        if (u == fin) return;
        if (not visitat[u]) {
            visitat[u] = true;

            for (ArcP uv: G[u]) {
                int nou = uv.second;
                int c = uv.first;

                if (dist[nou] > dist[u] + c) {
                    dist[nou] = dist[u] + c;
                    Q.push ({dist[nou], nou});
                    ways[nou] = ways[u];
                }
                else if (dist[nou] == dist[u] + c) ways[nou] += ways[u];
            }
        }
    }
}

int main(){
    
    int n, m;
    
    while (cin >> n >> m){
        GrafP G(n);
        
        llegir(G, m);
        
        int ini,fin;
        cin >> ini >> fin;
        vector<int> ways(n, -1);
        vector<int> dist(n, infinit);
        dijkstra(G, ini, fin, dist, ways);
        
        if (dist[fin] != infinit)  {
            cout << "cost " << dist[fin] << ", " << ways[fin] << " way(s)" << endl;
		}
		else cout << "no path from " << ini << " to " << fin << endl;
    }
    
}