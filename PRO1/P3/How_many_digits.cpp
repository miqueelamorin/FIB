//How many digits
//Reads a number and a base and tells how many digits to represent it in this base
#include <iostream>
using namespace std;

int main() {
    // reads two integers
    int b, n;
    //counts number of digits
    while (cin >> b >> n){
        int i = 0;
        //keep dividing the number for the base til it's =0
        while (n > 0) {
            n /= b;
            ++i;
        }
        cout << i << endl;
    }
}
