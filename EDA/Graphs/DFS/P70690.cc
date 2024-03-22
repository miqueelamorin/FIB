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

bool dfs_rec(const Matrixchar&m, int x, int y, Matrixbool& visited){
    if (m[x][y] == 't') return true;

    if (not visited[x][y] and m[x][y] != 'X'){
        visited[x][y] = true;
        if (x != 0 and dfs_rec(m, x-1, y, visited)) return true;
        if (x != m.size()-1 and dfs_rec(m, x+1, y, visited)) return true;
        if (y != 0 and dfs_rec(m, x, y-1, visited)) return true;
        if (y != m[0].size()-1 and dfs_rec(m, x, y+1, visited)) return true;
    }
    return false;
}

bool dfs(const Matrixchar&m, int xi, int yi){
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

    if (dfs(m, xi-1, yi-1)) cout << "yes" << endl;
    else cout << "no" << endl;
}
