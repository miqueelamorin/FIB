#include <iostream>
#include <vector>
using namespace std;

typedef vector < vector <char> > Tauler;

void write(const Tauler& t){
    for (int i = 0; i < t.size(); ++i){
        for (char p : t[i]) cout << p;
        cout << endl;
    }
    cout << "----------" << endl;
}

bool disponible(int x, int y, const Tauler& tauler){
    int n = tauler.size()-1;
    if (tauler[x][y] == 'K') return false;
    if (x > 0 and tauler[x-1][y] == 'K') return false;
    if (x < n and tauler[x+1][y] == 'K') return false;
    if (y > 0 and tauler[x][y-1] == 'K') return false;
    if (y < n and tauler[x][y+1] == 'K') return false;
    if (x > 0 and y > 0 and tauler[x-1][y-1] == 'K') return false;
    if (x < n and y < n and tauler[x+1][y+1] == 'K') return false;
    if (x > 0 and y < n and tauler[x-1][y+1] == 'K') return false;
    if (x < n and y > 0 and tauler[x+1][y-1] == 'K') return false;
    return true;
}

void backtracking(int reis, int max, Tauler& tauler, int x, int y){
    if (reis == max) write(tauler);
    else {
        int mida = tauler.size();
        bool primer = true;
        for (int i = x; i < mida; ++i){
            for (int j = 0; j < mida; ++j){
                if (primer) primer=false, j = y;
                if(disponible(i,j,tauler)){
                    tauler[i][j] = 'K';
                    backtracking(reis+1,max,tauler,i,j);
                    tauler[i][j] = '.';
                }
            }
        }
    }
}

int main(){
    int kings, n;
    cin >> n >> kings;
    Tauler tauler(n,vector<char>(n,'.'));
    backtracking(0,kings,tauler,0,0);
}