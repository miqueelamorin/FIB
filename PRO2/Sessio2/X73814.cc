#include "Estudiant.hh"
#include <iostream>
#include <vector>

using namespace std;

void leer_vector_estudiant(vector<Estudiant>& vest, int& newsize) {
  int numEst;
  cin >> numEst;
  vest = vector<Estudiant> (numEst);

  for (int i=0; i<numEst; ++i) {
      vest[i].llegir();
      if (i != 0 and vest[i].consultar_DNI() != vest[i-1].consultar_DNI()) ++newsize;
  }
}

void escribir_vector_estudiant(const vector<Estudiant>& vest) {
  for (int i=0; i<vest.size();++i) vest[i].escriure();
}

void simplificar_vector(const vector<Estudiant>& ini, vector<Estudiant>& def) {
    int inisize = ini.size();
    int j = 0;
    def[0] = ini[0];
    for (int i = 1; i < inisize; ++i) {
        if (ini[i].consultar_DNI() != ini[i-1].consultar_DNI()) {
            ++j;
            def[j] = ini[i];
        }
        else {
            if (def[j].te_nota()) {
                if (ini[i].te_nota() and ini[i].consultar_nota() > def[j].consultar_nota()) def[j] = ini[i];
            }
            else def[j] = ini[i];
        }
    }
}

int main() {
    vector<Estudiant> ini;
    int newsize = 1;
    leer_vector_estudiant(ini, newsize);
    vector<Estudiant> def(newsize);
    simplificar_vector(ini, def);
    escribir_vector_estudiant(def);
}
