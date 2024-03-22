//Reversed number in binary
//reads a number and prints its binary representation reversed
#include <iostream>
using namespace std;

int main() {
    //reads a number
    int n;
    cin >> n;
    //while number >= base, print the rest and divite it by 2
    while (n >= 2) {
        cout << n % 2;
        n = n / 2;
    }
    //print the last quotient
    cout << n << endl;
}
