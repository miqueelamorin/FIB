//Sum of digits
//Reads several numbers and prints the sum of their digits
#include <iostream>
using namespace std;

int main() {
    //reads two integers and declare var result = 0
    int n;
    //while input is an integer
    while (cin >> n){
        int number = n, result = 0;
        //keep dividing n by 10 and sum its rest every time in the var "result"
        while (n != 0){
            result += n % 10;
            n /=s 10;
        }
        cout << "The sum of the digits of " << number << " is " << result << '.' << endl;
    }
}
