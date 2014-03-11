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
const int MAXN = 55;
bool taken[MAXN][MAXN];
int val[MAXN][MAXN];

struct Stu {
    int t, q;
    int id;
} stu[MAXN];
bool cmp(const Stu &a, const Stu &b) {
    return a.t<b.t;
}
int ans[MAXN][2];
int n, m, K;
void take(const Stu &s) {
    int tr = -1, tc = -1, tv = -1;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (!taken[i][j] && val[i][j] > tv) {
                tv = val[i][j];
                tr = i, tc = j;
            }
        }
    int br = -1, bc = -1, bv = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j+s.q <= m; ) {
            int k = 0;
            for (; k < s.q; ++k) {
                if (taken[i][j+k])
                    break;
            }
            if (k == s.q) {
                if (val[i][j] > bv) {
                    bv = val[i][j];
                    br = i, bc = j;
                }
                j = j+1;
            } else {
                j = j+k+1;
            }
        }
    }
    if (-1 != bv) {
        ans[s.id][0] = br+1, ans[s.id][1] = bc+1;
        for (int k = 0; k < s.q; ++k) {
            taken[br][bc+k] = true;
        }
    } else if (-1 != tv) {
        ans[s.id][0] = tr+1, ans[s.id][1] = tc+1;
        taken[tr][tc] = true;
    }
}

void work() {
    sort(stu,stu+K,cmp);
    for (int i = 0; i < K; ++i)
        take(stu[i]);
    for (int i = 0; i < K; ++i)
        if (ans[i][0] != -1) {
            printf("%d %d\n", ans[i][0], ans[i][1]);
        } else {
            puts("-1");
        }
}
void init() {
    memset(ans,-1,sizeof(ans));
    memset(taken,0,sizeof(taken));
}
bool load() {
    init();
    scanf("%d%d%d", &n, &m, &K);
    if (n == 0)
        return false;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            scanf("%d", &val[i][j]);
        }
    for (int i = 0; i < K; ++i) {
       int a, b, c;
       scanf("%d:%d%d", &a, &b, &c);
       stu[i].id = i;
       stu[i].t = a*60+b;
       stu[i].q = c;
    }
    return true;
}

int main(int argc, char const *argv[]) {
    while (load()) {
        work();
    }
    return 0;
}