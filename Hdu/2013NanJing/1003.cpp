/**
 * Description:
 * ProblemName: Campus Design
 * Source: 2013 Nanjing onsite
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
#define CLR(f, v) memset(f, v, sizeof(f))
const int MAXN = 105;
const int MAXM = 15;
const int MAXD = 25;
int N, M, C, D;
typedef long long ll;

const int MOD = 1000000000+7;
void addm(int &a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
}
bool flower[MAXN][MAXM];
int dp[2][1<<11][25];
int now, nxt;
int MASK, ALL;
void update(int s, int k, int ns, int nk) {
    if (ns & (MASK)) {
        addm(dp[nxt][ns^(MASK)][nk], dp[now][s][k]);
    }
}
int main(int argc, char const *argv[]) {
    while (EOF != scanf("%d%d%d%d", &N, &M, &C, &D)) {
        CLR(flower,0);
        CLR(dp,0);
        char buf[MAXM];

        for (int i = 0; i < N; ++i) {
            scanf("%s", buf);
            for (int j = 0; j < M; ++j) {
                if ('0' == buf[j])
                    flower[i][j] = true;
            }
        }
        now = 0;
        MASK = 1<<M;
        ALL = MASK-1;
        dp[now][ALL][0] = 1;
        for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
            nxt = now^1;
            if (flower[i][j]) {
                for (int s = 0; s <= ALL; ++s) for (int k = 0; k <= D; ++k) {
                    if (dp[now][s][k]) update(s, k, (s<<1)^1, k);
                }
            } else {
                for (int s = 0; s <= ALL; ++s) for (int k = 0; k <= D; ++k) {
                    if (dp[now][s][k]) {
                        update(s, k, (s<<1), k);
                        update(s, k, (s<<1)^1, k+1);
                        if (i && !(s&(MASK>>1))) update(s, k, (s<<1)^(MASK)^1, k);
                        if (j && !(s&1)) update(s, k, (s<<1)^3, k);
                    }
                }
            }
            CLR(dp[now], 0);
            now ^= 1;
        }
        int ans = 0;
        for (int i = C; i <= D; ++i)
            addm(ans,dp[now][ALL][i]);
        printf("%d\n", ans);
    }
    return 0;
}
