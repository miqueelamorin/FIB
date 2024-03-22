#include "CacheSim.h"
#include <stdio.h>

/* Posa aqui les teves estructures de dades globals
 * per mantenir la informacio necesaria de la cache
 * */

int cache[128]; //128*32bytes = 4KB

int misses = 0;
int hits = 0;


/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La cache es inicialitzada al comen�ar cada un dels tests.
 * */
void init_cache ()
{
    totaltime=0.0;
	/* Escriu aqui el teu codi */

    for (int i = 0; i < 128; i++) cache[i] = -1; //buidem la cache
}

/* La rutina reference es cridada per cada referencia a simular */ 
void reference (unsigned int address)
{
	unsigned int byte;
	unsigned int bloque_m; 
	unsigned int linea_mc;
	unsigned int tag;
	unsigned int miss;	   // boolea que ens indica si es miss
	unsigned int replacement;  // boolea que indica si es reempla�a una linia valida
	unsigned int tag_out;	   // TAG de la linia reempla�ada
	float t1,t2;		// Variables per mesurar el temps (NO modificar)
	
	t1=GetTime();
	/* Escriu aqui el teu codi */

    byte = address & 0x1F; //extraiem els ultims 5 bits
    bloque_m = address >> 5; //eliminem els 5 bits de byte
    linea_mc = bloque_m & 0x7F; //extraiem els ultims 7 bits de la linia
    tag = bloque_m >> 7; //eliminem els ultims 7 bits i ens queda el tag

    miss = 0;
	replacement = 0;
	tag_out = 0;

    if (tag != cache[linea_mc]) {   //si el tag no es troba en la linia de la cache
        miss = 1;
        ++misses;
		if (cache[linea_mc] != -1) {  //si estava ocupada hem de fer un replacement
			replacement = 1;
			tag_out = cache[linea_mc];   //tag out �s el tag anterior
		}
        cache[linea_mc] = tag;  //afegim el tag a la linia
	}
	else ++hits;

	/* La funcio test_and_print escriu el resultat de la teva simulacio
	 * per pantalla (si s'escau) i comproba si hi ha algun error
	 * per la referencia actual. Tamb� mesurem el temps d'execuci�
	 * */
	t2=GetTime();
	totaltime+=t2-t1;
	test_and_print (address, byte, bloque_m, linea_mc, tag,
			miss, replacement, tag_out);
}

/* La rutina final es cridada al final de la simulacio */ 
void final ()
{
 	/* Escriu aqui el teu codi */ 
  printf("misses: %d, hits: %d\n", misses, hits);
  
}
