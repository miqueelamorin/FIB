#include "LlistaIOParInt.hh"

void LlegirLlistaParInt(list<ParInt>& l){
  list<ParInt>::iterator it = l.end();
  ParInt x; 
  while (x.llegir()) {
    l.insert(it, x);
  }
}

void EscriureLlistaParInt(const list<ParInt>& l) {
  if (not l.empty()) {
    list<ParInt>::const_iterator it;

    for (it = l.begin(); it != l.end(); ++it){
      (*it).escriure(); 
      cout << " "; 
    }                     

  } 
  cout << endl;
}

