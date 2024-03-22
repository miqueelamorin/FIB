//reads a number n and prints the “multiplication table” of n

#include <iostream>
using namespace std;

int main() {
    // reads a number
    int n;
    cin >> n;
    int mult = 1;
    while (mult <= 10){
    cout << n << '*' << mult << " = " << n*mult << endl;
    ++mult;
    }
}
