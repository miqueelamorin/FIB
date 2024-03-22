//tells if a year is or is not a leap year

#include <iostream>
using namespace std;

int main() {
    // reads a year input
    int y;
    cin >> y;
    // finds if is multiple of 4 or if ended in two zeros it removes them
    if ((y % 4 == 0 and y % 100 != 0) or (y % 100 == 0 and ((y / 100) % 4) == 0 )){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}
