//Looking for an a
//reads a sequence of characters ended with a period and prints if the sequence has an a
#include <iostream>
using namespace std;

int main() {
    char x = 'a';
    int c = 0;
    while (x != '.'){
        cin >> x;
        if (x == 'a') ++c;
    }
    if (c != 0) cout << "yes" << endl;
    else cout << "no" << endl;
}