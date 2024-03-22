#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair <int,int> ArcP;
typedef vector < vector < ArcP > > GraphP;

GraphP read_graphp(int vertices){
    int edges;
    cin >> edges;
    int vertex, adjacent, cost;
    GraphP g(vertices);
    for (int i = 0; i < edges; ++i){
        cin >> vertex >> adjacent >> cost;
        g[vertex].push_back({cost, adjacent});
    }
    return g;
}

void imprimir(int dist, int steps, int origen, int desti){
    if (dist == INT32_MAX) cout << "no path from " << origen << " to " << desti << endl;
    else cout << "cost " << dist << ", " << steps << " step(s)" << endl;
}

void dijkstra(const GraphP& g, int origen, int desti){
    int n = g.size();
    vector<int> visited(n,false);
    vector<int> distance(n,INT32_MAX);
    vector<int> steps(n,0);
    priority_queue<ArcP, vector<ArcP>, greater<ArcP>> queue;
    
    queue.push({0,origen});
    distance[origen] = 0;
    steps[origen] = 0;

    while(not queue.empty() and queue.top().second != desti){
        int act = queue.top().second;
        queue.pop();
        if (not visited[act]){
            visited[act] = true;
            for (auto nou : g[act]){
                if (distance[act] + nou.first < distance[nou.second]){
                    distance[nou.second] = distance[act] + nou.first;
                    steps[nou.second] = steps[act] + 1;
                    queue.push({distance[nou.second],nou.second}); 
                }
                else if (distance[act] + nou.first == distance[nou.second] and steps[nou.second] > steps[act] + 1){
                    steps[nou.second] = steps[act] + 1;
                    queue.push({distance[nou.second],nou.second});
                }
            }
        }
    }
    imprimir(distance[desti],steps[desti],origen,desti);
}
    

int main(){
    int vertices;
    while (cin >> vertices){
        GraphP g = read_graphp(vertices);
        int origen, desti;
        cin >> origen >> desti;
        dijkstra(g,origen,desti);
    }
}