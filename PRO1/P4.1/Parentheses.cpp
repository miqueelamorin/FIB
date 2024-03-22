//Parentheses
//reads a sequence of parentheses and tells if they close correctly
#include <iostream>
using namespace std;

int main() {
    char p;
    int count = 0;
    bool exit = false;
    //add or subt to count if parentheses opens or closes
    while (not exit and cin >> p) {
        if (p == '(') ++count;
        else if (p == ')'){
            --count;
            //if count is negative, exit the while
            //bc we're closing more things than opened ones
            if (count < 0)exit = true;
        }
        else exit = true;
    }
    if (count == 0) cout << "yes" << endl;
    else cout << "no" << endl;
}
