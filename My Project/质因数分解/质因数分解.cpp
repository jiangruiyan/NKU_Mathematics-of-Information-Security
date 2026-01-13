#include <iostream>
using namespace std;
void primeFactorization(int n) {
	if (n == 1) {
		cout << "1=1^1" << endl;
		return;
	}
	int factor[100]{}, exp[100]{};
	int count1 = 0, count2 = 0;
	int initial = n;
	for (int i = 2; i <= initial; i++) {
		if (n % i == 0) {
			if (count1 == 0) {
				factor[count2] = i;
				exp[count2]++;
			}
			else {
				if (i == factor[count2]) {
					exp[count2]++;
				}
				else {
					count2++;
					factor[count2] = i;
					exp[count2]++;
				}
			}
			count1++;
			n /= i;
			i = 1;//因为进入下一个循环要执行一遍i++，故要令i = 1
		}
	}
	cout << initial << "=";
	for (int i = 0; i < count2; i++) {
		cout << factor[i] << "^" << exp[i] << "*";
	}
	cout << factor[count2] << "^" << exp[count2] << endl;
}
int main() {
	cout << "Please input n(n>0):";
	int n;
	cin >> n;
	primeFactorization(n);
}