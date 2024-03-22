#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b)
{
    if (nest >= MAX_NEST) throw PRO2Excepcio("Conjunt ple");
    int dni = est.consultar_DNI();
    int pos = cerca_dicot(vest, 0, nest-1, dni);

    if (dni != vest[pos].consultar_DNI()){
        b = false;

        ++nest;
        vest[nest-1] = est;
        ordenar_cjt_estudiants();

        if (est.te_nota()) {
            suma_notes += est.consultar_nota();
            ++nest_amb_nota;
        }
    }
    else b = true;
}

void Cjt_estudiants::esborrar_estudiant(int dni, bool& b)
{
    int pos = cerca_dicot(vest, 0, nest-1, dni);
    if (vest[pos].consultar_DNI() == dni) {
        if (vest[pos].te_nota()) {
            suma_notes -= vest[pos].consultar_nota();
            --nest_amb_nota;
        }

        vest[pos] = vest[nest-1];
        --nest;
        ordenar_cjt_estudiants();

        b = true;
    }
    else b = false;
}
