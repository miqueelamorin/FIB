#include "BinTreeIOParInt.hh"

void read_bintree_parint(BinTree<ParInt>& a)
{
	ParInt x;
	BinTree<ParInt> l,r;
	if (x.llegir()){
		read_bintree_parint(l);
		read_bintree_parint(r);
	}
	a = BinTree<ParInt> (x,l,r);
}

void write_bintree_parint(const BinTree<ParInt>& a)
{
	if (not a.empty()) {
		ParInt x = a.value();
		write_bintree_parint(a.left());
		cout << " ";
		x.escriure();
		write_bintree_parint(a.right());
  }
}
