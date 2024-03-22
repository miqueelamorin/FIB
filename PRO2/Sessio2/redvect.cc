#include "Estudiant.hh"
#include "vectorIOEstudiant.hh"
#include <vector>

void redondear_vect_estudiante(vector<Estudiant>& vest){
    for (int i = 0; i < vest.size(); ++i){
        if (vest[i].te_nota()) vest[i].modificar_nota(((int) (10. * (vest[i].consultar_nota() + 0.05))) / 10.0);
    }
}

int main()
{
    vector<Estudiant> vest;
    leer_vector_estudiant(vest);
    redondear_vect_estudiante(vest);
    escribir_vector_estudiant(vest);
}
