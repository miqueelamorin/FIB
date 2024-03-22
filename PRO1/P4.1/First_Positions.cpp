//First position
//reads a sequence of numbers and prints the position of the first even number
#include <iostream>
using namespace std;

int main() {
    int n, position = 1;
    bool exit = false;
    //keep adding 1 to position until n%2!=0 then exit
    while (not exit and cin >> n){
        if (n % 2 == 0) exit = true;
        else ++position;
    }
    cout << position << endl;
}
