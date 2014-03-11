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
const int MAXN = 5;
typedef long long ll;
const int MOD = 10000;
int add(ll a, ll b) {
    return (a+b)%MOD;
}
int mult(ll a, ll b) {
    return (a*b)%MOD;
}
struct Matrix {
    int a[MAXN][MAXN];
    int n, m;
    void clear() {
        memset(a,0,sizeof(a));
    }
    Matrix operator*(const Matrix &b) const {
        Matrix ret;
        ret.clear();
        ret.n = n, ret.m = b.m;
        for (int i = 0; i < ret.n; ++i)
            for (int j = 0; j < ret.m; ++j) {
                for (int k = 0; k < m; ++k)
                    ret.a[i][j] = add(ret.a[i][j],mult(a[i][k],b.a[k][j]));
            }
        return ret;
    }
};
int solve(int a[], int b[], int n, int t) {
    Matrix M, F, E;
    M.clear(), F.clear(), E.clear();
    M.n = M.m = E.n = E.m = n;
    F.n = n, F.m = 1;
    for (int i = 0; i < n-1; ++i)
        M.a[i][i+1] = 1;
    for (int i = 0; i < n; ++i) {
        M.a[n-1][i] = a[i];
        F.a[i][0] = b[i];
        E.a[i][i] = 1;
    }
    if (t < n)
        return F.a[t][0];
    for (t -= n-1; t; t >>= 1) {
        if (t&1)
            E = E*M;
        M = M*M;
    }
    F = E*F;
    return F.a[n-1][0];
}
int coef[MAXN] = {1,1};
int fst[MAXN] = {0,1};

int main(int argc, char const *argv[]) {
    while (true) {
        int n;
        scanf("%d", &n);
        if (-1 == n)
            break;
        printf("%d\n", solve(coef,fst,2,n));
    }
    return 0;
}