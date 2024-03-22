//prints if contains any peak greater than 3143

#include <iostream>
using namespace std;

int main() {
    int seq, last = 0, peak = 0;
    bool higher = false;
    while (cin >> seq and seq != 0){
        if (peak > 3143 and peak > last and peak > seq and last != 0) higher = true;
        last = peak;
        peak = seq;
    }
    if (higher) cout <<  "YES" << endl;
    else cout << "NO" << endl;
}
