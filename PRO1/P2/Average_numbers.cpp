//Average numbers
//reads a sequence of numbers and prints their average
#include <iostream>
using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(2);
    //reads a sequence numbers
    double n, sum = 0, i = 0;
    while (cin >> n){
        sum += n;
        ++i;
    }
    cout << sum / i << endl;
}
