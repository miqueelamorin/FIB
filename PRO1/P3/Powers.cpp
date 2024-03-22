//Powers
//Reads several pair of integers and cumpute their powers
#include <iostream>
using namespace std;

int main() {
    // reads two integers and declare var result = 0
    int a, b;
    //while input is a pair of integers
    while (cin >> a >> b){
        int result = 1;
        //while i < second integer multiply a until i = b
        for (int i = 1; i <= b; ++i) result *= a
        }
        cout << result << endl;
    }
}
