#include<iostream>
#include"Class of elliptic curve.h"
using namespace std;

int main() {
	bool whetherLoop = true;
	
	//1.给定参数p,a,b，判断E_p(a,b)是否为椭圆曲线
	cout << "1.给定参数p,a,b，判断E_p(a,b)是否为椭圆曲线" << endl;
	int p, a, b;
	while (whetherLoop) {
		cout << "请输入椭圆曲线E_p(a,b):y^2≡x^3+ax+b(mod p)的参数：" << endl;
		cout << "p=";
		cin >> p;
		cout << "a=";
		cin >> a;
		cout << "b=";
		cin >> b;
		EllipticCurve e(p, a, b);
		if (!e.isEllipticCurve()) {
			cout << "E_" << p << "(" << a << "," << b << ")" << "不是椭圆曲线，请重新输入！" << endl;
		}
		else {
			cout << "E_" << p << "(" << a << "," << b << ")" << "是椭圆曲线。" << endl;
			whetherLoop = false;
		}
	}
	EllipticCurve e(p, a, b);
	whetherLoop = true;
	
	//2.判断给定的点P,Q是否在椭圆曲线E_p(a,b)上
	cout << "2.判断给定的点P,Q是否在椭圆曲线E_p(a,b)上" << endl;
	Point P, Q;
	while (whetherLoop) {
		cout << "请输入点P的坐标：" << endl;
		cout << "横坐标x1=";
		cin >> P.x;
		cout << "纵坐标y1=";
		cin >> P.y;
		if (!e.isOnEC(P)) {
			cout << "点P(" << P.x << "," << P.y << ")" << "不在椭圆曲线" << "E_" << p << "(" << a << ", " << b << ")" << "上，请重新输入！" << endl;
		}
		else {
			cout << "点P(" << P.x << "," << P.y << ")" << "在椭圆曲线" << "E_" << p << "(" << a << ", " << b << ")" << "上。" << endl;
			whetherLoop = false;
		}
	}
	whetherLoop = true;
	while (whetherLoop) {
		cout << "请输入点Q的坐标：" << endl;
		cout << "横坐标x2=";
		cin >> Q.x;
		cout << "纵坐标y2=";
		cin >> Q.y;
		if (!e.isOnEC(P)) {
			cout << "点Q(" << Q.x << "," << Q.y << ")" << "不在椭圆曲线" << "E_" << p << "(" << a << ", " << b << ")" << "上，请重新输入！" << endl;
		}
		else {
			cout << "点Q(" << Q.x << "," << Q.y << ")" << "在椭圆曲线" << "E_" << p << "(" << a << ", " << b << ")" << "上。" << endl;
			whetherLoop = false;
		}
	}
	whetherLoop = true;

	//3.对在椭圆曲线E_p(a,b)上的两点P,Q，计算P+Q
	cout << "3.对在椭圆曲线E_p(a,b)上的两点P,Q，计算P+Q" << endl;
	cout << "P(" << P.x << "," << P.y << ")+Q(" << Q.x << "," << Q.y << ")=";
	if (e.addPoint(P, Q).isInfinity == true) {
		cout << "O" << endl;
	}
	else {
		cout << "(" << e.addPoint(P, Q).x << "," << e.addPoint(P, Q).y << ")" << endl;
	}

	//4.对在椭圆曲线E_p(a,b)上的点P，使用“倍加-和”算法计算mP
	cout << "4.对在椭圆曲线E_p(a,b)上的点P，使用“倍加-和”算法计算mP" << endl;
	int m = 0;
	cout << "请输入m的值：m=";
	cin >> m;
	cout << m << "P=";
	if (e.DoubleAndAdd(m, P).isInfinity == true) {
		cout << "O" << endl;
	}
	else {
		cout << "(" << e.DoubleAndAdd(m, P).x << "," << e.DoubleAndAdd(m, P).y << ")" << endl;
	}

	//5.对在椭圆曲线E_p(a,b)上的点P，计算阶ord(P)
	cout << "5.对在椭圆曲线E_p(a,b)上的点P，计算阶ord(P)" << endl;
	cout << "点P的阶ord(P)=" << e.ord(P) << endl;

	//6.对于椭圆曲线E_p(a,b)，计算阶#E
	cout << "6.对于椭圆曲线E_p(a,b)，计算阶#E" << endl;
	cout << "椭圆曲线" << "E_" << p << "(" << a << ", " << b << ")" << "的阶#E=" << e.ordOfEC() << endl;

	//7.对于椭圆曲线E_p(a,b)，计算所有点
	cout << "7.对于椭圆曲线E_p(a,b)，计算所有点" << endl;
	cout << "椭圆曲线" << "E_" << p << "(" << a << ", " << b << ")" << "上所有点为" << endl;
	e.printAllPoints();

	//8.其他功能的进一步扩展……

	system("pause");
}