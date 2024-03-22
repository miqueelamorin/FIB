#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int> > Matrix;

bool is_solution(const Matrix& s) {
    int size1 = s.size();
    int size2 = s[0].size();
    
    for (int i = 0; i < size1; ++i) {
        vector<bool> rowchecker(9, false);
        vector<bool> colchecker(9, false);
        //mirar files i columnes
        for(int j = 0; j < size2; ++j) {
            int rownum = s[i][j];
            if (not rowchecker[rownum - 1]) rowchecker[rownum - 1] = true;
            else return false;

            int colnum = s[j][i];
            if (not colchecker[colnum - 1]) colchecker[colnum - 1] = true;
            else return false;
        }
    }
    
    //mirar submatrius 3x3
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            
            vector<bool> minichecker(9, false);
            
            for(int m = 3*i; m < (3*i + 3); ++m){
                for(int n = 3 * j; n < (3*j + 3); ++n){
                    int number = s[m][n];
                    if (not minichecker[number - 1]) minichecker[number - 1] = true;
                    else return false;
                }
            }
        }
    }

    return true;
}

void read_matrix(Matrix& s) {
    s = Matrix(9,vector<int>(9));
    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) cin >> s[i][j];
    }
}

void solution_sudoku(Matrix& s){
    int n;
    cin >> n;
    for(int ii=0; ii<n; ++ii){
        read_matrix(s);
        if(is_solution(s)) cout << "si" << endl;
        else cout << "no" << endl;
    }
}

int main() { 
    Matrix s;
    solution_sudoku(s);
}