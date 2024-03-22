//Data Comparison
//Reads a pair of dates and tells if the first one is anterior or posterior to the second one

#include <iostream>
using namespace std;

int compara(int d1, int m1, int a1, int d2, int m2, int a2){
    if (a1 < a2) return -1;
    else if (a1 > a2) return 1;
    else{
        if (m1 < m2) return -1;
        else if (m1 > m2) return 1;
        else{
            if (d1 < d2) return -1;
            else if (d1 > d2) return 1;
            else return 0;
        }
    }
}

int main() {
    int d1, m1, a1, d2, m2, a2;
    char bar;
    //reads several double numbers
    while(cin >> d1 >> bar >> m1 >> bar >> a1 and cin >> d2 >> bar >> m2 >> bar >> a2){
        int result = compara (d1, m1, a1, d2 , m2, a2);
        if (result < 0) cout << "anterior";
        else if (result > 0) cout << "posterior";
        else cout << "iguals";
        cout << endl;
    }
}