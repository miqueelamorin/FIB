//Add one second
//Adds 1 second to input and shows it

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int h,m,s;
    cin >> h >> m >> s;
    s = s+1;
    if (s == 60){
        m = m+1;
        s = 0;
        if (m == 60){
            h = h+1;
            m = 0;
            if (h == 24){
                h = 0;
            }
        }
    }

    cout << setfill('0') << setw(2) << h << ":" << setfill('0') << setw(2) << m << ":" << setfill('0') << setw(2) << s << endl;
}
