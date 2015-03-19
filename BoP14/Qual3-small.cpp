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

const int MAXN = 105;
const int INF  = 0x7f7f7f7f;
int N, M;
int val[MAXN][MAXN];
int rused[MAXN], cused[MAXN];
int ans;
bool check() {
    for (int i = 0; i < N; ++i)
        if (0 == rused[i])
            return false;
    for (int i = 0; i < M; ++i)
        if (0 == cused[i])
            return false;
    return true;
}
void dfs(int dep, int tans) {
    if (tans > ans)
        return;
    if (dep == N*M) {
        if (check() && tans < ans)
            ans = tans;
        return ;
    }
    int r = dep/M, c = dep%M;

    ++rused[r], ++cused[c];
    dfs(dep+1,tans+val[r][c]);
    --rused[r], --cused[c];
    dfs(dep+1,tans);
}
void load() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            scanf("%d", &val[i][j]);
}
int work() {
    ans = INF;
    dfs(0,0);
    return ans;
}
int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        load();
        printf("Case %d: %d\n", i, work());
    }
    return 0;
}