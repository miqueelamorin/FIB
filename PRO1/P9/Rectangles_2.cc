#include <typeinfo>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Rectangle {
    int x_esq, x_dre, y_baix, y_dalt;
};

void llegeix(Rectangle& r) {
    cin >> r.x_esq >> r.x_dre >> r.y_baix >> r.y_dalt;
}

bool es_intersec(const Rectangle& r) {
    if (r.x_dre == -1 and r.x_esq == -1 and r.y_dalt == -1 and r.y_baix == -1) return false;
    else return true;
}

Rectangle intersec(const Rectangle& r1, const Rectangle& r2) {
    Rectangle res;
    if (r1.x_esq > r2.x_esq) res.x_esq = r1.x_esq;
    else res.x_esq = r2.x_esq;
    if (r1.x_dre < r2.x_dre) res.x_dre = r1.x_dre;
    else res.x_dre = r2.x_dre;
    if (r1.y_baix > r2.y_baix) res.y_baix = r1.y_baix;
    else res.y_baix = r2.y_baix;
    if (r1.y_dalt < r2.y_dalt) res.y_dalt = r1.y_dalt;
    else res.y_dalt = r2.y_dalt;
    return res;
}

Rectangle relacio(const Rectangle& r1, const Rectangle& r2) {
    Rectangle res;
    if (r2.y_baix == r1.y_baix and r2.y_dalt == r1.y_dalt and r2.x_dre == r1.x_dre and r2.x_esq == r1.x_esq) return r1;  
    else if (r1.y_baix >= r2.y_baix and r1.y_dalt <= r2.y_dalt and r1.x_dre <= r2.x_dre and r1.x_esq >= r2.x_esq) return r1;
    else if (r2.y_baix >= r1.y_baix and r2.y_dalt <= r1.y_dalt and r2.x_dre <= r1.x_dre and r2.x_esq >= r1.x_esq) return r2;
    else if (r1.y_baix > r2.y_dalt or r1.y_dalt < r2.y_baix or r1.x_esq > r2.x_dre or r1.x_dre < r2.x_esq) {
        res.x_dre = res.x_esq = res.y_dalt = res.y_baix = -1;
        return res;
    }
    else return intersec(r1, r2);
}

int main() {
    int n;
    cin >> n;
    Rectangle r1, r2;
    while (n != 0){
        llegeix(r1);
        bool interseccio = true;
        for (int i = 1; i < n; i++) {
            llegeix(r2);
            if (interseccio) {
                Rectangle res = relacio(r1, r2);
                interseccio = es_intersec(res);
                r1 = res;
            }
        }
        if (not interseccio or r1.x_esq == r1.x_dre or r1.y_baix == r1.y_dalt) cout << "interseccio buida" << endl;
        else {
            cout << "punt inferior esquerre = (" << r1.x_esq << ", " << r1.y_baix << ");";
            cout << " punt superior dret = (" << r1.x_dre << ", " << r1.y_dalt << ")" << endl;
        }
        cin >> n;
    }
}