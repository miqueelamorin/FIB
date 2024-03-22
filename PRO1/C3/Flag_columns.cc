#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> Row;
typedef vector<Row> Flag;

Flag read_flag(int n) {
    Flag f (n, Row(n));
    for(int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j) cin >> f[i][j];
    }
    return f;
}

int column_count(const Flag& f) {
    int size = f.size();
    int count = 0;
    int idiag = f.size() - 1;
    
    for(int j = 0; j < size; ++j) {
        int i = 0;
        bool cumple = true;
        int colorchange = 0;
        
        while (cumple and i < size - 1) {

            if (f[i][j] != f[i + 1][j]) {
                if (i+1 >= idiag) {
                    ++colorchange;
                    if (colorchange > 1) cumple = false;
                }
                else cumple = false;
            }
            ++i;
        }
        if (cumple and colorchange != 0) ++count; 
        --idiag;
    }
    return count;
}



int main() {
    int n;
    while (cin >> n) {
        Flag flag = read_flag(n);
        cout << column_count(flag) << endl;
    }
}