#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
const int MAXN = 300005;

int col[MAXN];
int n, m;
vector<int> adj[MAXN];
void load() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}
bool isbad(int u) {
    int ct = 0;
    for (int i = 0; i < adj[u].size(); ++i)
        if (col[adj[u][i]] == col[u])
            ++ct;
    if (ct > 1)
        return true;
    return false;
}
void work() {
    memset(col,-1,sizeof(col));
    queue<int> que;
    for (int i = 1; i <= n; ++i) {
        if (-1 == col[i]) {
            col[i] = 0;
            que.push(i);
            while (que.size()) {
                int u = que.front();
                que.pop();
                for (int i = 0; i < adj[u].size(); ++i)
                    if (-1 == col[adj[u][i]]) {
                        que.push(adj[u][i]);
                        col[adj[u][i]] = 1-col[u];
                    }
            }
        }
    }
    stack<int> stk;
    for (int i = 1; i <= n; ++i)
        if (isbad(i)) {
            stk.push(i);
            while (stk.size()) {
                int u = stk.top();
                stk.pop();
                col[u] = 1-col[u];
                for (int i = 0; i < adj[u].size(); ++i)
                    if (isbad(adj[u][i]))
                        stk.push(adj[u][i]);
            }
        }
    for (int i = 1; i <= n; ++i)
        printf("%d", col[i]);
    puts("");
}
int main() {
    load();
    work();
    return 0;
}
