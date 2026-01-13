#include<iostream>
using namespace std;

int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    else {
        return gcd(b, a % b);
    }
}
bool isOddPrime(int a) {
    if (a <= 2) {
        return false;
    }
    for (int i = 2; i < a; i++) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}

//模幂运算base^exp mod
long long squareAndMultiply(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

//计算Legendre符号(a/p)
int Legendre(int a, int p) {
    if (!isOddPrime(p)) {
        cout << "p不是奇素数" << endl;
        return -1000;
    }
    if (gcd(a, p) != 1) {
        cout << "a和p不互素" << endl;
        return -2000;
    }
    if (squareAndMultiply(a, (p - 1) / 2, p) % p == 1) {
        return 1;
    }
    if (squareAndMultiply(a, (p - 1) / 2, p) % p == p - 1) {
        return -1;
    }
    return -3000;
}

int main() {
    int a = 0;
    int p = 0;
    cout << "a=";
    cin >> a;
    cout << "p=";
    cin >> p;

    if (!isOddPrime(p)) {
        cout << "p不是奇素数。" << endl;
        return 0;
    }
    if (gcd(a, p) != 1) {
        cout << "a和p不互素！" << endl;
        return 0;
    }

    if (Legendre(a, p) == 1) {
        cout << "Legendre(" << a << "/" << p << ")=" << 1 << endl;
        cout << a << "是模" << p << "的二次剩余。" << endl;
    }
    else {
        if (Legendre(a, p) == -1) {
            cout << "Legendre(" << a << "/" << p << ")=" << -1 << endl;
            cout << a << "不是模" << p << "的二次剩余。" << endl;
        }
        else {
            cout << "(" << a << "/" << p << ")=" << Legendre(a, p)<<"ERROR" << endl;
        }
    }
}
