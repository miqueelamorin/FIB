//reads two words and tells their lexicographic order

#include <iostream>
using namespace std;

int main() {
    string word1, word2;
	cin >> word1 >> word2;
	if (word1 > word2){
		cout << word1 << " > " << word2 << endl;
	}
	else if (word1 == word2) {
		cout << word1 << " = " << word2 << endl;
	}
	else {
		cout << word1 << " < " << word2 << endl;
	}

}
