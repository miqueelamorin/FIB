#include <iostream>
#include "BinTreeIOParInt.hh"

using namespace std;

void cerca(bool& found, const BinTree<ParInt>& a, int x, int count)
{
    if(a.value().primer() != 0 and a.value().segon() != 0) {
        found = a.value().primer() == x;
        if (found) cout << x << " " << a.value().segon() << " " << count << endl;
        else {
            cerca(found, a.left(), x, count+1);
            if (not found) cerca(found, a.right(), x, count+1);
        }
    }
}


int main() {
    BinTree<ParInt> t;
    read_bintree_parint(t);
    int x, count = 0;
    bool found = false;

    while (cin >> x){
        cerca(found, t, x, count);
        if (not found) cout << -1 << endl;

    }
}
