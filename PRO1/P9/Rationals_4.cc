#include <typeinfo>
#include <iostream>
#include <algorithm>
using namespace std;

struct Racional {
  int num, den;
};

int Mcd(int a, int b) {
  if (b == 0) return a;
  else return Mcd(b,a%b);
}

Racional simplifica(Racional& r) {
  int mcd = Mcd(r.num, r.den);
  Racional res;
	res.num = r.num/mcd;
	res.den = r.den/mcd;
	if (res.den < 0) {
		res.den = -res.den;
		res.num = -res.num;
	}
	return res;
}

Racional suma(Racional& r1, Racional& r2) {
  Racional r;
  r.den = r1.den*r2.den;
  r.num = r1.num*r2.den + r2.num*r1.den;
  return simplifica(r);
}

Racional multiplica(Racional& r1, Racional& r2) {
  Racional r;
  r.den = r1.den*r2.den;
  r.num = r1.num*r2.num;
  return simplifica(r);
}

void escriu_racional(Racional& r) {
  if (r.num == 0) cout << 0 << endl;
  else if (r.den == 1) cout << r.num << endl;
  else cout << r.num << "/" << r.den << endl;
}

int main() {
  Racional r1, r2;
  cin >> r1.num >> r1.den;
  r1 = simplifica(r1);
  string op;
  escriu_racional(r1);
  while (cin >> op) {
    if (op == "suma") {
            cin >> r2.num >> r2.den;
            r1 = suma(r1,r2);
        }
        else if (op == "resta") {
            cin >> r2.num >> r2.den;
            r2.num = -r2.num;
            r1 = suma(r1,r2);
        }
        else if (op == "multiplica") {
            cin >> r2.num >> r2.den;
            r1 = multiplica(r1,r2);
        }
        else if (op == "divideix") {
            cin >> r2.den >> r2.num;
            r1 = multiplica(r1,r2);
        }
        escriu_racional(r1);
  } 
}

