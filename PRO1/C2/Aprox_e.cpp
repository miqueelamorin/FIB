#include <iostream>
using namespace std;

double den(int i)
{
    if (i == 0) return 1;
    else return (i * den(i - 1));
}

int main()
{
    int n;
    while (cin >> n){
        double result = 0;
        for (int i = 0; i < n; ++i){
            result += 1/den(i);
        }
        cout.setf(ios::fixed);
        cout.precision(10);
        cout << "Amb " << n << " terme(s) s'obte " << result << '.' << endl;
    }
}