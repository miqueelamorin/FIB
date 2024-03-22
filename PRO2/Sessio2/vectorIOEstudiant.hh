#ifndef VECTOR_IO_ESTUDIANT	// per evitar errors de compilacio
#define VECTOR_IO_ESTUDIANT	// quan aquest fitxer s'inclou molts cops	

#include "Estudiant.hh"
#include <iostream>
#include <vector>

using namespace std;

/* Llegir vector */
void leer_vector_estudiant(vector<Estudiant>& vest);
/* Pre:  hi ha preparats al canal estandar d'entrada un estudiant est */
/* Post: v te N elements que son successivament els N estudiants
   qualssevol que hi eren al canal estandar d'entrada; se n'han
   avançat N i els N enters */

/* Escriure vector */
void escribir_vector_estudiant(const vector<Estudiant>& vest);
/* Pre: cert */
/* Post: s'han escrit tots els elements del vector */

#endif
