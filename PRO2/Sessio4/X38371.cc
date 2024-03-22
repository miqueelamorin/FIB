#include <queue>
#include <iostream>

using namespace std;

void maxminpop (queue<int> Cua, int& max, int& min){
    Cua.pop();
    if (not Cua.empty()){
        int size = Cua.size();
        max = min = Cua.front();
        for (int i = 0; i < size; ++i){
            if (Cua.front() > max) max = Cua.front();
            else if (Cua.front() < min) min = Cua.front();
            Cua.pop();
        }
    }
}

void maxmin (int& min, int& max, int x){
    if (x > max) max = x;
    if (x < min) min = x;
}

int main (){  
    queue<int> Cua;
    int x;
    cin >> x;
    int max, min, total = 0;
    max = min = x;
    
    while (x <= 1000 and x >= -1001){
        if (x == -1001){
            if (not Cua.empty()){
                total -= Cua.front();
                if (min == Cua.front() or max == Cua.front()) maxminpop(Cua, max, min);
                Cua.pop();
                //if (not Cua.empty()) maxminpop(Cua, max, min);
            }
        }
        else {
            if (Cua.empty()) min = max = x;
            Cua.push(x);
            total += x;
            maxmin(min, max, x);
        }
        if (Cua.empty()) cout << '0' << endl;
        else cout << "min " << min << "; max " << max << "; media " << total/(double)Cua.size() << endl;
        cin >> x;
    }
}
