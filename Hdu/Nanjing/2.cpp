#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <numeric>
#include <string>

using namespace std;
const int MAXN = 100005;
const int MAXK = 35;
const int P = 9875321;
typedef long long ll;
int n, m, k, cnt;

vector<int> occured;

int a[MAXN], s[MAXN], pat[MAXN];


set<ll> table;
vector<int> pos[MAXK];

ll coef[MAXN];

void prep() {
    coef[0] = 1;
    for (int i = 1; i < MAXN; ++i)
        coef[i] = coef[i-1] * P;
}




int wt[MAXK];
ll q[MAXN];
bool used[MAXK];

void clear() {
    table.clear();
    occured.clear();
    memset(used,0,sizeof(used));
    for (int i = 0; i < MAXK; ++i)
        pos[i].clear();
}

ll wtsum[MAXK];

void dfs(int st, int dep) {
    if (dep == cnt) {
        ll tmp = 0;
        for (int i = 1; i <= cnt; ++i)
            tmp += s[i] * wtsum[i];
        table.insert(tmp);
        return;
    }
    int t = cnt - dep;
    for (int i = st+1; i <= k+1-t; ++i) {
        s[dep + 1] = i;
        dfs(i, dep + 1);
    }
}

void work() {
    for (int i = 0; i < m; ++i)
        used[pat[i]] = 1;
    for (int i = 1; i <= k+1; ++i) {
        if (used[i]) {
            occured.push_back(i);
        }
    }


    cnt = occured.size();
    for (int i = 0; i < cnt; ++i)
        wt[occured[i]] = i + 1;
    for (int i = 0; i < m; ++i)
        pat[i] = wt[pat[i]];
    for (int i = 0; i < m; ++i)
        pos[pat[i]].push_back(i);
    for (int i = 1; i < cnt+1; ++i) {
        wtsum[i] = 0;
        int len = pos[i].size();
        for (int j = 0; j < len; ++j)
            wtsum[i] += coef[n - 1 - pos[i][j]];
    }

    dfs(0, 0);


    q[0] = 0;
    q[1] = a[0] * coef[n - 1];
    for (int i = 2; i <= n; ++i)
        q[i] = q[i - 1] + a[i - 1] * coef[n - i];

    int ans = 0, i = 0;
    while(i < n - m + 1) {
        ll tmp = (q[i + m] - q[i]) * coef[i];
        if (table.count(tmp)) {
            ++ans;
            i = i + m - 1;
        }
        ++i;
    }
    printf("%d\n", ans);
}

bool load() {
    if (EOF == scanf("%d%d%d", &n, &m, &k)) {
        return false;
    }
    clear();
    for (int i = 0; i < n; ++i)
        scanf("%d", a+i);
    for (int i = 0; i < m; ++i)
        scanf("%d", pat+i);
    return true;
}

int main() {
    prep();

    while (load()) {
        work();
    }
    return 0;
}

