/* 可以转化为二分图匹配模型
 * 因为可以这样考虑，对于图中的任意一个顶点
 * 若其不为某一个路径的终点的话，那么从这个点必然有出边
 * 也就是说必然有另一个顶点与这个顶点相对应
 * 这也就提示了我们二分图最大匹配的模型可能适用
 * 但是题目要求的是最小路径覆盖数,这个怎么考虑呢
 * 考虑到每条路径必然会有一个终点没有匹配上
 * 也就是说没匹配上的顶点个数也就是路径数
 * 那么要求最小路径覆盖的话，只需要让没匹配上的顶点最少，即匹配的最多即可
 * 最后答案就是顶点数减去最大匹配数
 */
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>
using namespace std;
ifstream fin("path.in");
ofstream fout("path.out");
const int MAXN = 150;

bool g[MAXN][MAXN];
bool used[MAXN];
int pal[MAXN];
int nxt[MAXN];
int n, m;

void load() {
    fin >> n >> m;
    while (m--) {
        int a, b;
        fin >> a >> b;
        g[a][b] = true;
    }
}
int ans;
bool find(int u) {
    for (int v = 1; v <= n; ++v)
        if (g[u][v] && !used[v]) {
            used[v] = true;
            if (!pal[v] || find(pal[v])) {
                nxt[u] = v;
                pal[v] = u;
                return true;
            }
        }
    return false;
}
void work() {
    for (int i = 1; i <= n; ++i) {
        memset(used,0,sizeof(used));
        if (find(i))
            ++ans;
    }
    ans = n-ans;
}

void output() {
    for (int i = 1; i <= n; ++i) {
        if (!pal[i]) {
            int t = i;
            while (true) {
                fout << t;
                if (!nxt[t]) {
                    fout.put('\n');
                    break;
                }
                t = nxt[t];
                fout.put(' ');
            }
        }
    }
    fout << ans << endl;
}

int main() {
    load();
    work();
    output();
    return 0;
} 
