#include <stack>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

typedef vector< vector<char> > Matrixchar;
typedef vector< vector<bool> > Matrixbool;

void llegir(Matrixchar& m){
    for(int i = 0; i < m.size(); ++i)
        for(int j = 0; j < m[i].size(); ++j)
            cin >> m[i][j];
}

int bfs(Matrixchar&m, int x, int y){
    int fils = m.size();
	int cols = m[0].size();

	queue<pair<int,int> > Q;
	vector<vector<int> > dist(fils, vector<int>(cols, -1));

	Q.push({x,y});
	dist[x][y] = 0;

 	while (not Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		if (m[x][y] == 't') return dist[x][y];
		m[x][y] = 'X';

		if (x != m.size()-1 and m[x+1][y] != 'X') {
            Q.push({x+1,y});
            dist[x+1][y] = dist[x][y] + 1;
        }

		if (x != 0 and m[x-1][y] != 'X') {
            Q.push({x-1,y});
            dist[x-1][y] = dist[x][y] + 1;
        }

		if (y != m[0].size()-1 and m[x][y+1] != 'X') {
            Q.push({x,y+1});
            dist[x][y+1] = dist[x][y] + 1;
        }

		if (y != 0 and m[x][y-1] != 'X') {
            Q.push({x,y-1});
            dist[x][y-1] = dist[x][y] + 1;
        }

	}
	return -1;
}

int main (){
    int x, y;
    cin >> x >> y;
    Matrixchar m(x, vector<char>(y));
    llegir(m);
    int xi, yi;
    cin >> xi >> yi;

    int d = bfs(m, xi-1, yi-1);
    if (d != -1) cout << "minimum distance: " << d << endl;
    else cout << "no treasure can be reached" << endl;

}
