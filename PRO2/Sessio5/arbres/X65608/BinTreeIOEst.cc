#include "BinTreeIOEst.hh"

void read_bintree_est(BinTree<Estudiant>& a)
{
	Estudiant est;
	est.llegir();
	BinTree<Estudiant> l,r;
	if (est.consultar_DNI() != 0){
		read_bintree_est(l);
		read_bintree_est(r);
	}
	a = BinTree<Estudiant> (est,l,r);
}
