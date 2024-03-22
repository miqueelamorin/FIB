//Movements on the ground
//reads a sequence of characters and prints the final position of an object
#include <iostream>
using namespace std;

int main() {
    char p;
    int vertical = 0, horizontal = 0;
    bool exit = false;
    //any letter not being n,s,e,w exits the while
    while (not exit and cin >> p){
        if (p == 'n') --vertical;
        else if (p == 's') ++vertical;
        else if (p == 'e') ++horizontal;
        else if (p == 'w') --horizontal;
        else exit = true;
    }
    cout << '(' << horizontal << ", " << vertical << ')' << endl;
}
