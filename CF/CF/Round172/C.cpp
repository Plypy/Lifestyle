#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iomanip>
#include <queue>
using namespace std;
const int MAXN = 100005;
double ans;
vector<int> adj[MAXN];
bool used[MAXN];
void dfs(int u, int d) {
    used[u] = true;
    int len = adj[u].size();
    for (int i = 0; i < len; ++i) {
        int v = adj[u][i];
        if (!used[v]) {
            dfs(v,d+1);
        }
    }
    ans += 1.0/d;
}
int n;
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,1);
    cout << fixed << setprecision(15) << ans << endl;
    return 0;
}
