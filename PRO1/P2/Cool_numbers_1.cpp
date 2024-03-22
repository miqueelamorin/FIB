//prints if a given number is cool or is not

#include <iostream>
using namespace std;

int main() {
    //reads a number
    int n;
    cin >> n;
    int sum = 0, num = n;
    //while the number is diff from 0
    while (n != 0){
        //get the rest by 10 and divide it by 10
        sum = n % 10;
        n = n / 100;
    }
    //if sum is even the num is cool
    if (sum % 2 == 0) cout << num << " IS COOL" << endl;
    else cout << num << " IS NOT COOL" << endl;
}
