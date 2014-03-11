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
const int MAXN = 1005;
const int MOD = 1000000007;
typedef long long LL;
int n, k;
LL ans = 0;
bool used[MAXN];
int mem[MAXN];
void dfs(int dep, int ct) {
    if (dep == n) {
        if (ct == k) {
            ++ans;
            for (int i = 1; i <= n; ++i)
                cout << mem[i] << ' ';
            cout << endl;
        }
        return ;
    }
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            used[i] = true;
            mem[dep+1] = i;
            if (1 == abs(i-dep-1))
                dfs(dep+1,ct+1);
            else
                dfs(dep+1,ct);
            used[i] = false;
        }
    }
}
int main() {
    while (true) {
        ans = 0;
        scanf("%d%d", &n, &k);
        dfs(0,0);
        cout << ans << endl;
    }
    return 0;
}
