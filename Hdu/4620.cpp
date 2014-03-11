/**
 * Description: Simple search problem with a easy optimal prunning
 * Source: hdu 4620
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

const int MAXN = 35;
const int MAXM = 205;
const int MAXC = 15;
struct Cut {
    int c, id, t;
    int fruit[MAXC];
    bool operator<(const Cut &s) const {
        return t<s.t;
    }
};
int best;
bool used[MAXM];
int sta[MAXN];
int ans[MAXN];
Cut cut[MAXN];
int n, m, w;
int f[MAXN];
void init() {
    best = 0;
    memset(used,0,sizeof(used));
    memset(f,0,sizeof(f));
}
void dfs(int dep, int cur) {
    if (cur-1+f[dep] <= best)
        return ;
    int cnt = 0;
    int tlist[MAXC] = {0};
    for (int i = 0; i < cut[dep].c; ++i) {
        int j = cut[dep].fruit[i];
        if (!used[j]) {
            tlist[cnt++] = j;
        }
    }
    if (cnt < 3)
        return ;
    sta[cur] = cut[dep].id;
    if (cur > best) {
        best = cur;
        memcpy(ans,sta,sizeof(ans));
    }
    for (int i = 0; i < cnt; ++i)
        used[tlist[i]] = true;
    for (int i = dep+1; i < n; ++i) {
        if (cut[i].t - cut[dep].t > w)
            break;
        dfs(i,cur+1);
    }
    for (int i = 0; i < cnt; ++i)
        used[tlist[i]] = false;
}
void prepare() {
    for (int i = 0; i < n; ++i) {
        f[i] = 1;
        for (int j = i+1; j < n && cut[j].t-cut[j-1].t <= w; ++j)
            ++f[i];
    }
}
void work() {
    // test();
    sort(cut,cut+n);
    prepare();
    for (int i = 0; i < n; ++i) {
        dfs(i,1);
    }
    printf("%d\n", best);
    sort(ans+1,ans+1+best);
    printf("%d", ans[1]+1);
    for (int i = 2; i <= best; ++i)
        printf(" %d", ans[i]+1);
    puts("");
}
void load() {
    scanf("%d%d%d", &n, &m, &w);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &cut[i].c, &cut[i].t);
        for (int j = 0; j < cut[i].c; ++j) {
            scanf("%d", &cut[i].fruit[j]);
        }
        cut[i].id = i;
    }
}
int main(int argc, char const *argv[]) {
    int T;
    scanf("%d", &T);
    while (T--) {
        load();
        work();
        init();
    }
    return 0;
}