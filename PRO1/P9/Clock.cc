#include <typeinfo>
#include <iostream>
using namespace std;

struct Rellotge {
    int h;      // hores (0<=h<24)
    int m;      // minuts (0<=m<60)
    int s;      // segons (0<=s<60)
};

Rellotge mitja_nit () {
    Rellotge rellotge1;
    rellotge1.h = 0;
    rellotge1.m = 0;
    rellotge1.s = 0;
    return rellotge1;        
}

void incrementa (Rellotge& r) {
    if(r.s == 59){        // XX:XX:59
        if(r.m == 59){      // XX:59:59
            if(r.h == 23){    // 23:59:59
                r.h = 0;
                r.m = 0;
                r.s = 0;
            }     
            else {
                ++r.h;
                r.m = 0;
                r.s = 0;
            }
        } 
        else {
            ++r.m;
            r.s = 0;
        }
    } 
    else ++r.s;
}

void escriu (const Rellotge& r) {
    // Print hour
    if(r.h < 10) cout << '0';
    cout << r.h << ':';

    // Print min
    if(r.m < 10) cout << '0';
    cout << r.m << ':';

    // Print sec
    if(r.s < 10) cout << '0';
    cout << r.s;

  cout << endl;
}

int main () 
{
    Rellotge r = mitja_nit();
    for (int i=0; i<=25*60*60; ++i) {
        escriu(r);
        incrementa(r);
    }
    return 0;
}