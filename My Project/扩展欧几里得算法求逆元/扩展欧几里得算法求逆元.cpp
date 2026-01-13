#include<iostream>
using namespace std;
//辗转相除法求最大公因数和最小公倍数
int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
//求逆元函数
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
int main() {
    int a, b;
    cout << "a=";
    cin >> a;
    cout << "b=";
    cin >> b;
    cout << "gcd(a,b)=" << gcd(a, b) << endl;
    cout << "lcm(a,b)=" << lcm(a, b) << endl;
    if (gcd(a, b) == 1) {
        cout << "a^(-1)=" << modInverse(a, b) << "(mod " << b << ")" << endl;
        cout << "b^(-1)=" << modInverse(b, a) << "(mod " << a << ")" << endl;
    }
    else {
        cout << "a,b不互素，无逆元" << endl;
    }
}