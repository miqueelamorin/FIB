#include <iostream>
#include <vector>
using namespace std;

// Pre: --
// Post: retorna la posició de l'últim element de v amb valor inferior a x,
//       retorna -1 si aquest element no existeix
int last_position_of(const vector<int>& v, double x){
    int vsize = v.size();
    int maxposition = -1;
    for (int i = 0; i < vsize; ++i){
        if (v[i] < x) maxposition = i;
    }
    return maxposition;
}

//Pre: S is an empty sequence of size n
//Post: fills the vector and computes the average of even elements
void read_and_evenaverage(vector<int>& S, double& avg){
    int size = S.size();
    int even_numbers = 0;
    for (int i = 0; i < size; ++i){ 
        cin >> S[i];
        if (S[i]%2 == 0){
            avg += S[i];
            ++even_numbers;
        }
    }
    avg = avg/even_numbers;
}

//Pre: n > 0 followed by a sequence of n elements >= 0
//     at least one of them is even
//Post: returns position of the last element lower than the average of even values
int main() {
    int n;
    while (cin >> n){
        vector<int> S(n);
        double avg = 0;
        read_and_evenaverage(S, avg);
        cout << last_position_of(S, avg) << endl;
    }
}