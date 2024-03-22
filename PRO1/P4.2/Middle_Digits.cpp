//Print ‘A’, ‘B’, or ‘=’, depending on whether Anna wins, Bernard wins, or it is a tie

#include <iostream>
using namespace std;

int main() {
    int n, i;
    cin >> n;
    int seq, middle = 0, firstmidd = 0;
    bool parell = false, perd = false;
    for (i = 1; i <= (2 * n) and cin >> seq and not perd and not parell; ++i){
        int posit = seq, count = 1;
        while (posit > 9){
            posit /= 10;
            ++count;
        }
//        cout << "count " << count << endl;
        if (count % 2 != 0){
            for (int j = 0; j < count / 2 + 1; ++j){
                middle = seq % 10;
                seq /= 10;
            }
            if (i == 1) firstmidd = middle;
            else {
                if (firstmidd != middle) perd = true;
            }
        }
        else perd = true;
    }
    i = i - 1;
//     cout << "i " << i << endl;
//     cout << "perd " << perd << endl;
//     cout << "par " << parell << endl;
//     cout << "midd " << middle << endl;
//     cout << "fmid " << firstmidd << endl;
    if (perd and i % 2 == 0) cout << 'A' << endl;
    else if (perd and i % 2 != 0) cout << 'B' << endl;
    else cout << '=' << endl;
}
