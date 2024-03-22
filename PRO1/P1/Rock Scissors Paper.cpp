//agua (A) vence a la piedra (P) que a su vez vence al viento (V) 

#include <iostream>
using namespace std;

int main() {
    // reads to characters
    char a, b;
	cin >> a >> b;
    // checks if the first char wins the second one
    if ((a == 'A' and b == 'P') or (a == 'P' and b == 'V') or (a == 'V' and b == 'A')){
        cout << '1' << endl;
    }
    // if char =
    else if (a == b){
        cout << '-' << endl;
    }
    // if the second char wins the first
    else {
        cout << '2' << endl;
    }
}
