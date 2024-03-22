#include <vector>
#include <iostream>

using namespace std;

typedef vector< vector< int > > Matrix;
typedef vector< vector< bool > > Matrixb;

void llegir(Matrix& m, int x, int y){
    string s;

    for (int i = 0; i < x; ++i)
        for (int j = 0; j < y; ++j){
            cin >> s;
            if (s == "X") m[i][j] = -1;
            else m[i][j] = atoi(s.c_str());
        }
}

bool valid(const Matrix& m, int x, int y){
    return x >= 0 and x < m.size() and y >= 0 and y < m[0].size();
}

int dfs(const Matrix& m, Matrixb& visited, int x, int y, int& nelem){
    int sum = 0;
    if (not visited[x][y] and m[x][y] != -1) {
        sum = m[x][y];
        visited[x][y] = true;
        ++nelem;
        if (valid(m, x+1, y+1)) sum += dfs(m, visited, x+1, y+1, nelem);
        if (valid(m, x-1, y+1)) sum += dfs(m, visited, x-1, y+1, nelem);
        if (valid(m, x+1, y-1)) sum += dfs(m, visited, x+1, y-1, nelem);
        if (valid(m, x-1, y-1)) sum += dfs(m, visited, x-1, y-1, nelem);
    }
    return sum;
}

bool solu(const Matrix& m){
    Matrixb visited(m.size(), vector <bool>(m[0].size(), false));
    int i = 0;
    bool impossible = false;

    bool first = true;
    int sum, sumant;
    int nelem = 0;

    for (int i = 0; i < m.size(); ++i){
        for (int j = 0; j < m[0].size(); ++j){
            if (m[i][j] != -1 and not visited[i][j]){
                nelem = 0;
                sum = dfs(m, visited, i, j, nelem);
                if (first) {first = false; sumant = sum/nelem;}
                if ((sum%nelem != 0) or sum/nelem != sumant) return false;
            }
        }
    }
    return true;
}

int main (){
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; ++i){
        int x, y;
        cin >> x >> y;
        Matrix m(x, vector<int>(y));
        llegir(m, x, y);

        cout << "Case " << i+1 << ':';
        cout << (solu(m) ? " yes" : " no") << endl;
    }
}
