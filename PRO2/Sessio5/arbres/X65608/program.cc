#include <iostream>
#include "BinTreeIOEst.hh"

using namespace std;

void cerca(bool& found, const BinTree<Estudiant>& a, int dni, int count)
{
    if (not a.empty()){
        found = (a.value().consultar_DNI() == dni);
        if (found) {
            cout << dni << ' ' << count << ' ';
            if (a.value().te_nota()) cout << a.value().consultar_nota();
            else cout << -1;
            cout << endl;
        }
        else {
            cerca(found, a.left(), dni, count+1);
            if (not found) cerca(found, a.right(), dni, count+1);
        }
    }
}


int main() {
    BinTree<Estudiant> t;
    read_bintree_est(t);
    int dni, count = 0;
    bool found = false;

    while (cin >> dni){
        cerca(found, t, dni, count);
        if (not found) cout << dni << ' ' << -1 << endl;

    }
}
