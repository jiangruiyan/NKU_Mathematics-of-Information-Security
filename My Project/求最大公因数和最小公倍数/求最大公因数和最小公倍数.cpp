#include <iostream>
using namespace std;
int gcd(int a, int b) {
	if (a % b == 0) {
		return b;
	}
	else {
		return gcd(b, a % b);
	}
}
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}
int main() {
	int a, b;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	cout << "gcd(a,b)=" << gcd(a, b) << endl;
	cout << "lcm(a,b)=" << lcm(a, b) << endl;
}