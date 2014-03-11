/**
 * Description:
 * Source:
 * Solution: http://blog.csdn.net/dslovemz/article/details/15236929
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

const int MAXN = 200005;
int n, m;
int C[MAXN];
inline int lowbit(int a) {
    return a&(-a);
}
void add(int p, int v) {
    for (; p <= n; p += lowbit(p))
        C[p] += v;
}
int get(int p) {
    int ret = 0;
    for (; p; p -= lowbit(p))
        ret += C[p];
    return ret;
}
vector<int> prime, fac[MAXN];
bool notp[MAXN];
int minfac[MAXN];
void prepare() {
    for (int i = 2; i < MAXN; ++i) {
        if (!notp[i]) {
            prime.push_back(i);
            minfac[i] = i;
        }
        int t;
        for (int j = 0; j < prime.size() && (t = prime[j]*i) < MAXN; ++j) {
            notp[t] = true;
            minfac[t] = prime[j];
            if (i % prime[j] == 0)
                break;
        }
    }
    for (int i = 2; i < MAXN; ++i) {
        int t = i;
        while (t != 1) {
            fac[i].push_back(minfac[t]);
            int mp = minfac[t];
            while (t%mp == 0)
                t /= mp;
        }
    }
}
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
pii ques[MAXN];
int ar[MAXN];
int l[MAXN], r[MAXN];
vector<int> lis[MAXN];
int pos[MAXN];
int ans[MAXN];
void init() {
    memset(C,0,sizeof(C));
    for (int i = 1; i <= n; ++i)
        lis[i].clear();
}
bool load() {
    scanf("%d%d", &n, &m);
    if (n == 0)
        return false;
    for (int i = 1; i <= n; ++i)
        scanf("%d", ar+i);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &ques[i].first, &ques[i].second.first);
        ques[i].second.second = i;
    }
    return true;
}
void work() {
    sort(ques,ques+m);

    memset(pos,0,sizeof(pos));
    for (int i = 1; i <= n; ++i) {
        int mpos = 0;
        for (int j = 0; j < fac[ar[i]].size(); ++j) {
            mpos = max(mpos,pos[fac[ar[i]][j]]);
            pos[fac[ar[i]][j]] = i;
        }
        l[i] = mpos;
        lis[mpos].push_back(i);
    }
    memset(pos,0x3f,sizeof(pos));
    for (int i = n; i; --i) {
        int mpos = n+1;
        for (int j = 0; j < fac[ar[i]].size(); ++j) {
            mpos = min(mpos,pos[fac[ar[i]][j]]);
            pos[fac[ar[i]][j]] = i;
        }
        r[i] = mpos;
    }
    for (int i = 1; i <= n; ++i) {
        if (l[i] < 1) {
            add(i,1);
            if (r[i] <= n)
                add(r[i],-1);
        }
    }
    int left = 1;
    for (int i = 0; i < m; ++i) {
        while (left < ques[i].first) {
            add(left, -1);
            if (r[left] <= n) add(r[left], 1);
            for (int j = 0; j < lis[left].size(); ++j) {
                int t = lis[left][j];
                add(t,1);
                if (r[t] <= n)
                    add(r[t],-1);
            }
            ++left;
        }
        ans[ques[i].second.second] = get(ques[i].second.first)-get(ques[i].first-1);
    }
    for (int i = 0; i < m; ++i)
        printf("%d\n", ans[i]);
}

int main(int argc, char const *argv[]) {
    prepare();
    while (load()) {
        init();
        work();
    }
    return 0;
}