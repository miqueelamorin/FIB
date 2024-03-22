//Classification of characters
//Reads a letter, tells if it's uppercase or lowercase and if it's vowel or consonant

#include <iostream>
using namespace std; 

int main() {
    // read a character
    char letter;
    cin >> letter;
    //check if it's uppercase or lowercase
    if (letter >='a' and letter <='z'){
        cout << "lowercase" << endl;
    }
    else{
        cout << "uppercase" << endl;
        // convert it to lowercase
        letter = letter - 'A' + 'a';
    }
    // check if it's vowel or consonant
    if (letter == 'a' or letter == 'e' or letter == 'i' or letter == 'o' or letter == 'u'){
        cout << "vowel" << endl;
    }
    else cout << "consonant" << endl;
}
