/**
 * Description:
 * ProblemName:
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
#include <vector>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
using namespace std;

const int MAXN = 15;
typedef long long ll;

int mult(ll a, ll b, int m) {
    ll ret = (a*b);
    if (ret >= m) {
        ret %= m;
    }
    return ret;
}

int add(ll a, ll b, int m) {
    ll ret = (a+b);
    if (ret >= m) {
        ret %= m;
    }
    return ret;
}

struct ModInt {
    const static int MOD = 10000007;
    int val;
    ModInt(int a = 0): val(a) {}
    ModInt operator*(const ModInt &t) const {
        return ModInt(mult(t.val, val, MOD));
    }
    ModInt operator+(const ModInt &t) const {
        return ModInt(add(t.val, val, MOD));
    }
    ModInt &operator+=(const ModInt &t) {
        (*this) = (*this)+t;
        return (*this);
    }
    ModInt &operator*=(const ModInt &t) {
        (*this) = (*this)*t;
        return (*this);
    }
};

struct Matrix {
    int n, m;
    ModInt mat[MAXN][MAXN];
    void clear() {
        n = m = 0;
        memset(mat, 0, sizeof(mat));
    }
    void show() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                printf("%d ", mat[i][j].val);
            }
            puts("");
        }
    }
    Matrix operator*(const Matrix &t) const {
        Matrix ret;
        ret.clear();
        ret.n = n;
        ret.m = t.m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < t.m; ++j) {
                for (int k = 0; k < m; ++k) {
                    ret.mat[i][j] += mat[i][k]*t.mat[k][j];
                }
            }
        }
        return ret;
    }
};

Matrix power(const Matrix &t, int p) {
    Matrix base = t;
    Matrix ret;
    ret.clear();
    ret.n = ret.m = t.n;
    for (int i = 0; i < ret.n; ++i) {
        ret.mat[i][i] = 1;
    }
    for (; p; p>>=1) {
        if (p&1) {
            ret = ret*base;
        }
        base = base*base;
    }
    return ret;
}

int ar[MAXN];
Matrix M;
int n, m;
void init() {
    M.clear();
}
void build() {
    ar[0] = 3;
    ar[1] = 23;
    M.n = M.m = n+2;
    for (int i = 0; i <= M.n; ++i) {
        for (int j = 0; j <= i; ++j) {
            M.mat[i][j] = 1;
        }
        if (i > 0) {
            M.mat[i][1] = 10;
        }
    }
}
int solve(int m) {
    M =power(M, m);
    ModInt ret = 0;
    for (int i = 0; i < n+2; ++i) {
        ret += M.mat[n+1][i]*ar[i];
    }
    return ret.val;
}

void test() {
    ModInt a = 2, b = 7;
    cout << (a*b).val << endl;
    cout << (a+b).val << endl;
    a += b;
    cout << a.val << endl;
    Matrix mat;
    mat.n = mat.m = 3;
    for (int i = 0; i < mat.n; ++i) {
        mat.mat[i][i] = 1;
    }
    mat.show();
    (mat*mat).show();
}

int main() {
    // test();
    while (EOF != scanf("%d%d", &n, &m)) {
        init();
        for (int i = 1; i <= n; ++i) {
            scanf("%d", ar+i+1);
        }
        build();
        printf("%d\n", solve(m));
    }
}

