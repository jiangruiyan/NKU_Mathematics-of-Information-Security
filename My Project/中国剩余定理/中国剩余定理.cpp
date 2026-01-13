#include <iostream>
using namespace std;
//扩展欧几里得算法求逆元
int modInverse(int a, int b) {
	int mod = b;
	int s = 0;
	int s0 = 1, s1 = 0;
	int m = 0;
	while (a % b != 0) {
		s = s0 - (a / b) * s1;
		s0 = s1;
		s1 = s;
		m = a % b;
		a = b;
		b = m;
	}
	while (s < 0) {
		s += mod;
	}
	return s;
}
//中国剩余定理求解同余方程组x≡b_i(mod m_i)
int ChineseRemainderTheorem(int n, int* pb, int* pm) {
	int m = 1;
	for (int i = 0; i < n; i++) {
		m *= pm[i];
	}
	int* M = new int[n];
	int* MM = new int[n];
	for (int i = 0; i < n; i++) {
		M[i] = m / pm[i];
	}
	for (int i = 0; i < n; i++) {
		MM[i] = modInverse(M[i], pm[i]);
	}
	int add = 0;
	for (int i = 0; i < n; i++) {
		add += M[i] * MM[i] * pb[i];
	}
	return add % m;
}
int main() {
	int n = 0;
	cout << "n=";
	cin >> n;
	int* pb = new int[n];
	int* pm = new int[n];
	for (int i = 0; i < n; i++) {
		cout << " b_" << i << "=";
		cin >> pb[i];
	}
	for (int i = 0; i < n; i++) {
		cout << " m_" << i << "=";
		cin >> pm[i];
	}
	int m = 1;
	for (int i = 0; i < n; i++) {
		m *= pm[i];
	}
	cout << "x≡" << ChineseRemainderTheorem(n, pb, pm) << "(mod " << m << ")" << endl;
	delete[]pb;
	delete[]pm;
}