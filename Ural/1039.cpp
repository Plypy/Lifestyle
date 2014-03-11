#include <iostream>
#include <cstdlib>
using namespace std;

class Problem {
private:
    static const int MAXN = 6010;
    int n;
    bool notRt[MAXN];
    int nxt[MAXN];
    int edg[MAXN];
    int adj[MAXN];
    int val[MAXN];
    inline int max(int a, int b) {
        return a>b?a:b;
    }
    int memo[MAXN][2];
    bool flag[MAXN][2];
public:
    void load() {
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> val[i];
        int l, k;
        while (true) {
            cin >> l >> k;
            if (0 == l)
                break;
            notRt[l] = true;
            edg[++edg[0]] = l;
            nxt[edg[0]] = adj[k];
            adj[k] = edg[0];
        }
    }
    int dp(int id, bool invited) {
        if (flag[id][invited])
            return memo[id][invited];
        int ret = invited?val[id]:0;
        for (int v = adj[id]; v; v = nxt[v]) {
            if (invited)
                ret += dp(edg[v],false);
            else
                ret += max(dp(edg[v],true),dp(edg[v],false));
        }
        flag[id][invited] = true;
        return memo[id][invited] = ret;
    }
    void work() {
        int rt = 0;
        for (int i = 1; i <= n; ++i)
            if (!notRt[i]) {
                rt = i;
                break;
            }
        cout << max(dp(rt,true),dp(rt,false)) << endl;
    }
    int run() {
        load();
        work();
//        system("pause");
        return 0;
    }
} prob;
int main() {
    return prob.run();
}
