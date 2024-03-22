//tells if the weather is hot, if it’s cold, or if it’s ok

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // reads a number
    int x;
    cin >> x;
    // checks the temp for cold and hot temp and else it's ok
    if (10 > x){
        cout << "it's cold" << endl;
        if (0 >= x){
            cout << "water would freeze" << endl;
        }
    }
    else if (x > 30){
        cout << "it's hot" << endl;
        if (x >= 100){
            cout << "water would boil" << endl;
        }
    }
    else {
        cout << "it's ok" << endl;
    }
}
