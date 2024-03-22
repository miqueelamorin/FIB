//I-th (1)
//Print the content of the position i
#include <iostream>
using namespace std;

int main() {
    int i;
    cin >> i;
    int seq, count = 0;
    while (cin >> seq){
        ++count;
        if (count == i) cout << "At the position " << i << " there is a(n) " << seq <<
                        '.' << endl;
    }
    //if the sequence has less positions that i
    if (count < i or i <= 0) cout << "Incorrect position." << endl;
}
