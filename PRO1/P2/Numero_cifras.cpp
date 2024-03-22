//Número de cifras
//Reads a numer and counts how many digits to represent in different bases
#include <iostream>
using namespace std;

int main() {
    //reads a number
	int n;
	cin >> n;
    //for base from 2 to 16
	for (int base = 2; base <= 16; ++base) {
		int y = 0;
		int x = n;
		while (x != 0) {
			x = x / base;
			++y;
		}
		cout << "Base " << base << ": " << y << " cifras." << endl;
	}
}
