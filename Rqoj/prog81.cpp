/* 线性规划与网络流24题之一 
 * 飞行员配对问题
 * 赤裸裸的二分图最大匹配问题 
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;
ifstream fin("air.in");
ofstream fout("air.out");
const int MAXN = 110;
int n, m;
bool r[MAXN][MAXN];
void load() {
    fin >> m >> n;
    n = n-m;
    int a, b;
    while (true) {
        fin >> a >> b;
        if (a == -1)
            break;
        b -= m;
        r[a][b] = true;
    }
}
bool used[MAXN];
int pat[MAXN], rpat[MAXN];
bool find(int u) {
    for (int v = 1; v <= n; ++v)
        if (r[u][v] && !used[v]) {
            used[v] = true;
            if (!rpat[v] || find(rpat[v])) {
                rpat[v] = u;
                pat[u] = v;
                return true;
            }
        }
    return false;
}
int ans;
void work() {
    for (int i = 1; i <= m; ++i) {
        memset(used,0,sizeof(used));
        if (find(i))
            ans++;
    }
}
void output() {
    fout << ans << endl;
    for (int i = 1; i <= m; ++i)
        if (pat[i])
            fout << i << ' ' << pat[i]+m << endl;
}
int main() {
    load();
    work();
    output();
    return 0;
} 
