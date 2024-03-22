#include "solution.hh"

void esborra_tots(list<Estudiant> &t, int dni) {
    
    list<Estudiant>::iterator it;
    it = t.begin();
    
    while (it != t.end()) {
        if ((*it).consultar_DNI() == dni) it = t.erase(it);
        else ++it;
    }
    
} 
