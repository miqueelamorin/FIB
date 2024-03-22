#include <iostream>
#include "BinTree.hh"

using namespace std;

void write_bintree_int(const BinTree<int> &a)
{
	if (not a.empty()) {
		int x = a.value();
		write_bintree_int(a.left());
		cout << " " << x;
		write_bintree_int(a.right());
  }
}

void read_bintree_int(BinTree<int>& a,int marca)
{
  int x;
  cin >> x;
  if (x!=marca){
	BinTree<int> l;
	read_bintree_int(l,marca);
	BinTree<int> r;
	read_bintree_int(r,marca);
	a=BinTree<int>(x,l,r);
  }
}

bool poda_subarbre(BinTree<int> &a, int x)
{
    
}

int main() {
    BinTree<int> t;
    read_bintree_int(t, 0);
	int x;
	cin >> x;
	bool b = poda_subarbre(t, x);

	cout << b << endl;
	write_bintree_int(t);
	cout << endl;
}
