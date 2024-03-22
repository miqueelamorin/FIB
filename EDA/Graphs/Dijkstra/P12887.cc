#include <iostream>
#include <vector>
#include <queue>
using namespace std;


typedef pair<int, int> ArcP;        // arc amb pes
typedef vector< vector<ArcP> > GrafP;  // graf amb pesos

GrafP llegir(int vertices, int edges){
    GrafP G(vertices);
    int vertex, adjacent, cost;
    for (int i = 0; i < edges; ++i) {
        cin >> vertex >> adjacent >> cost;
        G[vertex-1].push_back({cost,adjacent-1});
        G[adjacent-1].push_back({cost,vertex-1});
    }
    return G;
}

int prim(const GrafP& G){   
    int total_vertexs = G.size();
    priority_queue<ArcP, vector<ArcP>, greater<ArcP> > queue;
    vector<bool> visitat(total_vertexs, false);
    
    for (ArcP vertex: G[0]) queue.push (vertex);
    visitat[0] = true;

    int total_weight = 0;
    int done_vertexs = 1;

    while (done_vertexs  < total_vertexs) {
        int vact = queue.top().second; 
        int cact = queue.top().first;
        queue.pop();

        if (not visitat[vact]) {
            visitat[vact] = true;
            ++done_vertexs;
            total_weight += cact;
            for (ArcP adjacent: G[vact]) queue.push (adjacent);
        }
    }
    return total_weight;
}

int main(){
    
    int vertices, edges;
    
    while (cin >> vertices >> edges){
        GrafP G = llegir(vertices, edges);
        cout << prim(G) << endl;
    }
    
}