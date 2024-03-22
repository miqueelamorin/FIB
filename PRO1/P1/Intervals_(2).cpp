//given two intervals, tells if one is inside the other.

#include <iostream>
using namespace std;

int main() {
    // reads two intervals
    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    // check if it's inside the intervals
    if (a1 == a2 and b1 == b2) cout << '=' << endl;
    else if (a1 >= a2 and b1 <= b2) cout << '1' << endl;
    else if (a1 <= a2 and b1 >= b2) cout << '2' << endl;
    else cout << '?' << endl;
}
