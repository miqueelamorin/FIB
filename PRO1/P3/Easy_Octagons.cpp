//Easy octagons
//Reads several numbers and draws an octagon the size of n
#include <iostream>
using namespace std;

int main() {
    //reads an integer positive
    int n;
    while (cin >> n){
        int ncol = 2 * n - 1; //number of columns
        int space = n - 1; //number of spaces
        int maxncol = 0; //times repeats max number columns
        //go to next line and sum 1 to rows until rows = n
        //the formula for n rows is n+(n-1)*2
        for (int r = 1; r <= 3 * n - 2; ++r){
            //go through each column until = ncol
            for (int c = 1; c <= ncol; ++c){
                //draw spaces or Xs
                if (c <= space) cout << ' ';
                else cout << 'X';
            }
            cout << endl;
            //if it's increasing add 1 column and subtract 1 space
            if (maxncol == 0){
                ++ncol;
                --space;
            }
            //if columns = max number add 1 to maxcol
            if (ncol == 3 * n - 2)++maxncol;
            //if it's decreasing subtract 1 column and add 1 space
            if (maxncol > n){
                --ncol;
                ++space;
            }
        }
        cout << endl;
    }
}
