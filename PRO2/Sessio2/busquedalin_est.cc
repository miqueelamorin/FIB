#include <iostream>
#include <vector>
using namespace std;

#include "vectorIOEstudiant.hh"
#include "Estudiant.hh"

/* Buscar  */    
bool busqueda_lin(const vector<Estudiant>& vest, int x, int& j)
/* Pre: cierto */
/* Post: el resultado indica si x está en v */
{
  int size = vest.size();
  for (int i = 0; i < size; ++i) {
      if (x == vest[i].consultar_DNI()) {
          j = i;
          return true;
      }
  }
  return false;
}

int main()
{
  vector<Estudiant> vest;
  leer_vector_estudiant(vest);
  cout << "Escribe el elemento a buscar: " << endl;
  int x;
  cin >> x;
  int j = 0;
  bool b = busqueda_lin(vest,x,j);
  if (not b)  cout << "El estudiante no está en el vector" << endl;
  else if (not vest[j].te_nota()) cout << "El estudiante está en el vector, pero no tiene nota" << endl;
  else cout << "El estudiante está en el vector y su nota es " << vest[j].consultar_nota() << endl;
}
