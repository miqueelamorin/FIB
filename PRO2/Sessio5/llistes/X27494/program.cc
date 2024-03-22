#include <iostream>
#include <list>

using namespace std;

void add_list (list<int>& l, int number) {
    list<int>::iterator it = l.end();
    l.insert(it, number);
}

void erase_list (list<int>& l, int number, bool& found) {
    if (not l.empty()){
        list<int>::iterator it = l.begin();

        while (not found and it != l.end()){
            found = (*it == number); //if (*it == number) found = true
            ++it;
        }
        --it;
        if (found) l.erase(it);
    }
}

void minmaxavg (list<int>& l, int& min, int& max){
    //if (l.empty()) cout << 0 << endl;
    //else {
        list<int>::const_iterator it = l.begin();
        min = max = *it;
        while (it != l.end()) {
            if (max < *it) max = *it;
            else if (min > *it) min = *it;
            ++it;
        }

    //}
}


int main(){
    list <int> l;
    int code, number;
    cin >> code >> number;

    int min, max;
    min = max = number;
    double sum = 0.0;

    while (code != 0 and number != 0){
        if (code == -1) {
            add_list(l, number);
            sum += number;
            if (max < number) max = number;
            else if (min > number) min = number;
            cout << min << ' ' << max << ' ' << sum/l.size() << endl;
        }

        else if (code == -2) {
            bool found = false;
            erase_list(l, number, found);
            if (found){
                if (l.empty()) cout << 0 << endl;
                else {
                    sum -= number;
                    if (min == number or max == number) minmaxavg(l, min, max);
                    cout << min << ' ' << max << ' ' << sum/l.size() << endl;
                }
            }
        }


        cin >> code >> number;
    }
}
