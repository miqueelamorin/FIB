//Reversed number in hex
//reads a number and prints its hex representation reversed
#include <iostream>
using namespace std;

int main() {
    //reads a number
    int n;
    cin >> n;
    if (n == 0) cout <<n;
    //while number >= base, print the rest and divite it by 16
    while (n != 0) {
        int y =  n % 16;
        n = n / 16;
        //check if it's > 10 and associate to char
        if (y >= 10) cout << char('A' + y - 10);
        else cout << y;
    }
    cout << endl;
}
