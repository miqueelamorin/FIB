//Computing areas
//reads descriptions of rectangles or circles and prints its areas
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(6);
    //reads the number of descriptions
    int n;
    cin >> n;
    //for i < number of descriptions create var type and x y
    for (int i = 0; i < n; i++) {
        string type;
        cin >> type;
        //expect base and altura and mult them
        if (type == "rectangle") {
            double base, altura;
            cin >> base >> altura;
            cout << base * altura << endl;
        }
        //expect radius and mult by itself and pi
        else {
            double radius;
            cin >> radius;
            cout << radius * radius * M_PI << endl;
        }
    }
}
