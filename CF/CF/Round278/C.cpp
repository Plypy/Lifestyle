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
#include <bitset>
#include <stack>
using namespace std;

const int MAXN = 100005;
int ans[MAXN];
bool used[MAXN];
int n;

bool check() {
    int t = 1;
    memset(used, 0, sizeof(used));
    for (int i = 1; i <= n; ++i) {
        t *= ans[i];
        t %= n;
        if (used[t]) {
            return false;
        }
        used[t] = true;
    }
    return true;
}

bool has[MAXN];
void dfs(int dep) {
    // cout << dep << ' ' << ans[dep-1] << endl;
    if (dep == n+1) {
        if (check()) {
            for (int i = 1; i <= n; ++i) {
                cout << ans[i] << ' ';
            }
            cout << endl;
        }
        return ;
    }
    for (int i = 1; i <= n; ++i) {
        if (has[i]) {
            continue;
        }
        ans[dep] = i;
        has[i] = true;
        dfs(dep+1);
        has[i] = false;
    }
}

int main() {
    while (true) {
        cin >> n;
        dfs(1);
    }
}
