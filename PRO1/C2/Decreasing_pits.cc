//Decreasing pits
//Pre: n > 0 and sequence has 1 minimum element
//Post: how many elements are less than all their predecessors
//Post: and less than their immediate successor

#include <iostream>
using namespace std;

int main() {
    int sequences;
    cin >> sequences;

    for (int i = 0; i < sequences; ++i){
        int prev;
        cin >> prev;
        int min = prev + 1;
        int count = 0;
        int n;
        cin >> n;

        while (n != 0){
            if (prev < min) {
                min = prev;
                if (prev < n) ++count;
            }
            prev = n;
            cin >> n;
        }

    cout << count << endl;
    }
   
}