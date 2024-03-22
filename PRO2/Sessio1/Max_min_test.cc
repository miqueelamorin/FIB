#include <iostream>
#include <vector> 
using namespace std;

 void max_min3(const vector<int>& v, int& x, int& y)
 /* Pre: v.size()>0 */
 /* Post: x es el valor maximo de v;  y es el valor minimo de v */
 {
    x = y = v[0];
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] > x) x = v[i];
        if (v[i] < y) y = v[i];
    }
 }

 
 void leer_vector_int(vector<int>& v) {// version accion
  cout<<"Escribe el tamaño del vector:"<<endl;
  int numEst;
  cin >> numEst;
  v = vector<int> (numEst);
  
  cout<<"Escribe los elementos del vector:"<<endl;  
  for (int i=0; i<numEst;++i)
    cin >> v[i];
}
 
 int main() {
     vector<int> v;
     leer_vector_int(v);
     int x = 0, y = 0;
     max_min3(v, x, 0);
     cout << x << ' ' << y << endl;
 }
