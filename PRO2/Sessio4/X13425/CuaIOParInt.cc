#include "CuaIOParInt.hh"

void llegirCuaParInt(queue<ParInt>& c){
  ParInt p;
  while (p.llegir()){
    c.push(p);
  }
}
 
void escriureCuaParInt(queue<ParInt> c){
  while(not c.empty()){
    c.front().escriure();
    c.pop();
  }
}
