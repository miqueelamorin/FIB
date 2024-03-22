//Classification of characters
//Reads a letter and converts it to their opposite case

#include <iostream>
using namespace std; 

int main() {
    // read a character
    char letter;
    cin >> letter;
    // if letter is uppercase add the diff between 'a' and 'A'. Else subtract.
    if (letter >= 'A' and letter <= 'Z'){
        letter += ('a' - 'A');
    }
    else if (letter >= 'a' and letter <= 'z'){
        letter -= ('a' - 'A');
    }
    cout << letter << endl;
}
