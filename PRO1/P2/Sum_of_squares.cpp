//reads a natural number n, and prints the result of the sum of every square

#include <iostream>
#include <math.h>
using namespace std;

int main() {
    // reads a number
    int n;
    cin >> n;
    int result = 0;
    int veces = 0;
    //while veces is lower than the number, the var result sums the var veces² until veces=number
    while (veces <= n){
        result += pow(veces, 2);
        ++veces;
    }
    cout << result << endl;
}
