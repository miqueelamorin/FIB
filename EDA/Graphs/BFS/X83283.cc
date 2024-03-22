#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector < vector <int> > Graph;

Graph read(int vertices){
    int edges;
    cin >> edges;
    Graph g(vertices);
    int vertex1, vertex2;
    for (int i = 0; i < edges; ++i){
        cin >> vertex1 >> vertex2;
        g[vertex1].push_back(vertex2);
        g[vertex2].push_back(vertex1);  
    }    
    return g;
}

int farthest(const Graph& g){
    int n = g.size();
    vector<int> distance(n,-1);
    int dist_max = 0;
    int v_max = 0;
    queue<int> cua;
    cua.push(0);
    distance[0] = 0;

    while(not cua.empty()){
        int act = cua.front();
        cua.pop();
        for (int nou : g[act]){
            if (distance[nou] == -1){
                distance[nou] = distance[act]+1;
                cua.push(nou);
                if (distance[nou] > dist_max) dist_max = distance[nou], v_max = nou;
                else if (distance[nou] == dist_max and v_max > nou) v_max = nou;
            }
        }
    }
    return v_max;
}

int main(){
    int vertices;
    while(cin >> vertices){
        Graph g = read(vertices);
        cout << farthest(g) << endl;
    }
}