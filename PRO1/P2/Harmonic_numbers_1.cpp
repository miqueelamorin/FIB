//Harmonic numbers
//reads a number n and prints the harmonic number
#include <iostream>
using namespace std;

int main() {
    //reads a number n
    double n;
    cin >> n;
    //declare var suma = 0
    double suma = 0;
    //for a var i while it's lower than n, add one to i and add it to var suma denominator
    for (int i = 1; i <= n; ++i) suma += 1.0 / i;
    cout.setf(ios::fixed);
    cout.precision(4);
    cout << suma << endl;
}
