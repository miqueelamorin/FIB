//Cube between two integers
//Reads to integers and prints the cubic sum of a sequence between them.
#include <iostream>
using namespace std;

int main() {
    //reads to positive numbers
    int a, b;
    //for input declare var i and suma
    while (cin >> a >> b){
        int suma = 0;
        //while i = a <= b keep adding 1 to i and multiply i^3
        for (int i = a; i <= b; ++i) suma += i*i*i;
        cout << "suma dels cubs entre " << a << " i " 
            << b << ": " << suma << endl;
    }
}
