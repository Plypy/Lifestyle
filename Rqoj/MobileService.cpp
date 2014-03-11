/*
 * 状态压缩DP,状态如下
 * 设在第i次移动时没有行动的两人分别在j,k两地，且第i次移动到p[i]地
 * SpecialNote 在Tyvj和RQNOJ上 iostream家族的确比printf，scanf家族要慢许多 
 */
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
class Problem {
private:
    static const int MAXN = 210;
    static const int INF = 52111425;
    int cost[MAXN][MAXN];
    int f[2][MAXN][MAXN];
    int loc[2];
    bool used[MAXN];
    int n, p;
    inline int min(int a, int b) {
        return a<b?a:b;
    }
public:
    void load() {
//        freopen("test.in", "r", stdin);
//        freopen("test.out", "w", stdout);
        cin >> n >> p;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j) {
                f[1][i][j] = f[0][i][j] = INF;
                scanf("%d", &cost[i][j]);
            }
    }
    void show(int t) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j)
                cout << f[t][i][j] << ' ';
            cout << endl;
        }
    }
    void work() {
        int u, v;
        used[1] = used[2] = used[3] = true;
        scanf("%d", loc+1);
        used[loc[1]] = true;
        f[1][1][2] = f[1][2][1] = cost[3][loc[1]];
        f[1][1][3] = f[1][3][1] = cost[2][loc[1]];
        f[1][2][3] = f[1][3][2] = cost[1][loc[1]];
        for (int i = 2; i <= p; ++i) {
            u = (i-1)&1;
            v = i&1;
            scanf("%d", loc+v);
            for (int j = 1; j <= n; ++j)
                for (int k = 1; k <= n; ++k)
                    f[v][j][k] = INF;
            for (int j = 1; j <= n; ++j)
                if (used[j])
                    for (int k = 1; k <= n; ++k)
                        if (k != j && used[k]) {
                            f[v][j][k] = min(f[v][j][k],f[u][j][k]+cost[loc[u]][loc[v]]);
                            f[v][j][loc[u]] = min(f[v][j][loc[u]],f[u][j][k]+cost[k][loc[v]]);
                            f[v][loc[u]][k] = min(f[v][loc[u]][k],f[u][j][k]+cost[j][loc[v]]);
                        }
            used[loc[v]] = true;
        }
        int ans = INF;
        for (int i = 1; i <= n; ++i)
            if (used[i])
                for (int j = 1; j <= n; ++j)
                    if (j != i && used[j])
                        ans = min(ans,f[p&1][i][j]);
        cout << ans << endl;
    }
    int run() {
        load();
        work();
        return 0;
    }
} prob;
int main()
{
    return prob.run();
}
