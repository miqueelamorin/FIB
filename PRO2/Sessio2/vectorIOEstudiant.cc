#include "vectorIOEstudiant.hh"

/* Leer vector */
void leer_vector_estudiant(vector<Estudiant>& vest) {// version accion
  cout<<"Escribe el tamaño del vector:"<<endl;
  int numEst;
  cin >> numEst;
  vest = vector<Estudiant> (numEst);
  
  cout<<"Escribe los elementos del vector:"<<endl;  
  for (int i=0; i<numEst;++i) vest[i].llegir();
}

/* Escribir vector */
void escribir_vector_estudiant(const vector<Estudiant>& vest) {
  for (int i=0; i<vest.size();++i) vest[i].escriure();
}
