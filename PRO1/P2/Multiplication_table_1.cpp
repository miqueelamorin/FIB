//C201B
//reads a number n and prints the n first lines of its multiplication table

#include <iostream>
using namespace std;

int main() {
    // reads a number
    int n;
    cin >> n;
    int mult = 1;
    while (mult <= n){
    cout << n << " x " << mult << " = " << n*mult << endl;
    ++mult;
    }
}
