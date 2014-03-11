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


const int MAXN = 22;
const int MAXW = 105;

struct Point {
    int x, y;
    bool operator<(const Point &t) const {
        if (x != t.x)
            return x<t.x;
        return y<t.y;
    }
} pt[MAXN];
int ch[8000][5];
int cct;
bool check(int a, int b, int c, int d) {
    if (pt[b].x != pt[a].x)
        return false;
    if (pt[c].y != pt[a].y)
        return false;
    if (pt[d].x != pt[c].x)
        return false;
    if (pt[d].y != pt[b].y)
        return false;
    int len = pt[b].y-pt[a].y;
    if (len != pt[c].x-pt[a].x)
        return false;
    if (len != pt[d].y-pt[c].y)
        return false;
    if (len != pt[d].x-pt[b].x)
        return false;
    return true;
}
int n;
int dp[1<<MAXN];
void clear() {
    memset(dp,-1,sizeof(dp));
    cct = 0;
}
int dfs(int mask) {
    if (dp[mask] != -1)
        return dp[mask];
    int ret = 0;
    for (int i = 0; i < cct; ++i) {
        // cout << mask << ' ' << ch[i][4] << endl;
        if ((mask+ch[i][4]) == (mask|ch[i][4])) {
            // cout << ch[i][4] << endl;
            ret = max(ret,1+dfs(mask|ch[i][4]));
        }
    }
    return dp[mask] = ret;
}
void prep() {
    sort(pt,pt+n);
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            for (int k = j+1; k < n; ++k)
                for (int p = k+1; p < n; ++p)
                    if (check(i,j,k,p)) {
                        // cout << i << ' ' << j << ' ' << k << ' ' << p << endl;
                        ch[cct][0] = i;
                        ch[cct][1] = j;
                        ch[cct][2] = k;
                        ch[cct][3] = p;
                        ch[cct][4] = (1<<i)|(1<<j)|(1<<k)|(1<<p);
                        ++cct;
                    }
}
void work() {
    prep();
    int ans = dfs(0)*4;
    printf("%d\n", ans);
}
bool load() {
    clear();
    scanf("%d", &n);

    if (n == -1)
        return false;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &pt[i].x, &pt[i].y);
    }
    return true;
}
int main(int argc, char const *argv[]) {
    while (load()) {
        work();
    }
    return 0;
}