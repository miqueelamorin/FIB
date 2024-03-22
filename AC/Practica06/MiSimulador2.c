#include "CacheSim.h"
#include <stdio.h>

/* Posa aqui les teves estructures de dades globals
 * per mantenir la informacio necesaria de la cache
 * */

struct line{
	int tag;
	int dirty;
};

line cache[128]; //128*32bytes = 4KB

int misses = 0;
int hits = 0;


/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La cache es inicialitzada al comen�ar cada un dels tests.
 * */
void init_cache ()
{
	/* Escriu aqui el teu codi */

	for (int i = 0; i < 128; i++) {
		cache[i].tag = -1; //buidem la cache
		cache[i].dirty = false;
	}

}

/* La rutina reference es cridada per cada referencia a simular */ 
void reference (unsigned int address, unsigned int LE)
{
	unsigned int byte;
	unsigned int bloque_m; 
	unsigned int linea_mc;
	unsigned int tag;
	unsigned int miss;
	unsigned int lec_mp;
	unsigned int mida_lec_mp;
	unsigned int esc_mp;
	unsigned int mida_esc_mp;
	unsigned int replacement;
	unsigned int tag_out;

	/* Escriu aqui el teu codi */

	byte = address & 0x1F; //extraiem els ultims 5 bits
    bloque_m = address >> 5; //eliminem els 5 bits de byte
    linea_mc = bloque_m & 0x7F; //extraiem els ultims 7 bits de la linia
    tag = bloque_m >> 7; //eliminem els ultims 7 bits i ens queda el tag

	miss = false;
	replacement = false;
	tag_out = 0;

	lec_mp = false;
	esc_mp = false;

	if (LE == lectura){
		if (cache[linea_mc] != tag){ //fallada de lectura
			++misses;
			miss = true;
			
			lec_mp = true;			//hem de llegit 32 bytes de mp
			mida_lec_mp = 32;

			if (cache[linea_mc] != -1) {  //si estava ocupada hem de fer un replacement
				replacement = 1;
				tag_out = cache[linea_mc];   //tag out és el tag anterior
			}

			cache[linea_mc] = tag;  //afegim el tag a la linia
		}
		else ++hits;
		
	}
	else{
		esc_mp = true;		//escrivim 1 byte a mp
		mida_esc_mp = 1;
		
		if (cache[linea_mc] != tag) {	//si no esta a mc fallada d'escriptura
			++misses;
			miss = true;
		} 

		else ++hits;
	}

	/* La funcio test_and_print escriu el resultat de la teva simulacio
	 * per pantalla (si s'escau) i comproba si hi ha algun error
	 * per la referencia actual
	 * */
	test_and_print (address, LE, byte, bloque_m, linea_mc, tag,
			miss, lec_mp, mida_lec_mp, esc_mp, mida_esc_mp,
			replacement, tag_out);
}

/* La rutina final es cridada al final de la simulacio */ 
void final ()
{
 	/* Escriu aqui el teu codi */ 
	printf("misses: %d, hits: %d\n", misses, hits);
  
}
