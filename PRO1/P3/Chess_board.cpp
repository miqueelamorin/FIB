//Chess board
//board with rows and columns each one with 0-9 coins sum
#include <iostream>
using namespace std;

int main() {
    //reads three posititve integers
    int f, c;
    cin >> f >> c;
    char coins;
    int suma = 0;
    //keep adding 1 to i until = number filas
    for (int i = 0; i < f; i++){
        //keep adding 1 to j until = number columns
        //read value x and sum their chars except 0
        for (int j = 0; j < c; j++){
            cin >> coins;
            suma += coins - '0';
        }
    }
    cout << suma << endl;
}
