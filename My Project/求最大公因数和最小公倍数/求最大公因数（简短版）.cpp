#include<iostream>
using namespace std;
int gcd(int a, int b) {
	while (b ^= a ^= b ^= a %= b);
	return a;
}
int main() {
	cout << "请输入a和b：" << endl;
	int a, b;
	cin >> a;
	cin >> b;
	cout << "(" << a << "," << b << ")" << "=" << gcd(a, b) << endl;
}