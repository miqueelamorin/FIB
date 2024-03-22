#include <stack>
#include <iostream>

using namespace std;

int main (){ 
    stack<char> Pila;
    
    char x;
    bool correcte = true;
    
    cin >> x;
    
    while (correcte and x != '.') {
        if (x == '(' or x == '[') Pila.push(x);        
        
        else if (Pila.empty() or (x == ')' and Pila.top() != '(') or (x == ']' and Pila.top() != '[')) correcte = false;
        
        else Pila.pop();
        
        cin >> x;
    }
    
    if (correcte and Pila.empty()) cout << "Correcte" << endl;
    else cout << "Incorrecte" << endl;
    
}
