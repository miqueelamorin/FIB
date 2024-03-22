#include <stack>
#include <iostream>

using namespace std;



int main (){
    int n;
    cin >> n;
    stack<int> Pila;
    
    int x;
    int meitat = n/2;
    bool palindrome = true;
    
    for (int i = 0; i < n and palindrome; ++i) {
        cin >> x;
        
        if (n % 2 == 0 or i != meitat) {
            if (i >= meitat) {
                if (x == Pila.top()) Pila.pop();
                else palindrome = false;
            }
            else Pila.push(x);
        }
    }
    
    if (palindrome) cout << "SI" << endl;
    else cout << "NO" << endl;
}
