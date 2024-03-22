//Tres ultimes xifres
//compta i escriu nombres que acabin amb les mateixes tres xifres que el primer
#include <iostream>
using namespace std;

int main() {
    int n, ndiv, seq, seqdiv, count = 0;
    cin >> n;
    //extreure ultimes 3 xifres del primer nombre
    ndiv = n % 1000;
    cout << "nombres que acaben igual que " << n << ':' << endl;
    while (cin >> seq){
        //extreure ultimes 3 xifres
        seqdiv = seq % 1000;
        //si les 3 ultimes xifres son iguals
        if (ndiv == seqdiv){
            ++count;
            cout << seq << endl;
        }
    }
    cout << "total: " << count << endl;
}
