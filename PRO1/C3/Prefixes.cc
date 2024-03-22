#include <string>
#include <iostream>
using namespace std;


// Pre: p, pref estàn formades per lletres minúscules
// Post: retorna true si pref és prefix de p, false en cas contrari
bool prefix(const string& p, const string& pref) {
    int i = 0;
    while (i < p.size() and i < pref.size()) {
        if (p[i] != pref[i]) return false;
        ++i;
    }
    return i == pref.size();
}

int main() {
    int line = 1;
    int n;
    while (cin >> n) {
        string firstw;
        cin >> firstw;
        int count = 1;
        for (int i = 1; i < n; ++i) {
            string nextw;
            cin >> nextw;
            if (prefix(firstw, nextw)) ++count;
        }

    cout << "Linea " << line << ": " << count << " - " << firstw << endl;
    ++line;
    count = 1;
    }
}