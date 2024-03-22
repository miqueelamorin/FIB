//reads a number n, and prints all numbers between 0 and n

#include <iostream>
using namespace std;

int main() {
    // reads a number
    int n;
    cin >> n;
    int print = 0;
    while (print <= n){
    cout << print << endl;
    ++print;
    }
}
