//write the result of each operation with 2 decimal places

#include <iostream>
using namespace std;

int main() {
    double a, b;
    string op;
    bool parar = false;
    double result;
    while (not parar and cin >> op >> a){
        if (op == "parar") parar = true;
        else{
            if (op == "suma") {
                cin >> b;
                result = a + b;
            }
            else if (op == "resta") {
                cin >> b;
                result = a - b;
            }
            else if (op == "cambio") result = a * -1;
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << result << endl;
        }
    }
}
