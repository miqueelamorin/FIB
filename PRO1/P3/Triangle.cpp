//Triangle
//Reads a number and draws a triangle the size of n
#include <iostream>
using namespace std;

int main() {
    //reads an integer positive
    int n;
    cin >> n;
    int filas = 1;
    //go to next line and sum 1 to number of filas until filas = n
    while (filas <= n){
        int column = 0;
        //keep drawing * until column = filas from the column 0
        while (column < filas){
            cout << '*'; 
            ++column;
        }
        cout << endl;
        ++filas;
    }
}
