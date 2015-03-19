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

const int MAXN = 105;
int g[MAXN][MAXN];

int n, m;
vector<int> ans;
void dfs(int u) {
    for (int i = 1; i <= n; ++i)
        if (g[u][i]) {
            --g[u][i], --g[i][u];
            dfs(i);
        }
    ans.push_back(u);
}
void work() {
    dfs(1);
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << ' ';
    cout << endl;
}
void load() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        ++g[a][b], ++g[b][a];
    }
}
int main(int argc, char const *argv[]) {
    load();
    work();
    return 0;
}