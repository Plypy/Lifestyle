/**
 * Description:
 * ProblemName: Tiling Dominoes
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

#define CLR(a, v) memset(a,v,sizeof(a));

typedef long long ll;
ll dp[2][1<<10];

int n, m;
int ALL;
int now, nxt;

void update(int b, int a) {
    if (b & (1<<m))
        dp[nxt][b^(1<<m)] += dp[now][a];
}
int main(int argc, char const *argv[]) {
    while (scanf("%d%d", &n, &m) != EOF) {
        if (n < m) swap(n,m);
        CLR(dp, 0);
        ALL = (1<<m)-1;
        dp[0][ALL] = 1;
        now = 0;
        for (int i = 0; i < n; ++i) // row
            for (int j = 0; j < m; ++j) { // column
                nxt = now^1;
                for (int r = 0; r <= ALL; ++r) { // r stands for the state of last m square 0 for not, 1 for placed
                    if (dp[now][r]) {
                        update(r<<1,r); // no placing
                        if (i && !(r & (1 << (m-1))))
                            update((r<<1)^(1<<m)^1,r); // place it vertically
                        if (j && !(r & 1))
                            update((r<<1)^3,r); // horizontally
                    }
                }
                CLR(dp[now], 0);
                now ^= 1;
            }
        printf("%lld\n", dp[now][ALL]);
    }
    return 0;
}