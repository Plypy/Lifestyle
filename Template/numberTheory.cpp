/**
 * Description: Template library for number theory
 * Source:
 * Author: Ply_py
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
using namespace std;


int extend_gcd(int a, int b, int &x, int &y) {
    if (0 == b) {
        x = 1, y = 0;
        return a;
    } else {
        int ret = extend_gcd(b,a%b,y,x);
        y -= x*(a/b);
        return ret;
    }
}
int inv(int x, int m) {
    int a = 0, b = 0;
    if (1 == extend_gcd(x, m, a, b))
        return a;
    return 0;
}
// Chinese reminder theorem
int crt(int a[], int m[], int n) {
    int M = 1;
    for (int i = 0; i < n; ++i)
        M *= m[i];
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        int e = M/m[i];
        int ne = inv(e,m[i]);
        ret = (ret+e*ne*a[i])%M;
    }
    return (ret+M)%M;
}
int phi(int n) {
    int m = (int) sqrt(n+0.5);
    int ans = n;
    for (int i = 2; i <= m; ++i)
        if (0 == n%i) {
            ans = ans/i *(i-1);
            while (0 == n%i)
                n /= i;
        }
    if (n > 1)
        ans = ans/n*(n-1);
    return ans;
}

const int MAXN = 1005;

int table[MAXN];
void phi_table(int n) {
    table[1] = 1;
    for (int i = 2; i <= n; ++i)
        if (!table[i]) {
            for (int j = i; j <= n; j += i) {
                if (!table[j])
                    table[j] = j;
                table[j] = table[j]/i*(i-1);
            }
        }
}

int notp[MAXN];

void sieve(int n) {
    int m = (int) sqrt(n+0.5);
    for (int i = 2; i <= m; ++i)
        if (!notp[i])
            for (int j = i*i; j <= n; j += i)
                notp[j] = true;
}

int ninv[MAXN];
int mod = 7;
void invOne2n() { // 求1到n的逆元
    ninv[1] = 1;
    for (int i = 2; i < MAXN; ++i)
        ninv[i] = mod/i*(mod-ninv[mod%i])%mod;
}
int main() {
    int a, b, c, n;
    while (cin >> a >> b >> c >> n) {
        a %= n;
        b %= n;
        c %= n;
        cout << (a*b/c)%n << endl;
    }
}