//Sequence of numbers multiple of x
//Reads a number x and a sequence and tells how many multiples of x
#include <iostream>
using namespace std;

int main() {
    int x, seq, count = 0;
    cin >> x;
    while (cin >> seq) {
        if ((seq % x) == 0) ++count;
    }
    cout << count << endl;
}
