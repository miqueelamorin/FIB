//reads a natural number and prints the sum of their three last digits

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
  string text1;
  cin >> text1;
    int l= text1.length();
    if (l >= 3){
    string c1=text1.substr(l-1,1);
    string c2=text1.substr(l-2,1);
    string c3=text1.substr(l-3,1);
    
  cout << atoi(c1.c_str())+atoi(c2.c_str())+atoi(c3.c_str()) << endl;
  }
}
