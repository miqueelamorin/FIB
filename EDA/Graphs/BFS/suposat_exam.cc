#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

typedef vector < vector <char> > Matrix;
typedef vector < pair<int,int> > Direccions;
typedef vector < vector < pair<int,int> > > MatrixPair;

Direccions d={{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

Matrix read(int fils, int cols, int& ic, int& jc){
    Matrix m(fils, vector<char>(cols));
    for (int i = 0; i < fils; ++i)
    for (int j = 0; j < cols; ++j) {
        cin >> m[i][j];
        if (m[i][j] == 'K') ic=i, jc=j;
    }
    return m;
}

bool pos_ok(const Matrix& m, int i, int j){
    return (i >= 0 and j >= 0 and i < m.size() and j < m[0].size() and m[i][j] != 'X');
}

void write(const MatrixPair& prev, int ifarm, int jfarm, int ic, int jc){
    stack<pair<int,int>> pila;
    int iprov = ifarm;
    int jprov = jfarm;
    int steps = 1;
    pila.push({iprov,jprov});
    while(iprov != ic or jprov != jc){  
        iprov = prev[iprov][jprov].first;
        jprov = prev[iprov][jprov].second;
        pila.push({iprov, jprov});
        ++steps;
    }
    cout << steps;
    while(not pila.empty()){
        cout << "  " << pila.top().first << ' ' << pila.top().second;
        pila.pop();
    }
}

void pag_cav(Matrix& m, int ic, int jc){
    queue<pair<int,int>> queue;
    queue.push({ic,jc});
    MatrixPair prev(m.size(), vector<pair<int,int>>(m[0].size()));
    
    while(not queue.empty()){
        int iact = queue.front().first;
        int jact = queue.front().second;
        queue.pop();

        for (int i = 0; i < d.size(); ++i){
            int novai = iact+d[i].first;
            int novaj = jact+d[i].second;

            if (pos_ok(m,novai,novaj)){
                queue.push({novai,novaj});
                prev[novai][novaj] = {iact,jact};
                if (m[novai][novaj] == 'F') {write(prev,novai,novaj,ic,jc); return;}
                m[novai][novaj] = 'X';
            }
        }
    }
    cout << '0' << endl;
}

int main(){
    int fils, cols;
    while (cin >> fils >> cols){
        int ic, jc;
        Matrix m = read(fils, cols, ic, jc);
        pag_cav(m, ic, jc);
    }
}