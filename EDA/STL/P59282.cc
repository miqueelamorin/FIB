#include <iostream>
#include <queue>
using namespace std;

int main() {
    cout.setf(ios::fixed);
	cout.precision(4);
    
    priority_queue<int, vector<int>, greater<int>> pq;

    string op;
    double sum = 0.0;
    int max = 0;
    int num;

    while (cin >> op){

        if (op == "number"){
            cin >> num;
            sum += num;
            if (pq.empty()) max = num;
            else if (max < num) max = num;
            pq.push(num);
        }

        else if (op == "delete" and not pq.empty()){
            sum -= pq.top();
            pq.pop();
        }
        
        if (pq.empty()) cout << "no elements" << endl;

        else {      
        cout << "minimum: " << pq.top();
        cout << ", maximum: " << max;
        cout << ", average: " << sum/pq.size() << endl;
        }

    }
}
