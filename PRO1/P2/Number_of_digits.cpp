#include <iostream>
#include <math.h>
using namespace std;

int main() {
    // reads a number
    int n, digits;
    cin >> n;
    // saves it to variable x
    int x = n;
    // checks if the number is 0
    if (n == 0) digits = 1;
    else {
        // starts counting how many digits
        digits = 0;
        while (n != 0){
            n /= 10;
            ++digits;
        }
    }
    cout << "The number of digits of " << x << " is " << digits << '.' << endl;
}
