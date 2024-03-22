#include <iostream>
#include <vector>
using namespace std;

bool is_peak(const vector<int>& v, int index){
    if (index == 0 and v[index] > v[index+1]) return true;
    if (index == v.size()-1 and v[index] > v[index-1]) return true;
    if (index > 0 and index < v.size()-1 and 
    v[index] > v[index+1] and v[index] > v[index-1]) return true;
    return false;
}

int buscar_pic(const vector<int>& v, int left, int right){
    if (v.size() == 2) return (v[left]>v[right] ? left : right);
    if (left+1>=right) return right;
    int m = (left+right)/2;

    if (is_peak(v,m)) return m;
    if (is_peak(v,m+1)) return m+1;
    if (is_peak(v,m-1)) return m-1;
    if (v[m] > v[m-1]) return buscar_pic(v,m+1,right);
    if (v[m] > v[m+1]) return buscar_pic(v,left,m-1);
    return 1;
}

bool cerca_dec(const vector<int>& v, int x, int left, int right){
    if (left > right) return false;
    int m = (left+right)/2;
    if (v[m] == x) return true;
    if (v[m] > x) return cerca_dec(v,x,m+1,right);
    else cerca_dec(v,x,left,m-1);
}
bool cerca_cre(const vector<int>& v, int x, int left, int right){
    if (left > right) return false;
    int m = (left+right)/2;
    if (v[m] == x) return true;
    if (v[m] < x) return cerca_cre(v,x,m+1,right);
    else cerca_cre(v,x,left,m-1);
}

bool search(int x, const vector<int>& v){
    int pic = buscar_pic(v,0,v.size()-1);
    return cerca_cre(v,x,0,pic) or cerca_dec(v,x,pic+1,v.size()-1);
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int m;
        cin >> m;
        while (m--) {
          int x;
          cin >> x;
          cout << ' ' << search(x, V);
        }
        cout << endl;
    }
}
