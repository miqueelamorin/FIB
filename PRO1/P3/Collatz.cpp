//Collatz
//Reads a number print the lenght of collatz's sequence
#include <iostream>
using namespace std;

int main() {
    //reads a positive number
    int n;
    while (cin >> n){
        int i = 0;
        //count times til n=1
        while (n != 1){
            if (n % 2 == 0) n /= 2;
            else n = n * 3 + 1;
            ++i;
        }
        cout << i << endl;
    }
}
