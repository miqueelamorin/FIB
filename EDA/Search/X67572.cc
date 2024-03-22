#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

void conc_words(int n, vector<int>& visited, const vector<string>& paraules, 
                vector<string>& result){
    if (result.size() == n) {
        for (string u : result) cout << u;
        cout << endl;
    }
    else{
        for (int i = 0; i < n; ++i){
            if (not visited[i] and (result.size() == 0 or result.back().back() != paraules[i][0])){
                visited[i] = true;
                result.push_back(paraules[i]);
                conc_words(n,visited,paraules,result);
                visited[i] = false;
                result.pop_back();
            }
        }
    }

}

int main(){
    int n;
    cin >> n;
    vector <string> paraules(n);
    for (int i = 0; i < n; ++i) cin >> paraules[i];
    vector <int> visited(n,false);
    vector<string> result;
    conc_words(n,visited,paraules,result);
}