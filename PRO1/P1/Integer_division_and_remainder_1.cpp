//prints the integer division d and the remainder r of a divided by b

#include <iostream>
using namespace std;

int main() {
    int s;
    cin >> s;
    // convert total seconds to hours, minutes and seconds
    int h = s/3600;
    int m = (s%3600)/60;
    s = (s%3600)%60;
    // prints the hours, minutes and seconds
    cout << h << " ";
    cout << m << " ";
    cout << s << endl;
    
} 
