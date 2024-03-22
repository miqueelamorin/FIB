//reads two numbers a and b, and prints all numbers between a and b

#include <iostream>
using namespace std;

int main() {
    // reads a number
    int n, s;
    cin >> n >> s;
    if (n <= s){
        while (n < s){
            cout << n << ',';
            ++n;
        }
    cout << n << endl;
    }
    if (n > s) cout << endl;
}
