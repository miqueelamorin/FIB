#include <iostream>
#include <vector>
#include <queue>
using namespace std;


typedef pair<int, int> ArcP;        // arc amb pes
typedef vector< vector<ArcP> > GrafP;  // graf amb pesos

void llegir(GrafP& G, int m){
    int x, y, p;

    for (int i = 0; i < m; ++i) {
        cin >> x >> y >> p;
        G[x].push_back(ArcP(p,y));
    }
}

int dijkstra(const GrafP G, int u, int v){
    int n = int(G.size());

    vector<int> cost(n, -1);
    vector<bool> visitat(n, false);
    priority_queue<ArcP, vector<ArcP>, greater<ArcP> > Q;
    
    Q.push(ArcP(0,u));
    cost[u] = 0;

    while (not Q.empty()) {
        int act = Q.top().second; 
        Q.pop();

        if (not visitat[act]) {
            visitat[act] = true;

            for (int i = 0; i < int (G[act].size ()); ++i) {
                
                int nou = G[act][i].second;
                int c = G[act][i].first;
                if (cost[nou] == -1 or cost[nou] > cost[act] + c) {
                    cost[nou] = cost[act] + c;
                    Q.push (ArcP(cost[nou], nou));
                }
            }
        }
    }
    return cost[v];
}

int main(){
    
    int n, m;
    
    while (cin >> n >> m){
        GrafP G(n);
        
        llegir(G, m);
        
        int u,v;
        cin >> u >> v;
        int ret = dijkstra(G, u, v);
        
        if (ret < 0) cout << "no path from " << u << " to " << v << endl;
        else cout << ret << endl;
    }
    
}