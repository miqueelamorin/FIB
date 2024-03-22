#include <typeinfo>
#include <iostream>
#include <cmath>
using namespace std;

struct Punt {
  double x, y;
};

double distancia(const Punt& a, const Punt& b) {
  return sqrt(pow((a.x - b.x),2 ) + pow((a.y - b.y), 2));
}


int main() {

  {   // vigilar el tipus Punt

        struct Punt_cntrl {
            double x, y;
        };

        Punt ru;
        Punt_cntrl rc;

        // diagn�stics en temps de compilaci�  
        ru.x = rc.x;  
        ru.y = rc.y;  

        // diagn�stics en temps d'execuci�
        if (sizeof(ru)!=sizeof(rc))     throw string("Sembla que 'Punt' no est� ben definit");
        if (typeid(ru.x)!=typeid(rc.x)) throw string("Sembla que 'Punt.x' no est� ben definit");
        if (typeid(ru.y)!=typeid(rc.y)) throw string("Sembla que 'Punt.y' no est� ben definit");
  }


  cout.setf(ios::fixed);
  cout.precision(6);

  double x1, y1, x2, y2;
  while (cin >> x1 >> y1 >> x2 >> y2) {
    Punt a, b;
    a.x = x1;
    a.y = y1;
    b.x = x2;
    b.y = y2;
    cout << distancia(a, b) << endl;
  }
}
