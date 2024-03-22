//given five integers x,a,b,c,d, determines if x∈[a,b]∪[c,d]

#include <iostream>
using namespace std;

int main() {
    // reads a year input
    int x, a, b, c, d ;
    cin >> x >> a >> b >> c >> d;
    // check if it's inside the intervals
    if (x >= a and x <= b) cout << "si" << endl;
    else if (x >= c and x <= d) cout << "si" << endl;
    else cout << "no" << endl;
}
