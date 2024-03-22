//prints the integer division d and the remainder r of a divided by b

#include <iostream>
using namespace std;

int main() {
int s,m,mr,h,hr;
cin >> s;
m = s/60;
mr = s%60;
    if(m >= 60){
        h = m/60;
        hr = m%60;
        cout << h << " " << hr << " " << mr << endl;
    }
    else{
        cout << "0 " << m << " " << mr << endl;
    }
}