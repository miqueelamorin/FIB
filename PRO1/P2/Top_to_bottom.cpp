//top to bottom
//reads two integer numbers x and y and prints all numbers between
#include <iostream>
using namespace std;

int main() {
    // reads a number
    int n, s;
    cin >> n >> s;
    if (n == s) cout << n << endl;
    else if (n > s) {
        while (n >= s){
        cout << n << endl;
        --n;
        }
    }
    else {
        while (s >= n){
        cout << s << endl;
        --s;
        }
    }
}
