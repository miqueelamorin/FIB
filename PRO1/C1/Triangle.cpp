//Draw the outline of a right triangle of size n

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int j = 1; j <= n; ++j) cout << '*';
    cout << endl;
    for (int i = 2; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            if (i == j) cout << '*';
            else if (n == j) cout << '*';
            else cout << ' ';
        }
        cout << endl;
    }
}
