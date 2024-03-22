//Value of the letters
//Reads a pharse and computes the value of each letter and sums it

#include <iostream>
using namespace std;

int value(char c)
{
    if (c == 'a' or c == 'e') return 1;
    else if (c == 'o' or c == 's') return 2;
    else if (c == 'd' or c == 'i' or c == 'n' or c == 'r') return 3;
    else if (c == 'c' or c == 'l' or c == 't' or c == 'u') return 4;
    else if (c == 'm' or c == 'p') return 5;
    else if (c == 'b' or c == 'f' or c == 'g' or c == 'h' or c == 'j') return 6;
    else if (c == 'q' or c == 'v' or c == 'x' or c == 'y' or c == 'z') return 6;
    else if (c == 'k' or c == 'w') return 7;
    else return 0;
}

int main ()
{
    //reads a serie of characters
    char letter;
    int sum = 0;
    while(cin >> letter)
    {
        //computes the value and sums it
        sum += value(letter);
    }
    cout << sum << endl;
}