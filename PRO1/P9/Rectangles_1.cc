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

int relacio(const Rectangle& r1, const Rectangle& r2) {
    if (r1.y_baix > r2.y_dalt or r1.y_dalt < r2.y_baix or r1.x_esq > r2.x_dre or r1.x_dre < r2.x_esq) return 0;
    else if (r2.y_baix == r1.y_baix and r2.y_dalt == r1.y_dalt and r2.x_dre == r1.x_dre and r2.x_esq == r1.x_esq) return 4;    
    else if (r1.y_baix >= r2.y_baix and r1.y_dalt <= r2.y_dalt and r1.x_dre <= r2.x_dre and r1.x_esq >= r2.x_esq) return 1;
    else if (r2.y_baix >= r1.y_baix and r2.y_dalt <= r1.y_dalt and r2.x_dre <= r1.x_dre and r2.x_esq >= r1.x_esq) return 2;
    else return 3;
}

int main() {
    int n; 
    cin >> n;
    Rectangle r1, r2;
    for (int i = 0; i < n; ++i) {
        llegeix(r1);
        llegeix(r2);
        int result = relacio(r1, r2);
        if (result == 1) cout << "el primer rectangle es interior al segon" << endl;
        else if (result == 2) cout << "el segon rectangle es interior al primer" << endl;
        else if (result == 3) cout << "els rectangles intersecten" << endl;
        else if (result == 4) cout << "els rectangles son iguals" << endl;
        else if (result == 0)cout << "els rectangles no intersecten" << endl;
    }
}