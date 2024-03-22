#include <iostream>
#include <vector>
using namespace std;


int posicio(double x, const vector<double>& v, int esq, int dre) {
    if (esq > dre) return -1;
    int i = (esq + dre)/2;
    if (v[i] < x) return posicio (x, v, i+1, dre);
    if (v[i] > x) return posicio (x, v, esq, i-1);
    return i;
}