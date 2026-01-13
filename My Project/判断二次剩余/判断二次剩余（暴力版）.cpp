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

//判断a≡b(mod m)是否成立
bool isMod(long long a, long long b, long long m) {
    return (a - b) % m == 0 ? true : false;
}

int main() {
    int a = 0;
    int m = 0;
    cout << "a=";
    cin >> a;
    cout << "m=";
    cin >> m;

    if (m <= 1) {
        cout << "不满足m>1。" << endl;
        return 0;
    }
    if (gcd(a, m) != 1) {
        cout << "a和m不互素！" << endl;
        return 0;
    }

    bool res = false;
    int count = 0;
    int* pSol = new int[m];
    for (int i = 0; i < m; i++) {
        if (isMod(i * i, a, m)) {
            res = true;
            pSol[count] = i;
            count++;
        }
    }

    if (res == true) {
        cout << a << "是模" << m << "的二次剩余。" << endl;
        cout << "同余方程x^2≡" << a << "(mod " << m << ")的解为x≡";
        for (int i = 0; i < count - 1; i++) {
            cout << pSol[i] << ",";
        }
        cout << pSol[count - 1];
        cout << "(mod " << m << ")。" << endl;
    }
    else {
        cout << a << "不是模" << m << "的二次剩余。" << endl;
    }
    delete[]pSol;
}
