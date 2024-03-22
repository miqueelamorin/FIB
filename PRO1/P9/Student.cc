#include <typeinfo>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct Estudiant {
    int dni;
    string nom;
    double nota;        // La nota és un valor entre 0 i 10, o -1 que representa NP
    bool repetidor;
};

void informacio(const vector<Estudiant>& es, double& min, double& max, double& mitj) {
    int size = es.size();
    int repetidors = 0;
    max = min = mitj = -1;
    
    for (int i = 0; i < size; ++i) {
        if (not es[i].repetidor and es[i].nota != -1) {
            if (min == -1) {
                min = max = mitj = es[i].nota;
            }
            else {
                mitj += es[i].nota;
                if (es[i].nota > max) max = es[i].nota;
                if (es[i].nota < min) min = es[i].nota;
            }
        }
        else ++repetidors;
    }
    if (mitj != -1) mitj = mitj / (size - repetidors);
}


int main() {

    {   // vigilar el tipus Estudiant

        struct Estudiant_cntrl {
            int dni;
            string nom;
            double nota;
            bool repetidor;
        };

        Estudiant ru;
        Estudiant_cntrl rc;

        // diagn�stics en temps de compilaci�  
        ru.dni = rc.dni;  
        ru.nom = rc.nom;  
        ru.nota = rc.nota;  
        rc.repetidor = ru.repetidor;  

        // diagn�stics en temps d'execuci�
        if (sizeof(ru)!=sizeof(rc))     throw string("Sembla que 'Estudiant' no est� ben definit");
        if (typeid(ru.dni)!=typeid(rc.dni)) throw string("Sembla que 'Estudiant.dni' no est� ben definit");
        if (typeid(ru.nom)!=typeid(rc.nom)) throw string("Sembla que 'Estudiant.nom' no est� ben definit");
        if (typeid(ru.nota)!=typeid(rc.nota)) throw string("Sembla que 'Estudiant.nota' no est� ben definit");
        if (typeid(ru.repetidor)!=typeid(rc.repetidor)) throw string("Sembla que 'Estudiant.repetidor' no est� ben definit");
    }


    cout.setf(ios::fixed);
    cout.precision(4); 

    int n;
    while (cin >> n) {
        vector<Estudiant> es(n);
        for (int i=0; i<n; ++i) {
            cin >> es[i].nota >> es[i].repetidor;
        }
        double min, max, avg;
        informacio(es, min, max, avg);
        cout << min << " " << max << " " << avg << endl;
    }
}
