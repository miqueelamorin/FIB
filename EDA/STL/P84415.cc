#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> bossa;
    string op;

    while (cin >> op){

        if (op == "maximum?"){
            if (bossa.empty()) cout << "indefinite maximum" << endl;
            else {
                auto it = bossa.end();
                --it;
                cout << "maximum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
        }

        else if (op == "minimum?"){
            if (bossa.empty()) cout << "indefinite minimum" << endl;
            else {
                auto it = bossa.begin();
                cout << "minimum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
        }

        else if (op == "store"){
            string valor;
            cin >> valor;
            if (bossa.find(valor) == bossa.end()) bossa[valor] = 1;
            else ++bossa[valor];
        }

        else if (op == "delete"){
            string valor;
            cin >> valor;
            auto it = bossa.find(valor);
            if (it != bossa.end()) {
                if (bossa.find(valor)->second > 1) --bossa[valor];
                else bossa.erase(valor);
            }
        }


    }
}