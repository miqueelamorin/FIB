#include <iostream>
using namespace std;

int suma_digits(int n) {
    int digit_sum = 0;
    while (n > 0) {
        digit_sum += n % 10;
        n /= 10;
    }
    return digit_sum;
}

int main() {
    int count = 0;
    int prev;
    cin >> prev;
    int n;
    while (cin >> n) {
        if (prev % suma_digits(n) == 0) ++count;
        prev = n;
    }
    cout << count << endl;
}