//prints the updated arrival time in the format “HH:MM”

#include <iostream>
using namespace std;

int main() {
    //reads three positive integers being h<24, m<60 and d>=0
    int h,m,d;
    cin >> h >> m >> d;
    int total= h * 60 + m;
    total = total + d;
    h = (total%1440)/60;
    m = total%60;
    cout << h/10 << h%10 << ':';
    cout << m/10 << m%10 << endl;
}
