#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<string>> Matrixstring;
typedef vector<vector<int>> Matrixint;
vector <pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

bool pos_ok(int i, int j, const Matrixstring& m){
    return (i >= 0 and i < m.size() and j >= 0 and j < m[0].size() and m[i][j] != "*");
}

int film_search(const Matrixstring& keyboard, const vector<string>& film){
    queue<pair<int,int>> queue;
    int k = 0;
    int steps = 0;
    queue.push({0,0});

    while(not queue.empty()){
        int iact = queue.front().first;
        int jact = queue.front().second;
        queue.pop();

        if (keyboard[iact][jact] == film[k]){
            ++k;
            if (k == film.size()) return k;
        } 
        cout << iact << ' ' << jact << endl;

        for (int i = 0; i < 4; ++i){
            int newi = iact + directions[i].first;
            int newj = jact + directions[i].second;
            if (pos_ok(newi,newj,keyboard)){
                queue.push({newi,newj});
            }
        }
    }
}

int main(){
    int fils, cols;
    while (cin >> fils >> cols){
        Matrixstring keyboard(fils, vector<string>(cols));
        for (int i = 0; i < fils; ++i)
            for (int j = 0; j < cols; ++j) cin >> keyboard[i][j];
        int p;
        cin >> p;
        vector<string> film(p);
        for (int i = 0; i < n; ++i) cin >> film[i];
        cout << film_search(keyboard,film) << endl;
    }
}