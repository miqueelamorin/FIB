//reads a sequence of letters that ends with a dot and tells if it contains the succession of consecutive letters ‘h’, ‘e’, ‘l’, ‘l’, ‘o’ or not

#include <iostream>
using namespace std;

int main() {
    char seq;
    bool h = false, he = false, hel = false, hell = false, hello = false;
    while (cin >> seq and seq != '.'){
        if (seq == 'h') h = true;
        else if (h and seq == 'e') he = true, h = false;
        else if (he and seq == 'l') hel = true,he = false;
        else if (hel and seq == 'l') hell = true, hel = false;
        else if (hell and seq == 'o') hello = true, hell = false;
        else h = false, he = false, hel = false, hell = false;
//     cout << seq << endl;
//     cout << h << endl;
//     cout << he << endl;
//     cout << hel << endl;
//     cout << hell << endl;
//     cout << hello << endl;
    }
    if (hello) cout << "hello" << endl;
    else cout << "bye" << endl;
}

