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
using namespace std;

const int MAXN = 1005;
const int MAXM = 2105;

const int MOD = 1000000007;
typedef long long ll;

void addon(int &a, ll b) {
    ll t = (a+b)%MOD;
    a = t;
}

int f[MAXN][MAXM];
int n, m;
void dfs(int r, int s, int dep, int ns) {
    if (dep == m) {
        addon(f[r+1][ns], f[r][s]);
        return;
    }
    dfs(r,s,dep+1,ns);

    int cube = 3<<dep;
    if ((dep+2)<=m && (cube+ns) == (cube|ns)) {
        dfs(r,s,dep+1,ns|cube);
    }
}

void push(int r, int s) {
    int ns = 0;
    for (int p = 1<<(m-1); p; p>>=1) {
        if (s&p) {
            continue;
        }
        ns |= p;
    }
    dfs(r,s,0,ns);
}

int solve() {
    int ms = (1<<m)-1;

    f[0][ms] = 1;
    push(0, ms);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= ms; ++j) {
            if (!f[i][j]) {
                continue;
            }
            push(i,j);
        }
    }
    return f[n][ms];
}

int main() {
    cin >> n >> m;
    cout << solve() << endl;
}
