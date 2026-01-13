#include <iostream>  
using namespace std;
long long squareAndMultiply(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod; //首先对底数取模，防止中间结果过大  
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }//如果当前位是1，则乘以当前的base
        base = (base * base) % mod;//将base平方，并准备处理下一位
        exp >>= 1;//exp右移一位，相当于exp除以2，也可以写成exp /= 2;
    }
    return result;
}
int main() {
    long long a, n, m;
    cout << "Calculate a^n(mod m)..." << endl;
    cout << "Please input:" << endl;
    cout << " a=";
    cin >> a;
    cout << " n=";
    cin >> n;
    cout << " m=";
    cin >> m;
    cout << a << "^" << n << "(mod " << m << ")=" << squareAndMultiply(a, n, m) << endl;
}