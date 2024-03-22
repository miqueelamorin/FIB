//given two intervals, tells if one is inside the other, 
//and computes the interval corresponding to their intersection, 
//or tells that it is empty

#include <iostream>
using namespace std;

int main() {
    // reads two intervals
    int a1, b1, a2, b2, x, y;
    cin >> a1 >> b1 >> a2 >> b2;
    // if it's the same interval
    if (a1 == a2 and b1 == b2) cout << "= , ";
    // if int1 is inside int2
    else if (a1 >= a2 and b1 <= b2) cout << "1 , ";
    else if (a1 <= a2 and b1 >= b2) cout << "2 , ";
    else cout << "? , ";

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
