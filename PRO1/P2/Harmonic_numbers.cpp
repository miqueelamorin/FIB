//Harmonic numbers
//reads a number n and prints the harmonic number
#include <iostream>
using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(4);
    //reads a number n
    double n;
    cin >> n;
    //declare var suma = 0
    double suma = 0;
    //while var veces is lower than the number, add one to the suma denominator and to veces
    while ((int veces = 1) <= n){
    suma += 1.0 / veces;
    ++veces
    }
    cout << suma << endl;
}
