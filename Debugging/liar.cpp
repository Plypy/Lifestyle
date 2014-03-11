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
const int MAXN = 15;
int g[MAXN][MAXN];
int plan[MAXN];
int cur[MAXN];
int n;

bool check(int dep) {
    for (int i = 1; i <= n; ++i)
        if (-1 != cur[i] && -1 != g[dep][i] && cur[i] != g[dep][i])
            return false;
    return true;
}
void dfs(int dep) {
    if (dep == n+1) {
        bool flag = true;
        for (int i = 1; i <= n; ++i) {
            if (0 == cur[i] && check(i))
                flag = false;
            if (1 == cur[i] && !check(i))
                flag = false;
        }
        if (flag) {
            for (int i = 1; i <= n; ++i)
                cout << cur[i] << ' ';
            cout << endl;
        }
        return ;
    }
    int buf[MAXN];
    memcpy(buf, cur, sizeof(buf));
    if (check(dep)) {
        for (int i = 1; i <= n; ++i) {
            if (-1 != g[dep][i])
                cur[i] = g[dep][i];
        }
        cur[dep] = 1;
        dfs(dep+1);
        memcpy(cur, buf, sizeof(buf));
    }

    cur[dep] = 0;
    dfs(dep+1);
    memcpy(cur,buf,sizeof(buf));
}

void init() {
    n = 3;
    memset(g,-1,sizeof(g));
    g[1][2] = false;
    g[2][3] = false;
    g[3][1] = g[3][2] = false;
    memset(cur,-1,sizeof(cur));
}
int main(int argc, char const *argv[]) {
    init();
    dfs(1);
    return 0;
}