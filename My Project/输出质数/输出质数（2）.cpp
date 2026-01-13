#include<iostream>
#include<iomanip>
using namespace std;
int main() {
	const int n = 1000;//n为输出质数的上界
	int seive[n + 1];
	int count = 0;
	for (int i = 0; i < n; i++) {
		seive[i] = i + 1;
	}
	for (int j = 1; j < n; j++) {
		if (seive[j] != 0) {
			cout << setw(5)<<seive[j];
			count++;
			for (int k = 2; k <= (n+1) / (j + 1); k++) {
				seive[k * (j + 1) - 1] = 0;
			}
			if (count % 10 == 0) {
				cout << endl;
		   }
		}
	}
}