//prints its minimum, its maximum and its average

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        int m;
        cin >> m;
        double seq1, seq, max, min, sum;
        cin >> seq1;
        max = seq1;
        min = seq1;
        sum = seq1;
        for (int j = 1; j < m; ++j){
            cin >> seq;
            if (seq > max) max = seq;
            if (seq < min) min = seq;
            sum += seq;
        }
        cout.setf(ios::fixed);
        cout.precision(4);
        cout << min << ' ' << max << ' ' << sum/m << endl;
    }
}
