//Primality
//reads a sequence of naturals and tells if it is a prime number or not
#include <iostream>
using namespace std;

int main() {
    int n, seq, j;
    cin >> n;
    bool prime;
    //while the sequence lenght < n
    for (int i = 1; i <= n and cin >> seq; ++i){
        prime = true;
        if (seq > 2){
            //check for the case 2
            if (seq % 2 == 0) prime = false;
            j = 3;
            //check until j=sqrt(seq) or number has divisors
            while (prime and j * j <= seq){
                if (seq % j == 0) prime = false;
                j = j + 2;
            }
        }
        else if (seq >= 0 and seq <= 1) prime = false;
        if (seq >= 0){
            if (prime) cout << seq << " is prime" << endl;
            else cout << seq << " is not prime" << endl;
        }
    }
}
