//Words between two words
//Print the number of words between the word “beginning” and the word “end”
#include <iostream>
using namespace std;

int main() {
    string word;
    bool beginning = false;
    int count = 0;
    while (cin >> word and word != "end") {
        //if word is beginning true add 1 to count
        if (beginning) ++count;
        else if (word == "beginning") beginning = true;
    }
    if (beginning and word == "end") cout << count << endl;
    else cout << "wrong sequence" << endl;
}
