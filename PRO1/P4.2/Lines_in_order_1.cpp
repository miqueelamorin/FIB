//tells which is the first line that has the words in increasing (lexicographic) order

#include <iostream>
using namespace std;

int main() {
    int n, line = 0, firstline = 0;
    bool increasing = true;
    while (cin >> n and firstline == 0){
        increasing = true;
        string prev = "a", seq;
        for (int i = 1; i <= n and cin >> seq; ++i){
//             cout << "seq " << seq << endl;
//             cout << "prev " << prev << endl;
            if (seq < prev) increasing = false;
            prev = seq;
        }
        ++line;
        if (increasing) firstline = line;
    }
    if (firstline != 0) cout << "The first line in increasing order is " << firstline << '.' << endl;
    else cout << "There is no line in increasing order." << endl;
}
