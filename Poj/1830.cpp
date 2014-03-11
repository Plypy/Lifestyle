/**
 * Description: Solving system of xor equations
 * Source: Poj
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

const int MAXN = 35;

int n;
bool a[MAXN], b[MAXN];
bool g[MAXN][MAXN];
int w[MAXN];
void work() {

    for (int i = 1; i <= n; ++i) {
        g[i][i] = true;
        g[i][0] = a[i]^b[i];
    }
    int r = 0, ans = 0;
    for (int i = 1; i <= n; ++i)
        w[i] = i;

    for (int i = 1; i <= n; ++i) {
        for (int j = r+1; j <= n; ++j) {
            if (g[w[j]][i]) {
                swap(w[j],w[r+1]);
                break;
            }
        }
        if (!g[w[r+1]][i]) {
            ++ans;
            continue;
        }
        ++r;
        for (int j = 1; j <= n; ++j) {
            if (j != r && g[w[j]][i]) {
                g[w[j]][0] ^= g[w[r]][0];
                for (int k = i; k <= n; ++k)
                    g[w[j]][k] ^= g[w[r]][k];
            }
        }
    }
    bool suc = true;
    for (int i = r+1; i <= n; ++i)
        if (g[w[i]][0]) {
            suc = false;
            break;
        }
    if (suc) {
        ans = (1<<ans);
        cout << ans << endl;
    } else {
        cout << "Oh,it's impossible~!!" << endl;
    }
}
void clear() {
    memset(g,0,sizeof(g));
}
void load() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];
    int u, v;
    while (true) {
        cin >> u >> v;
        if (u == 0 && v == 0)
            break;
        g[v][u] = true;
    }
}
int main(int argc, char const *argv[]) {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        load();
        work();
        clear();
    }
    return 0;
}