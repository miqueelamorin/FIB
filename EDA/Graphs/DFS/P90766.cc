#include <stack>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

typedef vector< vector<char> > Matrixchar;
typedef vector< vector<bool> > Matrixbool;

void llegir(Matrixchar& m){
    for(int i = 0; i < m.size(); ++i)
        for(int j = 0; j < m[i].size(); ++j)
            cin >> m[i][j];
}

int dfs_rec(const Matrixchar&m, int x, int y, Matrixbool& visited){
    int a = 0;

    if (not visited[x][y]){
        visited[x][y] = true;
        if (m[x][y] == 't') a = 1;

        if (m[x][y] != 'X'){
            if (x != 0) a+=dfs_rec(m, x-1, y, visited);
            if (x != m.size()-1) a+=dfs_rec(m, x+1, y, visited);
            if (y != 0) a+=dfs_rec(m, x, y-1, visited);
            if (y != m[0].size()-1) a+=dfs_rec(m, x, y+1, visited);
        }
    }
    return a;
}

int dfs(const Matrixchar&m, int xi, int yi){
    Matrixbool visited(m.size(), vector<bool>(m[0].size(), false));
    return dfs_rec(m, xi, yi, visited);
}

int main (){
    int x, y;
    cin >> x >> y;
    Matrixchar m(x, vector<char>(y));
    llegir(m);
    int xi, yi;
    cin >> xi >> yi;

    cout << dfs(m, xi-1, yi-1) << endl;
}
