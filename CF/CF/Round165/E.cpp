//给定一个最大流，确定每条边的流向
#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <cstdio>
using namespace std;

const int MAXN = 200005;
const int MAXM = MAXN;
int n, m;
int s[MAXM], t[MAXM], c[MAXM];
int out[MAXN], in[MAXN];
vector<pair<int,int> > adj[MAXN];
void load() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d", s+i, t+i, c+i);
        out[s[i]] += c[i];
        out[t[i]] += c[i];
        adj[s[i]].push_back(make_pair(t[i],i));
        adj[t[i]].push_back(make_pair(s[i],i));
    }
}
int ans[MAXM];
void work() {
    memset(ans,-1,sizeof(ans));
    queue<int> Q;
    Q.push(1);
    while (Q.size()) {
        int u = Q.front();
        Q.pop();
        for (vector<pair<int,int> >::iterator it = adj[u].begin();
            it != adj[u].end(); ++it) {
                int v = it->first, id = it->second;
                if (ans[id] != -1)
                    continue;
                if (s[id] == u)
                    ans[id] = 0;
                else
                    ans[id] = 1;
                in[v] += c[id];
                out[v] -= c[id];
                if (in[v] == out[v] && v != n)
                    Q.push(v);
                }
    }
    for (int i = 1; i <= m; ++i)
        printf("%d\n", ans[i]);
}
int main() {
    load();
    work();
    return 0;
}
