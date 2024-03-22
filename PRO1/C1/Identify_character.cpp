//reads a character and prints if this is a letter, a digit, or it is not either a letter nor digit
#include <iostream>
using namespace std;

int main() {
    char input;
    cin >> input;
    if (input >= '0' and input <= '9') cout << "digit" << endl;
    else if ((input >= 'a' and input <= 'z') or (input >= 'A' and input <= 'Z')){
        cout << "lletra" << endl;
    }
    else cout << "res" << endl;
}
