#include <stack>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

void escriure_pila(stack<string> pila){
    while(not pila.empty()){
        cout << pila.top() << endl;
        pila.pop();
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector <stack<string>> biblio(n);

    int x;
    cin >> x;

    int cat;
    while (x != -4){
        if (x == -1){
            string nom;
            cin >> nom >> cat;
            biblio[cat-1].push(nom);
        }

        else if (x == -2){
            int num;
            cin >> num >> cat;
            for (int i = 0; i < num; ++i) biblio[cat-1].pop();
        }

        else if (x == -3){
            cin >> cat;
            cout << "Pila de la categoria " << cat << endl;
            escriure_pila(biblio[cat-1]);
        }

        cin >> x;
    }
}
