//reads two numbers and prints their minimum

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // reads three numbers
    int n1, n2;
    cin >> n1 >> n2;
    // compares them in 2 cases and prints the smaller one
    if (n1 <= n2){
        cout << n1 << endl;
    }
    else{
        cout << n2 << endl;
    }
}
