//Intervals (1)
//Given two intervals, computes the interval corresponding to their intersection, or tells that it is empty.

#include <iostream>
using namespace std;

int main() {
    // reads two intervals
    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    int max;
    if (a1 < a2) max=a2;
    else max = a1;
    int min;
    if (b1 < b2) min = b1;
    else min = b2;
    if (max > min) cout << "[]" << endl;
    else cout << '[' << max << ',' << min << ']'<< endl;
}