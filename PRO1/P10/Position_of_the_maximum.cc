#include <iostream>
#include <vector>
using namespace std;


int posicio_maxim(const vector<double>& v, int m){
    int pos = m;
    double max = v[m];
    for (int i = m - 1; i >= 0; --i) {
      if (v[i] >= max) pos = i, max = v[i];
    }
    return pos;
}