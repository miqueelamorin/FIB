#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector <vector <char> > Matrix;
typedef vector < pair <int,int> > Directions;

Directions d = {{1,0},{0,1},{-1,0},{0,-1}};
Directions df={{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

bool pos_ok(const Matrix& m, int i, int j){
    return (i >= 0 and j >= 0 and i < m.size() and j < m[0].size());
}

void rodejar(Matrix&m, int ifant, int jfant){
    for (auto d : df){
        int novai = ifant+d.first;
        int novaj = jfant+d.second;
        if (pos_ok(m,novai,novaj)) m[novai][novaj] = 'X';
    }
}

Matrix read(int fils, int cols, int& ip, int& jp){
    Matrix m(fils, vector<char>(cols));
    char aux;
    for (int i = 0; i < fils; ++i){
        for (int j = 0; j < cols; ++j){
            cin >> aux;
            if (m[i][j] == 'X' and aux != 'F') continue;
            if (aux == 'P') ip = i, jp = j;
            if (aux == 'F') rodejar(m,i,j);
            m[i][j] = aux;
        }
    }
    return m;
}

bool pacman(Matrix& m, int ip, int jp){
    queue<pair<int,int>> queue;
    queue.push({ip,jp});

    while(not queue.empty()){
        int iact = queue.front().first;
        int jact = queue.front().second;
        queue.pop();
        for (int k = 0; k < 4; ++k){
            int novai = iact+d[k].first;
            int novaj = jact+d[k].second;
            if (pos_ok(m,novai,novaj) and m[novai][novaj] != 'X'){
                if (m[novai][novaj] == 'B') return true;
                queue.push({novai, novaj});
                m[novai][novaj] = 'X';
            }
        }
    }
    return false;
}


int main(){
    int fils, cols;
    while(cin >> fils >> cols){
        int ip, jp;
        Matrix m = read(fils, cols, ip, jp);
        cout << (pacman(m,ip,jp) ? "si" : "no") << endl;
    }
}