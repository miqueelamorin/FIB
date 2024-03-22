#include <iostream>
#include <map>
using namespace std;

int main() {
    int x, y, n;
    while (cin >> x >> y >> n) {
        map<int,int> m;
        bool found = false;
        int count = 0;
        m[n] = count;
        map<int,int>::iterator it;

        while (n <= 100000000 and not found){
            ++count;
            if (n%2 == 0) n = n/2 + x;
            else n = 3*n + y;

            it = m.find(n);
            if (it != m.end()) found = true;
            else m[n] = count;
        }

        if (found) cout << m.size() - it->second << endl;
        else cout << n << endl;
    }
}
