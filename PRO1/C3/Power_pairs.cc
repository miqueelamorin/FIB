#include <iostream>
using namespace std;

// Pre: n >= 0, base > 1
// Post: returns true when n is a power of base.
//       returns false otherwise
bool is_power(int n, int base) {
    if (base == 1) return true;
    else {    
        int mult = 1;
        while (mult < n) mult *= base;
        return mult == n;
    }
}

int trobar_pot(int n) {
    for (int i = 2; i * i <= n; ++i){
        if (is_power(n, i)) return i; 
    }
    return n;
}

int main() {
    int curr;
    int prev;
    while (cin >> prev){
        int count = 0;
        
        cin >> curr;
        while (curr != 0) {
            if (is_power(curr,(trobar_pot(prev)))) ++count;
            prev = curr;
            cin >> curr;
        }
        cout << count << endl;
    }
}