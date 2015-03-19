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
#include <bitset>
#include <stack>
using namespace std;

typedef long long ll;

const int MAXN = 505;

int N, M, MOD;

void add(ll &a, ll b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

ll mult(ll a, ll b) {
    return (a*b)%MOD;
}

ll f[MAXN][MAXN];// column with 1 (1), 2 (1) respectively
char dat[MAXN][MAXN];
int cnt[MAXN];

ll C(ll x) {
    return x*(x-1)/2;
}

ll dfs(int n1, int n2) {
    if (-1 != f[n1][n2]) {
        return f[n1][n2];
    }
    ll ret = 0;

    // 2 more n1
    if (n1 >= 2) {
        ll tmp = C(n1);
        tmp = mult(tmp, dfs(n1-2, n2));
        add(ret, tmp);
    }

    // 1 more n1, 1 more n2
    if (n2 >= 1 && n1 >= 1) {
        ll tmp = mult(n2, n1);
        tmp = mult(tmp, dfs(n1, n2-1));
        add(ret, tmp);
    }

    // 2 more n2
    if (n2 >= 2) {
        ll tmp = C(n2);
        tmp = mult(tmp, dfs(n1+2, n2-2));
        add(ret, tmp);
    }

    return f[n1][n2] = ret;
}

int main(int argc, char const *argv[]) {
    cin >> N >> M >> MOD;
    for (int i = 0; i < M; ++i) {
        cin >> dat[i];
        for (int j = 0; j < N; ++j) {
            if ('1' == dat[i][j]) {
                ++cnt[j];
            }
        }
    }
    int n1 = 0, n2 = 0;
    for (int j = 0; j < N; ++j) {
        if (1 == cnt[j]) {
            ++n1;
        } else if (2 == cnt[j]) {
            ++n2;
        }
    }
    memset(f, -1, sizeof(f));
    f[0][0] = 1;
    ll ans = dfs(n1, N-n1-n2);
    cout << ans << endl;
    return 0;
}
