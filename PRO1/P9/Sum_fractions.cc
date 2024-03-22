#include <typeinfo>
#include <iostream>
#include <algorithm>
using namespace std;

struct Fraccio {
    int num, den;   // sempre estrictament positius
};

Fraccio simplifica(Fraccio& r) {
    if (r.den > 1) {
		int e = __gcd(r.num, r.den);
		r.num /= e;
		r.den /= e;
	}
    return r;
}

Fraccio suma(const Fraccio& x, const Fraccio& y) {
    Fraccio r;
    r.den = x.den*y.den;
    r.num = x.num*y.den + y.num*x.den;
    return r;
}

int main() {
	Fraccio primera, acumulada;
	acumulada.num = 0;
	acumulada.den = 1;
	char useless;
	bool keep = true;
	while (keep) {
		cin >> primera.num >> useless >> primera.den >> useless;
		if (useless == '=') keep = false;
		simplifica(primera);
		acumulada = suma(primera, acumulada);
		simplifica(acumulada);
	}
	cout << acumulada.num << "/" << acumulada.den << endl;
}