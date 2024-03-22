//prints the number of the n-th first letters in the sequence that are between c1 and c2

#include <iostream>
using namespace std;

int main()
{
    int n, count = 0;
    char c1, c2, seq;
    cin >> n >> c1 >> c2;
    int i = 1;
    while (cin >> seq and i <= n){
        if (c1 <= seq and seq <= c2) ++count;
        ++i;
        }
    cout << count << endl;
}
