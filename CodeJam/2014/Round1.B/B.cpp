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


const int MAXL = 30;
typedef long long ll;

ll f[MAXL][2][2][2];
int a, b, c;
int sa[MAXL],sb[MAXL],sc[MAXL];
ll dp(int p, bool fa, bool fb, bool fc) {
    if (-1 == p) {
        return fa&&fb&&fc? 1: 0;
    }
    if (f[p][fa][fb][fc] != -1)
        return f[p][fa][fb][fc];
    ll ret = 0;
    for (int x = 0; x < 2; ++x) {
        for (int y = 0; y < 2; ++y) {
            int v = x&y;
            if (!fa && (x > sa[p]))
                continue;
            if (!fb && (y > sb[p]))
                continue;
            if (!fc && (v > sc[p]))
                continue;
            ret += dp(p-1, fa||(x<sa[p]), fb||(y<sb[p]), fc||(v<sc[p]));
        }
    }
    return f[p][fa][fb][fc] = ret;
}
void init() {
    memset(f,-1,sizeof(f));
}
void load() {
    scanf("%d%d%d", &a, &b, &c);
}
ll work() {
    for (int i = 0; i < MAXL; ++i) {
        sa[i] = a&1;
        a   >>= 1;
        sb[i] = b&1;
        b   >>= 1;
        sc[i] = c&1;
        c   >>= 1;
    }
    return dp(MAXL-1,0,0,0);
}

int main(int argc, char const *argv[]) {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        init();
        load();
        ll ans = work();
        printf("Case #%d: %lld\n", i+1, ans);
    }
    return 0;
}
