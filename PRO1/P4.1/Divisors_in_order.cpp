//Divisors in order
//reads a sequence of numbers and print its divisors in order
#include <iostream>
using namespace std;

int main() {
  int n;
  while (cin >> n){
    cout << "divisors of " << n << ": ";
    int i, lasti = 0;
    //get the divisors from 1 to sqrt of n
    if (n > 1){
        for (i = 1; i * i <= n; ++i){
            if (n % i == 0){
                cout << i << ' ';
                if (i * i < n) lasti = i;
            }
        }
        //get the divisors from sqrt of n to n
        for (int j = lasti; j >= 2; --j){
            //if it's divisor cout the result
            if (n % j == 0) cout << n / j << ' ';
        }
    }
    cout << n << endl;
  }
}
