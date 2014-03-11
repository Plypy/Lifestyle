/*
  The Beautiful Chinese Knot
*/
// Todo 
// 用dfs将原树的节点映射到一个线段树上
// 然后使用线段树操作就可以
// 可以考虑使用标记优化
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class Problem {
private:
    static const int MAXN = 100010;
    struct Knot {
        int st, ed;
    } knot[MAXN];
    int edge[MAXN][4];
    bool used[MAXN];
    int n, m;
    int stree[MAXN<<1];
public:
    void load() {
        scanf("%d", &n);
        int u, v;
        for (int i = 1; i < n; ++i) {
            scanf("%d%d", &u, &v);
            edge[u][++edge[u][0]] = v;
            edge[v][++edge[v][0]] = u;
        }
    }
    void dfs(int u) {
        static int tRecord;
        knot[u].st = ++tRecord;
        used[u] = true;
        for (int i = 1; i <= edge[u][0]; ++i)
            if (!used[edge[u][i]])
                dfs(edge[u][i]);
        knot[u].ed = tRecord;
    }
    void build() {
        dfs(1);
    }
    void change(int lbd, int rbd) {
        for (int i = lbd+n; i <= rbd+n; ++i)
            stree[i] ^= 1;
        lbd += n, rbd += n;
        for (lbd >>= 1, rbd >>= 1; lbd; lbd >>= 1, rbd >>= 1)
            for (int i = lbd; i <= rbd; ++i)
                stree[i] = stree[i<<1] + stree[(i<<1)+1];
    }
    int query(int lbd, int rbd) {
        int ret = 0;
        for (lbd += n-1, rbd += n+1; lbd^rbd^1; lbd >>= 1, rbd >>= 1) {
            if (~lbd&1)
                ret += stree[lbd+1];
            if (rbd&1)
                ret += stree[rbd-1];
        }
        return ret;
    }
    void work() {
        build();
        scanf("%d", &m);
        char type;
        int x;
        while (m--) {
            while ('\n' != getchar())
                continue;
            scanf("%c%d", &type, &x);
            if ('C' == type) {
                change(knot[x].st, knot[x].ed);
            } else {
                printf("%d\n", query(knot[x].st, knot[x].ed));
            }
        }
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
/*
5
1 2
1 3
2 4
2 5
5
Q 1
C 1
Q 1
C 2
Q 1

0
5
2
*/
