#include "Estudiant.hh"

void leer_estudiante(Estudiant& est){
    est.llegir();
}

bool ultimo_estudiante(const Estudiant& est){
    if (est.consultar_DNI() == 0) return true;
    else return false;
}

void redondear_estudiante(Estudiant& est){
    if (est.te_nota()) est.modificar_nota(((int) (10. * (est.consultar_nota() + 0.05))) / 10.0);
}

void escribir_estudiante(const Estudiant& est){
    est.escriure();
}


int main()
{
  Estudiant est;  
  leer_estudiante(est);

    while (not ultimo_estudiante(est)) {
        redondear_estudiante(est);
        escribir_estudiante(est);
        leer_estudiante(est);
    }
}
