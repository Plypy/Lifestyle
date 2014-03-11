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
struct Matrix {
    double a[MAXN][MAXN];
    int n, m;
    void clear() {
        memset(a,0,sizeof(a));
    }
    Matrix operator*(const Matrix &b) const{
        Matrix ret;
        ret.clear();
        ret.n = n;
        ret.m = b.m;
        for (int i = 0; i < ret.n; ++i)
            for (int j = 0; j < ret.m; ++j) {
                for (int k = 0; k < m; ++k)
                    ret.a[i][j] += a[i][k]*b.a[k][j];
            }
        return ret;
    }
};
// 快速求解fx = a0fx-1+a1fx-2... a为系数矩阵an-1,an-2...，b为前n项f0,f1...fn-1
double solve(double a[], double b[], int n, int t) {
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
    if (t<n)
        return F.a[t][0];
    for (t -= n-1; t; t >>= 1) {
        if (t&1)
            E = M*E;
        M = M*M;
    }
    F = E*F;
    return F.a[n-1][0];
}

int n;
double p;
int pos[MAXN];
double coef[MAXN];
double fst[MAXN];

int main(int argc, char const *argv[]) {
    // cout << fixed << setprecision(7);
    while (EOF != scanf("%d%lf", &n, &p)) {
        fst[0] = 1;
        fst[1] = p;
        coef[0] = 1-p;
        coef[1] = p;
        pos[0] = 0;
        for (int i = 1; i <= n; ++i)
            scanf("%d", pos+i);
        sort(pos+1,pos+n+1);
        double ans = 1;
        for (int i = 1; i <= n; ++i) {
            ans *= 1-solve(coef,fst,2,pos[i]-pos[i-1]-1);
        }
        // cout << ans << endl;
        printf("%.7f\n", ans);
    }
    return 0;
}