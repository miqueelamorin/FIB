//Interest
//given a capital, interest, years and type print final capital

#include <iostream>
using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(4);
    //read capital, interest, years
    double c, i, t;
    //read type of interest
    string type;
    cin >> c >> i >> t >> type;
    //declare the value of interest (sum)
    double interest = 0;
    if (type == "compound") {
        //while f <= years sum value of interest and add interest + c to c
        for (int f = 1; f <= t; ++f){
            interest = (i * c / 100);
            c = c + interest;
        }
        cout << c << endl;
    }
    else cout << c + ((i * c / 100) * t) << endl;
}
