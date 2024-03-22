#include <iostream>
using namespace std;

double exp_rapida(double base, int exp){
	if (base == 1 or exp == 0) return 1;
	double y = exp_rapida(base,exp/2);
	if (exp%2 == 0) return y*y;
	else return y*y*base;
}

int trobar_limit(int min, int max, double bank_int, double money, double prof_int){
	if (min > max) return min;
	int dies = (min+max)/2;
	double bank = exp_rapida(bank_int, dies)*money;
	double prof = prof_int * dies + money;
	if (prof > bank) return trobar_limit(dies+1, max, bank_int, money, prof_int);
	if (prof < bank) return trobar_limit(min, dies-1, bank_int, money, prof_int);
	return dies;
}

int main(){
	double money, prof_int, bank_int;
	while(cin >> money >> prof_int >> bank_int){
		bank_int = bank_int/100 + 1;
		cout << trobar_limit(1, 10000000, bank_int, money, prof_int) << endl;
	}
}