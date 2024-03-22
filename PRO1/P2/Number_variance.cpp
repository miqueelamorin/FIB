//C202B
//donat un natural n≥ 2 seguit de n nombres reals x1, x2,…, xn, calculi la variança dels nombres
#include <iostream>
using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(2);
    //reads a number indicating the lenght of a sequence of numbers
    int n;
    cin >> n;
    double x, result, sum1 = 0, sum2 = 0;
    //while input x make 2 sums (1 each term elevated to 2)
    while (cin >> x){
        sum1 += x*x;
        sum2 += x;
    }
    result = ((1.0 / (n - 1)) * sum1) - ((1.0 / (n * (n - 1))) * (sum2 * sum2));
    cout << result << endl;
}
