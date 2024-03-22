//Harmonic numbers (2)
//Several pairs of natural numbers print Hn − Hm with 10 digits
#include <iostream>
using namespace std;

int main() {
    //reads two positive numbers
    double n, m;
    while (cin >> n >> m){
    double suma = 0;
    //keep adding 1 to i from the diff between n and m
    for (int i = m + 1; i <= n; ++i) suma += 1.0 / i;
    cout.setf(ios::fixed);
    cout.precision(10);
    cout << suma << endl;
    }
}
