//Chess board 2
//board with rows and columns each one with 0-9 coins sum
#include <iostream>
using namespace std;

int main() {
    //reads three posititve integers
    int f, c;
    cin >> f >> c;
    char coins;
    int suma = 0, k;
    //keep adding 1 to i until = number filas
    for (int i = 1; i <= f; i++){
        k = i;
        //keep adding 1 to j until = number columns
        //read value x
        for (int j = 1; j <= c; j++){
            cin >> coins;
            //if k is odd sum the digit
            if (k % 2 != 0){
                suma += coins - '0';
                }
            ++k;
        }
    }
    cout << suma << endl;
}
