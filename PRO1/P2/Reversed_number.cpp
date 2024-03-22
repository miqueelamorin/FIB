//reads a number and prints it reversed

#include <iostream>
using namespace std;

int main() {
  string n;
  cin >> n;
  int position = n.size()-1;
  while (position >= 0){
    cout << n[position];
    --position;
  }
  cout << endl;
}