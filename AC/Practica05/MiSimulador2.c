#include "CacheSim.h"
#include <stdio.h>

/* Posa aqui les teves estructures de dades globals
 * per mantenir la informacio necesaria de la cache
 * */

typedef struct{
    int via[2];
    int valid[2];
    int LRU;
}dos_associativa;

dos_associativa cache[64];

int misses = 0;
int hits = 0;


/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La cache es inicialitzada al començar cada un dels tests.
 * */
void init_cache ()
{
    totaltime=0.0;
	/* Escriu aqui el teu codi */

    for (int i = 0; i < 64; i++) {
        cache[i].valid[0] = 0;
        cache[i].valid[1] = 0;
        cache[i].LRU = 1;
    }

}

/* La rutina reference es cridada per cada referencia a simular */ 
void reference (unsigned int address)
{
	unsigned int byte;
	unsigned int bloque_m; 
	unsigned int conj_mc;
	unsigned int via_mc;
	unsigned int tag;
	unsigned int miss;	   // boolea que ens indica si es miss
	unsigned int replacement;  // boolea que indica si es reemplaça una linia valida
	unsigned int tag_out;	   // TAG de la linia reemplaçada
	float t1,t2;		// Variables per mesurar el temps (NO modificar)
	
	t1=GetTime();
	/* Escriu aqui el teu codi */

    byte = address & 0x1F; //extraiem els ultims 5 bits
    bloque_m = address >> 5; //eliminem els 5 bits de byte
    conj_mc = bloque_m & 0x3F; //extraiem els ultims 6 bits de la linia
    tag = bloque_m >> 6; //eliminem els ultims 6 bits i ens queda el tag

    miss = 0;
	replacement = 0;
	tag_out = 0;

    if (tag == cache[conj_mc].via[0] && cache[conj_mc].valid[0]) {     //hit a la via 0 i bit valid
        cache[conj_mc].LRU = via_mc = 0;    //utilitzem la via 0 (LRU)
        replacement = 0;
        ++hits;
    }
    else if (tag == cache[conj_mc].via[1] && cache[conj_mc].valid[1]){ //hit a la via 1 i bit valid
        cache[conj_mc].LRU = via_mc = 1;    //utilitzem la via 1 (LRU)
        replacement = 0;
        ++hits;
    }

    else{   //cas fallada
        miss = 1;
        ++misses;
        if (cache[conj_mc].LRU == 0) {  //si el last used es la via 0
			if (cache[conj_mc].valid[1]) {   //comprovem que la via 1 estigui ocupada
				replacement = true;
				tag_out = cache[conj_mc].via[1];   //aleshores hem de reemplaçar la via1 perque s?ha utilitzat abans que la via 0 (mes antiga)
			}
			cache[conj_mc].valid[1] = 1;         //valid = 1
			cache[conj_mc].via[1] = tag;         //afegim a la cache
			cache[conj_mc].LRU = via_mc = 1;     //marquem la via 1 com a ultima utilitzada
		}
        else {                                      //via1 last used
			if (cache[conj_mc].valid[0]) {
				replacement = true;
				tag_out = cache[conj_mc].via[0];
			}
			cache[conj_mc].valid[0] = 1;
			cache[conj_mc].via[0] = tag;
			cache[conj_mc].LRU = via_mc = 0;
		}
	}

	/* La funcio test_and_print escriu el resultat de la teva simulacio
	 * per pantalla (si s'escau) i comproba si hi ha algun error
	 * per la referencia actual. També mesurem el temps d'execució
	 * */
	t2=GetTime();
	totaltime+=t2-t1;
	test_and_print2 (address, byte, bloque_m, conj_mc, via_mc, tag,
			miss, replacement, tag_out);
}

/* La rutina final es cridada al final de la simulacio */ 
void final ()
{
 	/* Escriu aqui el teu codi */ 
    printf("misses: %d, hits: %d\n", misses, hits);
  
}
