#include "LlistaIOParInt.hh"
#include <iostream>
#include <list>

using namespace std;

void cerca (const list<ParInt>& l, int x) {
    
    list<ParInt>::const_iterator it;
    it = l.begin();
    
    int suma, count;
    suma = count = 0;
    while (it != l.end()) {
        if ((*it).primer() == x) {
            ++count;
            suma += (*it).segon();
        }
        ++it;
    }
    cout << x << ' ' << count << ' ' << suma << endl;
}


int main(){
    list <ParInt> l;
    LlegirLlistaParInt(l);
    int x;
    cin >> x;
    cerca(l, x);
}
