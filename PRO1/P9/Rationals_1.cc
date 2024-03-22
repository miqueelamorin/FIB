#include <typeinfo>
#include <iostream>
#include <algorithm>
using namespace std;

struct Racional {
  int num, den;
};

Racional racional(int n, int d) {
  Racional r;
	int mcd = __gcd(n, d);
 
	r.num = n/mcd;
	r.den = d/mcd;
	if (r.den < 0) {
		r.den = -r.den;
		r.num = -r.num;
	}
	return r;
}

int main() {

  { // Vigilem el tipus Racional.

    struct Racional_control {
      int num, den;
    };

    Racional r;
    Racional_control rc;

    // Diagnòstics en temps de compilació.
    r.num = rc.num;
    r.den = rc.den;

    // Diagnòstics en temps d'execució.
    if (sizeof(r) != sizeof(rc)) throw string("Sembla que 'Racional' no està ben definit");
    if (typeid(r.num) != typeid(rc.num)) throw string("Sembla que 'Racional.num' no està ben definit");
    if (typeid(r.den) != typeid(rc.den)) throw string("Sembla que 'Racional.den' no està ben definit");
  }

  int num, den;
  while (cin >> num >> den) {
    Racional r = racional(num, den);
    cout << r.num << " " << r.den << endl;
  }
}

