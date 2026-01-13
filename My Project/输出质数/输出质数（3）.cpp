#include <iostream>
using namespace std;
void sieveOfEratosthenes(int a) {
	int* sieve = new int[a - 1];
	for (int i = 0; i < a - 1; i++) {
		sieve[i] = i + 2;
	}
	int i = 0;
	while (i < a - 1) {
		if (sieve[i] != 0) {
			cout << sieve[i] << " ";
			if (i + 2 <= sqrt(a)) {
				for (int j = i + 1; j < a - 1; j++) {
					if (sieve[j] % sieve[i] == 0) {
						sieve[j] = 0;
					}
				}
			}
		}
		i++;
	}
	cout << endl;
	delete[]sieve;
}
int main() {
	int x = 0;
	cout << "ÇëÊäÈëÉÏ½ç£º" << endl;
	cin >> x;
	sieveOfEratosthenes(x);
}