//tells which is the last line that has the words in increasing (lexicographic) order

#include <iostream>
using namespace std;

int main() {
    int n, line = 0, lastline = 0;
    bool increasing = true;
    while (cin >> n){
        increasing = true;
        string prev = "a", seq;
        for (int i = 1; i <= n and cin >> seq; ++i){
//             cout << "seq " << seq << endl;
//             cout << "prev " << prev << endl;
            if (seq < prev) increasing = false;
            prev = seq;
        }
        ++line;
        if (increasing) lastline = line;
    }
    if (lastline != 0) cout << "The last line in increasing order is " << lastline << '.' << endl;
    else cout << "There is no line in increasing order." << endl;
}
