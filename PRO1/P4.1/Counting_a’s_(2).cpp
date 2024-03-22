//Counting as
//reads a sequence of characters ended with a period and prints the number of letters ‘a’ in the sequence
#include <iostream>
using namespace std;

int main() {
    //declare var c and set it to 0
    int c = 0;
    char x = 'a';
    while (x != '.'){
        cin >> x;
        if (x == 'a') ++c;
    }
    cout << c << endl;
}