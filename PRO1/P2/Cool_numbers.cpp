//prints if a given number is cool or is not

#include <iostream>
using namespace std;

int main() {
    //reads a number
    int n;
    cin >> n;
    int i = 1, sum = 0, rest = 0, num = n;
    //while the number is diff from 0
    while (n != 0){
        //get the rest by 10 and divide it by 10
        rest = n % 10;
        n = n / 10;
        //if i is odd, add to sum the value of the rest
        if (i % 2 == 1){
        sum += rest;
        }
        ++i;
    }
    //if sum is even the num is cool
    if (sum % 2 == 0) cout << num << " IS COOL" << endl;
    else cout << num << " IS NOT COOL" << endl;
}
