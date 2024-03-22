#include <iostream>
#include <map>
using namespace std;

int main() {
    map <string, int> casino;
    string name, op;
    while (cin >> name >> op){
        if (op == "enters") {
            if (casino.find(name) != casino.end()) cout << name << " is already in the casino" << endl;
            else casino[name] = 0;
        }

        else if (op == "leaves") {
            if (casino.find(name) != casino.end()) {
                cout << name << " has won " << casino[name] << endl;
                casino.erase(name);
            }
            else cout << name << " is not in the casino" << endl;
        }

        else if (op == "wins") {
            int points;
            cin >> points;
            auto it = casino.find(name);
            if (it != casino.end()){
                it->second += points;
            }
            else cout << name << " is not in the casino" << endl;
        }
    }

    cout << "----------" << endl;
    for (auto it = casino.begin(); it != casino.end(); ++it) {
        cout << it->first << " is winning " << it->second << endl;
    }
}


