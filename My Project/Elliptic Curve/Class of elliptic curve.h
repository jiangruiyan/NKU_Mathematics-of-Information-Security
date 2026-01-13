//点类
class Point {
public:
	int x;
	int y;
	bool isInfinity = false;
};

//椭圆曲线类
class EllipticCurve {
public:
	//椭圆曲线E_p(a,b):y^2≡x^3+ax+b(mod p)
	int p;
	int a;
	int b;
	EllipticCurve(int p, int a, int b) {
		this->p = p;
		this->a = a;
		this->b = b;
	}

	//判断是否为椭圆曲线
	bool isEllipticCurve();
	//判断给定的点是否在椭圆曲线上
	bool isOnEC(Point P);
	//计算P+Q
	Point addPoint(Point P, Point Q);
	//使用“倍加-和”算法计算mP（其中m <= ord(P)）
	Point DoubleAndAdd(int m, Point P);
	//计算点P的阶ord(P)
	int ord(Point P);
	//计算椭圆曲线的阶#E
	int ordOfEC();
	//输出椭圆曲线上的所有点
	void printAllPoints();
};

//其他函数
//判断是否为大于3的质数
bool isPrime3(int a);
//求逆元a^(-1)(mod b)
int modInverse(int a, int b);