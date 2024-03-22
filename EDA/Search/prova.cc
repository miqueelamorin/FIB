#include <vector> 
#include <iostream> 
#include <string>

using namespace std; 


typedef vector<string> VS;
typedef vector<int> VB;

bool compatible(string a, char b, VS& vi){
	string t = a + b;
	string tp = b +a;
	bool test = true;
	for(int i = 0; i < vi.size(); ++i){
		//cerr << vi[i] << endl;
		if (vi[i] == t or vi[i] == tp) test = false;
	}
	return test;
}

void backtraking(VS &vs, VS &vi, int i, string r, VB& vb) {
	if (i == vs.size()) cout << r << endl;
	else{
		string x;
		if (i == 0){
			for (int j = 0; j < vs.size(); ++j ){
				if (not vb[j]){
					vb[j] = true;
					x = r + vs[j];
					backtraking(vs, vi, i+1, x, vb);
					vb[j] = false;
				}
			}
		}
		else{
			for (int j = 0; j < vs.size(); ++j){
				if (not vb[j] and compatible(vs[j], r[i-1], vi)){
					vb[j] = true;
					x = r + vs[j];
					backtraking(vs, vi, i+1, x, vb);
					vb[j] = false;
				}
			}
		}
	}
}

int main() {

	int x; 
	string s;
	cin >> x;

	VB vb(x);
	VS vs(x);

	for (int i = 0; i < x; ++i) {
		cin >> s;
		vs[i] = s;
	}

	cin >> x;

	VS vi(x);

	for (int i = 0; i < x; ++i) {
		cin >> s;
		vi[i] = s;
	}  


	backtraking(vs, vi,0, "", vb);

}