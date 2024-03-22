#include "LlistaIOEstudiant.hh"
#include <iostream>
#include <list>

using namespace std;

void cerca (const list<Estudiant>& l, int dni) {
    
    list<Estudiant>::const_iterator it;
    it = l.begin();
    
    int count = 0;
    while (it != l.end()) {
        if ((*it).consultar_DNI() == dni) ++count;
        ++it;
    }
    cout << dni << ' ' << count << endl;
}


int main(){
    list <Estudiant> l;
    LlegirLlistaEstudiant(l);
    int dni;
    cin >> dni;
    cerca(l, dni);
}
