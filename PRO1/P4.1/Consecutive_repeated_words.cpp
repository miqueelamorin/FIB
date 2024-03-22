//Consecutive repeated words
//reads a sequence of words and tells the largest sequence with the first word
#include <iostream>
using namespace std;

int main() {
    string first, seq;
    int count = 1, max = 1;
    cin >> first;
    while (cin >> seq) {
        //if it doesn't coincide count equals 0
        if (seq != first) count = 0;
        //add 1 to count and if it's superior to max update value
        else {
          ++count;
          if (count > max) max = count;
        }   
    }
    cout << max << endl;
}