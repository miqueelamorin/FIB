//Add one second
//Adds 1 second to input and shows it

#include <iostream>
using namespace std;

int main() {
    // reads hours, minutes and seconds
    int h, m, s;
    cin >> h >> m >> s;
    // convert all to seconds and add 1    
    int total = (h*3600) + (m*60) + s + 1;
    // convert total seconds to hours, minutes, seconds and days
    int d = total/86400;
    h = d/3600;
    m = (total%3600)/60;
    s = (total%3600)%60;
    // prints the hours, minutes and seconds in HH:MM:SS
    cout << h/10 << h%10 << ':';
    cout << m/10 << m%10 << ':';
    cout << s/10 << s%10 << endl;
    
}
