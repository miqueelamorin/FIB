#include <iostream>
using namespace std;

// Pre: x > 0
// Post: retorna el valor que resulta d'eliminar a x els seus dígits igual a 0
int elimina_zeros(int x) {
    if (x < 10 and x > 0) return x;
    else
    {
       if (x % 10 == 0) return elimina_zeros(x/10);
       else return x%10 + 10*elimina_zeros(x/10);

    //elimina_zeros(x%10);
}
}

int main() {
    int n;
    while (cin >> n){
        cout << elimina_zeros(n) << endl;
    }
}