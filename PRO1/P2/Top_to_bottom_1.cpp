//top to bottom
//reads two integer numbers x and y and prints all numbers between
#include <iostream>
using namespace std;

int main() {
    // reads a number
    int n, s, max = 0, min = 0;
    cin >> n >> s;
    if (n < s) min = n, max = s;
    else min = s, max = n;    
    while (max >= min){ 
        cout << max << endl;
        --max;
    }
}
