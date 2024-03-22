//prints the total number of coins on the board and the number of coins placed in odd rows

#include <iostream>
using namespace std;

int main() {
    int r, c;
    char coins;
    cin >> r >> c;
    int result = 0, oddresult = 0;
    for (int i = 1; i <= r; ++i){
        for (int j = 1; j <= c; ++j){
            cin >> coins;
            if (i % 2 != 0){
                oddresult += coins - '0';
            }
            result += coins - '0';
        }
    }
    cout << result << ' ' << oddresult << endl;
}
