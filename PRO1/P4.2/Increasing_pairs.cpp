#include <iostream>
using namespace std;

int main() {
    int n, seq;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        int count = 0; int prev = 0;
        while (cin >> seq and seq != 0){
            if (seq > prev and prev != 0) ++count;
            prev = seq;
        }
        cout << count << endl;
    }
}
