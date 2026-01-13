#include<iostream>
#include<string>
using namespace std;
//十进制转二进制
string DecTransToBin(int a) {
	string str;
	if (a == 0) {
		return "0";
	}
	int i = 0;
	while (a != 0) {
		str = to_string(a % 2) + str;
		a /= 2;
		i++;
	}
	return str;
}
//同余运算
long long congruence(long long a, int m) {
	if (a >= 0) {
		return (long long)a - m * (a / m);
	}
	else {
		return (long long)a - m * (a / m - 1);
	}
}
//乘方运算a^b
long long power(long long a, int b) {
	long long res = 1;
	for (int i = 0; i < b; i++) {
		res *= a;
	}
	return res;
}
//平方-乘算法函数
long long sqrt_mul(int a, int n, int m) {
	string bin = DecTransToBin(n);//将n转化为二进制存储
	long long res = 1;//结果初始化为1
	for (int i = 0; i < bin.length(); i++) {
		res = congruence(power(res, 2) * power(a, bin[i] - '0'), m);
		//平方-乘算法核心公式，不能忘了减去0的ASCII码
	}
	return res;
}
int main() {
	cout << "Calculate a^n(mod m)..." << endl;
	cout << "Please input:" << endl;
	int a, m, n;
	cout << " a=";
	cin >> a;
	cout << " n=";
	cin >> n;
	cout << " m=";
	cin >> m;
	cout << a << "^" << n << "(mod " << m << ")=" << sqrt_mul(a, n, m) << endl;
}