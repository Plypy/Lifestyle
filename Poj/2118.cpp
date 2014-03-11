/**
 * Description: Using matrix multipication to solve a recurrence function.
 * Source: POJ 2118
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

const int MOD  = 10000;
const int MAXK = 105;

int mult(int a, int b) {
    return (a*b)%MOD;
}
int add(int a, int b) {
    return (a+b)%MOD;
}

struct Square {
    int mat[MAXK][MAXK];
    int n;
    Square() {
        n = 0;
        memset(mat,0,sizeof(mat));
    }
};

Square mult(Square &a, Square &b) {
    Square ret;
    ret.n = a.n;
    for (int i = 0; i < a.n; ++i)
        for (int j = 0; j < a.n; ++j)
            for (int k = 0; k < a.n; ++k)
                ret.mat[i][j] = add(ret.mat[i][j],mult(a.mat[i][k],b.mat[k][j]));
    return ret;
}
Square pow(Square &a, int n) {
    if (n == 1) return a;
    Square ret = pow(a,n/2);
    ret = mult(ret,ret);
    if (n&1)    ret = mult(ret,a);
    return ret;
}

int b[MAXK], a[MAXK];
int main() {
    int n;
    while (true) {
        scanf("%d", &n);
        if (0 == n)
            break;
        for (int i = 0; i < n; ++i)
            scanf("%d", a+i);
        for (int i = 0; i < n; ++i)
            scanf("%d", b+i);
        int k;
        scanf("%d", &k);
        int ans = 0;
        if (k < n) {
            ans = a[k];
        } else {
            k -= n-1;
            Square sa;
            sa.n = n;
            for (int i = 0; i < n; ++i)
                sa.mat[0][i] = b[i];
            for (int i = 1; i < n; ++i)
                sa.mat[i][i-1] = 1;
            sa = pow(sa,k);
            for (int i = 0; i < n; ++i)
                ans = add(ans,mult(sa.mat[0][i],a[n-i-1]));
        }
        printf("%d\n", ans);
    }
}