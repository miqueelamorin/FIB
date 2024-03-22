#include <iostream>
#include <vector>
using namespace std;

typedef vector <vector <int> > Matrixint;
typedef vector <vector <char> > Matrixchar;
typedef pair <int,int> pos;

const vector <pos> directions = {{1,0},{-1,0},{0,1},{0,-1}};

bool pos_ok(int i, int j, const Matrixchar& table){
    return (i >= 0 and i < table.size() and j >= 0 and j < table[0].size());
}

void tortuga(pos act, pos fin, Matrixint& visited, const Matrixchar& table, vector<char>& path){
    if (act.first == fin.first and act.second == fin.second) {
        for (char l : path) cout << l;
        cout << endl;
    }
    else{
        for (int i = 0; i < 4; ++i){
            int newi = act.first + directions[i].first;
            int newj = act.second + directions[i].second;
            if (pos_ok(newi,newj,table) and not visited[newi][newj]){
                path.push_back(table[newi][newj]);
                visited[newi][newj] = true;
                tortuga({newi,newj},fin,visited,table,path);
                visited[newi][newj] = false;
                path.pop_back();
            }
        }
    }
}

int main(){
    int fils, cols;
    cin >> fils >> cols;
    Matrixchar table(fils, vector<char>(cols));
    for (int i = 0; i < fils; ++i){
        for (int j = 0; j < cols; ++j) cin >> table[i][j];
    }

    Matrixint visited(fils, vector<int>(cols,false));
    pos ini, fin;
    cin >> ini.first >> ini.second;
    cin >> fin.first >> fin.second;
    vector<char> path;

    path.push_back(table[ini.first][ini.second]);
    visited[ini.first][ini.second] = true;

    tortuga(ini,fin,visited,table,path);
}