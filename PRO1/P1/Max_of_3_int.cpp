//reads three numbers and prints their maximum.

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // reads three numbers
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    // compares them in 3 cases and prints the bigger one
    if ((n1 >= n2) and (n1 >= n3)){
        cout << n1 << endl;
    }
    else if ((n2 >= n1) and (n2 >= n3)){
        cout << n2 << endl;
    }
    else{
        cout << n3 << endl;
    }
}
