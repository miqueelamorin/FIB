//Sum of digits 2
//Reads several numbers and prints the sum of their digits in the base declared
#include <iostream>
using namespace std;

int main() {
    // reads two integers
    int b, n;
    cin >> b;
    //while input is an integer
    while (cin >> n){
        int number = n, result = 0;
        //keep dividing n by the base and sum its rest every time in the var "result"
        while (n != 0){
            result += n % b;
            n = n / b;
        }
        cout << number << ": " << result << endl;
    }
}
