#include<iostream>
#include<iomanip>
using namespace std;

//求最大公因数
int gcd(int a, int b) {
	if (a % b == 0) {
		return b;
	}
	else {
		return gcd(b, a % b);
	}
}

//求欧拉函数值
int Euler(int m) {
	int count = 0;
	for (int i = 0; i < m; i++) {
		if (gcd(i, m) == 1) {
			count++;
		}
	}
	return count;
}

//求素因子，将结果储存在数组中，rec指向数组首地址，并返回素因子个数
int primeFactorization(int n, int*& rec) {
	rec = new int[100];
	if (n == 1) {
		rec[0] = 1;
		return 1;
	}
	int count1 = 0, count2 = 0;
	int initial = n;
	for (int i = 2; i <= initial; i++) {
		if (n % i == 0) {
			if (count1 == 0) {
				rec[count2] = i;
			}
			else {
				if (i == rec[count2]) {
				}
				else {
					count2++;
					rec[count2] = i;
				}
			}
			count1++;
			n /= i;
			i = 1;
		}
	}
	return count2 + 1;
}

//平方-乘算法进行模幂运算
long long squareAndMultiply(long long base, long long exp, long long mod) {
	long long result = 1;
	base = base % mod;
	while (exp > 0) {
		if (exp % 2 == 1) {
			result = (result * base) % mod;
		}
		base = (base * base) % mod;
		exp /= 2;
	}
	return result;
}

//求最小原根
int minPrimitiveRoot(int n) {
	int* primeFactor = nullptr;
	int countPrimeFactor = primeFactorization(Euler(n), primeFactor);//φ(n)素因子个数
	bool isMinPrimitiveRoot = true;
	for (int i = 2; i < n; i++) {
		if (gcd(i, n) == 1) {
			isMinPrimitiveRoot = true;
			for (int j = 0; j < countPrimeFactor; j++) {
				if (squareAndMultiply(i, Euler(n) / primeFactor[j], n) == 1) {
					isMinPrimitiveRoot = false;
				}
			}
			if (isMinPrimitiveRoot == true) {
				return i;
			}
		}
	}
	return -1;
}

int main() {
	int n = 0, g = 0;
	cout << "Please input n(n>0):";
	cin >> n;
	g = minPrimitiveRoot(n);
	cout << "The min primitive root of " << n << ":g=" << g << endl;
	cout << "The ind_table of " << n << " based on g=" << g << " is:" << endl;

	//以下给表格开辟空间并初始化
	int** table = new int* [(n - 1) / 10 + 1];
	for (int i = 0; i <= (n - 1) / 10; i++) {
		table[i] = new int[10];
	}
	for (int i = 0; i <= (n - 1) / 10; i++) {
		for (int j = 0; j < 10; j++) {
			table[i][j] = -1;
		}
	}

	//以下给表格赋值
	int mod = 0;
	for (int i = 0; i < Euler(n); i++) {
		mod = squareAndMultiply(g, i, n);
		table[mod / 10][mod % 10] = i;
	}

	//以下输出表格
	cout << setw(5) << " ";
	for (int i = 0; i < 10; i++) {
		cout << setw(5) << i;
	}
	cout << endl;
	for (int i = 0; i <= (n - 1) / 10; i++) {
		cout << setw(5) << i;
		for (int j = 0; j < 10; j++) {
			if (10 * i + j > 0 && 10 * i + j < n && gcd(10 * i + j, n) == 1) {
				cout << setw(5) << table[i][j];
			}
			else {
				cout << setw(5) << "-";
			}
		}
		cout << endl;
	}

	//以下释放表格空间
	for (int i = 0; i <= (n - 1) / 10; i++) {
		delete[]table[i];
	}
	delete[]table;
}