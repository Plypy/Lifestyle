/*
    ID: jake1994
    PROG: schlnet
    LANG: C++
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <fstream>
using namespace std;
ifstream fin("schlnet.in");
ofstream fout("schlnet.out");
class Problem {
private:
    static const int MAXN = 110;
    int edg[MAXN*MAXN], adj[MAXN*MAXN], nxt[MAXN*MAXN];
    bool g[MAXN][MAXN];
    int n;
    int tick[MAXN], low[MAXN];
    int rep[MAXN];
    int stack[MAXN];
    bool in[MAXN];
    inline int min(int a, int b) {
        return a<b?a:b;
    }
    inline int max(int a, int b) {
        return a>b?a:b;
    }
    int ind[MAXN], oud[MAXN];
    int ans1, ans2;
public:
    void load() {
        fin >> n;
        int t;
        for (int i = 1; i <= n; ++i) {
            while (true) {
                fin >> t;
                if (!t)
                    break;
                g[i][t] = true;
                edg[++edg[0]] = t;
                nxt[edg[0]] = adj[i];
                adj[i] = edg[0];
            }
        }
    }
    void tarjan(int u) {
        static int time = 0;
        tick[u] = low[u] = ++time;
        stack[++stack[0]] = u;
        in[u] = true;
        int v;
        for (int i = adj[u]; i; i = nxt[i]) {
            v = edg[i];
            if (!tick[v]) {
                tarjan(v);
                low[u] = min(low[u],low[v]);
            } else if (in[v])
                low[u] = min(low[u],tick[v]);
        }
        
        if (low[u] == tick[u])
        {
            ++rep[0];
            do {
                v = stack[stack[0]--];
                rep[v] = rep[0];
                in[v] = false;
            } while (u != v);
        }
    }
    void task() {
        for (int i = 1; i <= n; ++i)
            if (!tick[i])
                tarjan(i);
        ans1 = ans2 = rep[0];
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (rep[i] != rep[j] && g[i][j]) {
                    if (ind[rep[j]] == 0)
                        --ans1;
                    if (oud[rep[i]] == 0)
                        --ans2;
                    ++ind[rep[j]];
                    ++oud[rep[i]];
                }
    }
    void output() {
        fout << ans1 << endl;
        if (rep[0] == 1)
            fout << 0 << endl;
        else
            fout << max(ans1,ans2) << endl;
    }
    void work() {
        task();
        output();
    }
    int run() {
        load();
        work();
        return 0;
    }
} prob;
int main() {
    return prob.run();
}
