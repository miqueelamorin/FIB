//Easy octagons
//Reads several numbers and draws an octagon the size of n
#include <iostream>
using namespace std;

int main() {
    //reads an integer positive
    int n, m;
    bool first = true;
    while (cin >> n >> m){
        //if not first time print space
        if (not first) cout << endl;
        int num = 9;
        //go through each line
        for (int f = 1; f <= n; ++f){
            //go through each column
            for (int c = 1; c <= m; ++c){
                cout << num;
                --num;
                if (num == -1) num = 9;
            }
            cout << endl;
        }
        first = false;
    }
}
