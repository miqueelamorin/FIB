//Intervals (1)
//Given two intervals, computes the interval corresponding to their intersection, or tells that it is empty.

#include <iostream>
using namespace std;

int main() {
    // reads two intervals
    int a1, b1, a2, b2, x, y;
    cin >> a1 >> b1 >> a2 >> b2;
    // check if it's inside the intervals
    if (b1 < a2 or b2 < a1) cout << "[]" << endl;
    else {
        // start point
        if (a1 <= a2) x = a2;
        else x = a1;
        // end point
        if (b1 <= b2) y = b1;
        else y = b2;
        cout << '[' << x << ',' << y << ']' << endl;
    }
}