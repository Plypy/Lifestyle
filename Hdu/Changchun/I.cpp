/**
 * Description:
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
const int MOD = 95041567;
const int MAXN = 55;
typedef long long ll;
int add(ll a, ll b, ll mod) {
    return (a+b)%mod;
}
int mult(ll a, ll b, ll mod) {
    return (a*b)%mod;
}
int p[5] = {31, 37, 41, 43, 47};
int coef[5][MAXN];
int bell[5][MAXN];
int comb[5][MAXN][MAXN];
void init() {
    for (int i = 0; i < 5; ++i) {
        coef[i][p[i]-1] = coef[i][p[i]-2] = 1;
    }
    for (int i = 0; i < 5; ++i)
        bell[i][0] = comb[i][0][0] = 1;
    for (int k = 0; k < 5; ++k)
        for (int i = 1; i < MAXN; ++i) {
            comb[k][i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                comb[k][i][j] = add(comb[k][i-1][j],comb[k][i-1][j-1],p[k]);
                // comb[k][i][j] = comb[k][i-1][j]+comb[k][i-1][j-1];
            }
        }
    for (int k = 0; k < 5; ++k)
        for (int i = 1; i < MAXN; ++i) {
            for (int j = 0; j < i; ++j) {
                bell[k][i] = add(bell[k][i],mult(comb[k][i-1][j],bell[k][j],p[k]),p[k]);
                // bell[k][i]  += comb[k][i-1][j]*bell[k][j];
            }
        }
}
void gcd(int a, int b, int &d, int &x, int &y) {
    if (0 == b) {
        d = a, x = 1, y = 0;
    } else {
        gcd(b,a%b,d,y,x);
        y -= x*(a/b);
    }
}
int crt(int a[], int m[], int n) {
    int M = MOD;
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        int x, y, t;
        int tm = M/m[i];
        gcd(tm,m[i],t,x,y);
        ret = (ret+tm*x*a[i])%M;
    }
    return (ret+M)%M;
}
const int MAXP = 55;
struct Matrix {
    int n, m;
    int a[MAXP][MAXP];
    int mod;
    void clear() {
        n = m = 0;
        memset(a,0,sizeof(a));
    }
    Matrix operator*(const Matrix &b) const {
        Matrix ret;
        ret.clear();
        ret.n = n, ret.m = b.m;
        ret.mod = mod;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < b.m; ++j)
                for (int k = 0; k < m; ++k) {
                    // cout << i << ' ' << j << ' ' << k << endl;
                    ret.a[i][j] = (ret.a[i][j]+a[i][k]*b.a[k][j])%mod;
                }
        return ret;
    }
};
int solve(int a[], int b[], int n, int t, int mod) {
    Matrix M, F, E;
    M.clear(), F.clear(), E.clear();
    M.mod = E.mod = F.mod = mod;
    M.n = M.m = n;
    E.n = E.m = n;
    F.n = n, F.m = 1;
    for (int i = 0; i < n-1; ++i)
        M.a[i][i+1] = 1;
    for (int i = 0; i < n; ++i) {
        M.a[n-1][i] = a[n-1-i];
        F.a[i][0] = b[i];
        E.a[i][i] = 1;
    }
    if (t < n)
        return (F.a[t][0]+mod)%mod;
    // cout << "fucking" << endl;
    // cout << "Before " << M.mod << endl;
    for (t -= n-1; t; t >>= 1) {
        // cout << t << endl;
        if (t&1) {
            // cout << E.mod << endl;
            E = M*E;
            // cout << "here" << endl;
        }
        // cout << M.mod << endl;
        M = M*M;
        // cout << "here" << endl;
    }
    F = E*F;
    return (F.a[n-1][0]+mod)%mod;
}
// int get(int n, int p) {

// }
int ans[5];
void test() {
    int n;
    // for (int k = 0; k < 5; ++k)
    // for (int i = 1; i < 10; ++i) {
    //     for (int j = 0; j <= i; ++j) {
    //         cout << comb[k][i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    while (cin >> n) {
        for (int i = 0; i < 5; ++i)
            cout << bell[i][n] << ' ' ;
        cout << endl;
    }
}
int main(int argc, char const *argv[]) {
    init();
    // test();
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < 5; ++i) {
            ans[i] = solve(coef[i],bell[i],p[i],n,p[i]);
            // cout << "i fuck" << endl;
            // cout << i << ' ' << ans[i] << endl;
        }
        // cout << "fucked" << endl;
        int tmp = crt(ans, p, 5);
        printf("%d\n", tmp);
    }
    return 0;
}