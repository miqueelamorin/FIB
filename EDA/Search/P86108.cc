#include <iostream>
#include <vector>
using namespace std;

typedef vector <vector<char>> Matrix;

int LOL(Matrix& solution, int fils, int cols, int i, int j, int num){
    if (i == fils) return num;
    
    int num_lol = 0;
    int newi, newj;
    newj = (j == cols-1 ? 0 : j+1);  //si final de col nova newj = 0 and newi = i+1;
    newi = (j == cols-1 ? i+1 : i);  //sino newj = j+1 and newi = i;
    solution[i][j] = 'L';

    // comprovem que s'ha creat un LOL horitzontal
    if (j >= 2 and solution[i][j-1] == 'O' and solution[i][j-2] == 'L') ++num_lol;
    // comprovem si s'ha format un LOL diagonal esq-dre
    if (i >= 2 and j >= 2 and solution[i-1][j-1] == 'O' and solution[i-2][j-2] == 'L') ++num_lol;
    // comprovem si s'ha format un LOL en vertical
    if (i >= 2 and solution[i-1][j] == 'O' and solution[i-2][j] == 'L') ++num_lol;
    // comprovem si s'ha format un LOL diagonal dre-esq
    if (i >= 2 and j < cols-1 and solution[i-1][j+1] == 'O' and solution[i-2][j+2] == 'L') ++num_lol;

    int num_l = LOL(solution, fils, cols, newi, newj, num + num_lol);
    // num_l és el màxim num. de LOLs posant una L a la posició [i, j]

    solution[i][j] = 'O';
    int num_o = LOL(solution, fils, cols, newi, newj, num);
    // num_o és el màxim num. de LOLs posant una O a la posició [i, j]

    return max(num_l, num_o);
}

int main(){
    int fils, cols;
    while (cin >> fils >> cols){
        Matrix solution(fils, vector<char>(cols));
        cout << LOL(solution, fils, cols, 0, 0, 0) << endl;
    }
}