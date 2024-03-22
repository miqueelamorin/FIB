//reads a real number x≥0 and prints ⌊ x ⌋ (the floor of x)
//⌈ x ⌉ (the ceiling of x), and the rounding of x

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // reads a number
    double x;
    cin >> x;
    // prints its int value
    cout << int(x) << ' ';
    // variable rest = the number minus its int value
    double rest = x - int(x);
    // check if the number is integer or decimal and add 1
    if (rest != 0){
        cout << int(x) + 1 << ' ';
    }
    // it's integer so print it
    else{
        cout << int(x) << ' ';
    }
    // check if the decimal part is >= 0.5
    if (rest >= 0.5){
        cout << int(x) + 1 << endl;
    }
    else{
        cout << int(x) << endl;
    }
}
