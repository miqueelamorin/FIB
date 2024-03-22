#include <iostream>
using namespace std;

int main() {
    int y, d, h, m, s;
    cin >> y >> d >> h >> m >> s;
    // convert total seconds to days, hours, minutes and seconds
    int total = (y*365*24*60*60) + (d*24*60*60) + (h*3600) + (m*60) + s;
    // prints the total seconds
    cout << total << endl;
    
} 
