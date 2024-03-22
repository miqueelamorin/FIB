//Figures
//Reads a number and prints figures as +/* according to lenght
#include <iostream>
using namespace std;

int main() {
    //reads an integer positive
    int number;
    cin >> number;
    //save number value into s and column = first one
    int s = number, filas = 1;
    //go to next line, reduce 1 position and sum 1 to filas
    while (filas <= number){
        //start from position 1
        int left = 1;
        //write + and go one position ahead until = s
        while (left < s){
            cout << '+'; 
            ++left;
        }
        //when the positions are the same write /
        cout << '/';
        //write * and go one position ahead until = number entered
        while (left < number){
            cout << '*';
            ++left;
        }
        cout << endl;
        --s;
        ++filas;
    }
}
