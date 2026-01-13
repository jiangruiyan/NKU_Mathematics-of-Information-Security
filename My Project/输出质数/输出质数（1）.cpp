#include<iostream>
#include<iomanip>
using namespace std;
int main() {
	int a = 0, count = 0;
	cout << "ÇëÊäÈëÉÏ½ç£º" << endl;
	cin >> a;
	const int max = a;
	for (int i = 2; i <= max; i++) {
		int judge = 1;
		for (int j = 2; j <= sqrt(i); j++) {
			if (i % j == 0) {
				judge = 0;
				break;
			}
		}
		if (judge) {
			count++;
			cout << setw(4) << i;
			if (count % 10 == 0) {
				cout << endl;
			}
		}
	}
	cout << endl;
	system("pause");
}