#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> Row;
typedef vector<Row> Matrix;

Matrix read_matrix(int r, int c)
{
    Matrix m(r, Row(c));
    for (int i = 0; i < r; ++i){
        for (int j = 0; j < c; ++j){
            cin >> m[i][j];
        }
    }
    return m;
}

void Findfields(const Matrix& m)
{
    int r = int(m.size());
    int c = int(m[0].size());
    bool below = true;
    bool right = true;
    int areas = 0;
    for (int i = 0; i < r; ++i){
        for (int j = 0; j < c; ++j){
            if (m[i][j] != 0){
                below = (i + 1 < r and m[i+1][j] != 0);
                right = (j + 1 < c and m[i][j+1] != 0);
                if (!below and !right) ++areas;
            }
        }
    }
    cout << areas << endl;
}

int main() 
{
    int r, c;
    while(cin >> r >> c){
        Matrix M = read_matrix(r, c);
        Findfields(M);
  }
}