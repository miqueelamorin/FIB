#include <iostream>
#include <vector>
using namespace std;

int potencia (int n, int k, int m){
    if (k == 0) return 1;
    else {
        int y = potencia(n, k/2, m);
        y = (y*y)%m;
        if (k % 2 == 0) return y;
        else return (y*n)%m;
    }
}


int main() {
    int n, k, m;
    while (cin >> n >> k >> m) cout << potencia(n, k, m) << endl;
}
