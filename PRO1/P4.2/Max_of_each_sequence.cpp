//prints the maximum value of each sequence

#include <iostream>
using namespace std;

int main() {
    int n, max, seq1, seq;
    while (cin >> n){
        cin >> seq1;
        max = seq1;
        for (int i = 2; i <= n and cin >> seq; ++i){
            if (seq > max) max = seq;
        }
        cout << max << endl;
    }
}
