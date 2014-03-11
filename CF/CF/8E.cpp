
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int MAXN = 55;
long long n, k;
long long f[MAXN][2][2];
int a[MAXN];

long long dp(int l, int r, bool x, bool y) {
    if (l > r)
        return 1;
    if (-1 != f[r-l][x][y])
        return f[r-l][x][y];
    long long ret = 0;
    for (int i = 0; i < 2; ++i) {
        if (-1 != a[l] && a[l] != i)
            continue;
        for (int j = 0; j < 2; ++j) {
            if (-1 != a[r] && a[r] != j)
                continue;
            if (l == r && i != j)
                continue;
            if (x == false && i > j)
                continue;
            if (y == false && i > 1-j)
                continue;
            int a = x, b = y;
            if (a == false && i < j)
                a = true;
            if (b == false && i < 1-j)
                b = true;
            ret += dp(l+1,r-1,a,b);
        }
    }
    return f[r-l][x][y] = ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    ++k;
    memset(f,-1,sizeof(f));
    memset(a,-1,sizeof(a));

    a[0] = 0;
    long long tmp = dp(0,n-1,0,0);
    if (tmp < k) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 1; i < n; ++i) {
        memset(f,-1,sizeof(f));
        a[i] = 0;
        tmp = dp(0,n-1,0,0);
        if (tmp < k) {
            a[i] = 1;
            k -= tmp;
        }
    }
    for (int i = 0; i < n; ++i)
        cout << a[i];
    cout << endl;
    return 0;
}
