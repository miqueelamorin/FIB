#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair <int,int> ArcP;
typedef vector < vector < ArcP > > Graph;

Graph read_graph(int vertices){
    int edges;
    cin >> edges;
    Graph g(vertices);
    int vertex, adjacent, weight;
    for (int i = 0; i < edges; ++i){
        cin >> vertex >> adjacent >> weight;
        g[vertex].push_back({weight,adjacent});
    }
    return g;
}

int short_roads(const Graph& g){
    int n = g.size();
    vector<int> visited(n,false);
    priority_queue<ArcP, vector<ArcP>, greater<ArcP>> queue;
    vector<int> distance(n,INT32_MAX);

    distance[0] = 0;
    queue.push({0,0});

    while(not queue.empty()){
        int act = queue.top().second;
        queue.pop();

        if (not visited[act]){
            visited[act] = true;
            if (act == 1) return distance[act];
                for (ArcP nou : g[act]){
                    if (distance[nou.second] > max(distance[act], nou.first)){
                        distance[nou.second] = max(distance[act], nou.first);
                        queue.push({distance[nou.second],nou.second});
                    }
                }
        }
    }
    return INT32_MAX;
}

int main(){
    int vertices;
    while (cin >> vertices){
        Graph g = read_graph(vertices);
        cout << short_roads(g) << endl;
    }
}