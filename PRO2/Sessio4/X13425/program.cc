#include "CuaIOParInt.hh"
#include "ParInt.hh"
#include <queue>

using namespace std;

void assignar_cues(queue<ParInt>& original, queue<ParInt>& cua1, queue<ParInt>& cua2){
    int total1, total2;
    total1 = total2 = 0;

    while (not original.empty()){
        if (total1 <= total2) {
            cua1.push(original.front());
            total1 += original.front().segon();
        }

        else {
            cua2.push(original.front());
            total2 += original.front().segon();
        }

        original.pop();
    }
}


int main() {
    queue<ParInt> original;
    llegirCuaParInt(original);

    queue<ParInt> cua1;
    queue<ParInt> cua2;
    assignar_cues(original, cua1, cua2);

    escriureCuaParInt(cua1);
    cout << endl;
    escriureCuaParInt(cua2);
}
