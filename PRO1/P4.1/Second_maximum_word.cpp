//Second maximum word
//Print the second largest word in alphabetical order
#include <iostream>
using namespace std;

int main() {
    string word, max = "a", secmax = "a";
    while(cin >> word){
        //sec is the max and max is the new word
        if (word > max) secmax = max, max = word;
        //sec is the new word (inferior to sec)
        else if (word < max and word > secmax) secmax = word;
        //if word < secmax then nothing
    }
    cout << secmax << endl;
}
