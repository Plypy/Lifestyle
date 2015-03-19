/**
 * Notes: I've spent lots of time on this problem, as a result of lacking
 * a correct sense of the true math model behind the question, particularly
 * the matrix of array recurrsion.
 **/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cctype>
using namespace std;

const int MAXD = 100;
const int MOD = 1e9+7;

int mult(long long a, long long b)
{
    return (a*b)%MOD;
}

int add(long long a, long long b)
{
    long long ret = a+b;
    if (ret >= MOD) {
        ret -= MOD;
    }
    return ret;
}

int ct[MAXD+5];
int f[MAXD+5];

struct Mat {
    int ar[MAXD+5][MAXD+5];
    Mat() { memset(ar, 0, sizeof(ar)); }
    Mat operator*(const Mat &t) const {
        Mat ret;
        for (int i = 0; i <= MAXD; ++i) {
            for (int j = 0; j <= MAXD; ++j) {
                for (int k = 0; k <= MAXD; ++k) {
                    ret.ar[i][j] = add(ret.ar[i][j], mult(ar[i][k], t.ar[k][j]));
                }
            }
        }
        return ret;
    }
};

int calc(int x)
{
    Mat a, b;
    b.ar[0][0] = 1;
    b.ar[MAXD][0] = 1;
    for (int i = 0; i < MAXD; ++i) {
        a.ar[0][i] = ct[i+1];
    }
    a.ar[0][MAXD] = 1;
    for (int i = 1; i < MAXD; ++i) {
        a.ar[i][i-1] = 1;
    }
    a.ar[MAXD][MAXD] = 1;
    Mat c;
    for (int i = 0; i <= MAXD; ++i) {
        c.ar[i][i] = 1;
    }

    for (; x; x >>= 1) {
        if (x & 1) {
            c = c*a;
        }
        a = a*a;
    }
    a = c*b;
    return a.ar[0][0];
}

int main()
{
    int n, x;
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        ++ct[a];
    }

    // for (int i = 0; i < MAXD; ++i) {
    //     f[i] = 1;
    //     for (int j = 1; j <= i; ++j) {
    //         f[i] = add(f[i], mult(ct[j], f[i-j]));
    //     }
    // }
    // int ans = 0;
    // if (x <= MAXD) {
    //     ans = f[x];
    // } else {
    //     ans = calc(x);
    // }
    int ans = calc(x);
    printf("%d\n", ans);
}
