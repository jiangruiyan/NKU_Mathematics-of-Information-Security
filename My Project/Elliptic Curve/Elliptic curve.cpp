#include<iostream>
#include"Class of elliptic curve.h"
using namespace std;

bool isPrime3(int a) {
	if (a <= 3) {
		return false;
	}
	bool judge = true;
	for (int i = 2; i * i <= a; i++) {
		if (a % i == 0) {
			judge = false;
			break;
		}
	}
	return judge;
}
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

bool EllipticCurve::isEllipticCurve() {
	//p为大于3的质数并且4a^3+27b^2不被p整除即为椭圆曲线
	return isPrime3(p) && (4 * a * a * a + 27 * b * b) % p != 0;
}
bool EllipticCurve::isOnEC(Point P) {
	return (P.isInfinity == true) || ((P.y * P.y - P.x * P.x * P.x - a * P.x - b) % p == 0);
}
Point EllipticCurve::addPoint(Point P, Point Q) {
	if (P.isInfinity == true) {
		return Q;
	}//O + Q = Q
	if (Q.isInfinity == true) {
		return P;
	}//P + O = P
	Point R;
	int k;
	if (P.x == Q.x) {
		if ((P.y + Q.y) % p == 0) {
			R.isInfinity = true;
			return R;
		}//P + Q = O
		k = ((3 * P.x * P.x + a) * modInverse(2 * P.y, p)) % p;
	}
	else {
		k = ((Q.y - P.y) * modInverse(Q.x - P.x, p)) % p;
	}
	R.x = (k * k - P.x - Q.x) % p;
	while (R.x < 0) {
		R.x += p;
	}
	R.y = (k * (P.x - R.x) - P.y) % p;
	while (R.y < 0) {
		R.y += p;
	}
	R.isInfinity = false;
	return R;
}
Point EllipticCurve::DoubleAndAdd(int m, Point P) {
	Point mP;
	mP.isInfinity = true;
	while (m > 0) {
		if (m % 2 == 1) {
			mP = addPoint(mP, P);
		}
		P = addPoint(P, P);
		m /= 2;
	}
	return mP;
}
int EllipticCurve::ord(Point P) {
	int ord = 0;
	for (int i = 1; i <= ordOfEC(); i++) {
		if (DoubleAndAdd(i, P).isInfinity) {
			ord = i;
			break;
		}
	}
	return ord;
}
int EllipticCurve::ordOfEC() {
	int ord = 1;//初始化为1，因为要算上无穷远点O
	for (int x = 0; x < p; x++) {
		for (int y = 0; y < p; y++) {
			if ((y * y - x * x * x - a * x - b) % p == 0) {
				ord++;
			}
		}
	}
	return ord;
}
void EllipticCurve::printAllPoints() {
	int count = 0;
	for (int x = 0; x < p; x++) {
		for (int y = 0; y < p; y++) {
			if ((y * y - x * x * x - a * x - b) % p == 0) {
				count++;
				cout << "(" << x << "," << y << ")" << ",";
				if (count % 4 == 0) {
					cout << endl;
				}
			}
		}
	}
	cout << "O" << endl;
}