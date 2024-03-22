#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;


typedef pair<int, int> ArcP;        // arc amb pes
typedef vector< vector<ArcP> > GrafP;  // graf amb pesos
const int infinit = INT_MAX;

void llegir(GrafP& G, int m){
    for (int i = 0; i < m; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        G[x].push_back({c,y});
    }
}

void dijkstra(const GrafP& G, int ini, int fin, vector<int>& dist, vector<int>& prev){   
    priority_queue<ArcP, vector<ArcP>, greater<ArcP> > Q;
    Q.push({0,ini});
    dist[ini] = 0;
    
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
                    prev[nou] = u;
                }
            }
        }
    }
}

void escriu_camino(const vector<int>& c, int ini, int fin) {
	if (ini != fin) {
		escriu_camino(c, ini, c[fin]);
		cout << c[fin] << ' ';
	}
}

int main(){
    
    int n, m;
    
    while (cin >> n >> m){
        GrafP G(n);
        
        llegir(G, m);
        
        int ini,fin;
        cin >> ini >> fin;
        vector<int> prev(n, -1);
        vector<int> dist(n, infinit);
        dijkstra(G, ini, fin, dist, prev);

        if (dist[fin] != infinit)  {
			escriu_camino(prev, ini, fin);
			cout << fin << endl;
		}
		else cout << "no path from " << ini << " to " << fin << endl;
    }
    
}