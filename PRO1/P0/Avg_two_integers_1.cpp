//Average
//write average of two integers

#include <iostream>
using namespace std;

int main() {
    //read two integers
    int n1,n2;
    cin >> n1 >> n2;
    //print the average of two integers
    //the divider must be 2.0 to be able to print 6.5
    //promote the integer 2 to double
    cout << (n1 + n2)/double(2) << endl;
  
}
