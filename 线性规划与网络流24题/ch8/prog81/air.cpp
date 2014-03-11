#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;
ifstream fin("air.in");
ofstream fout("air.out");
const int MAXN = 110;
bool g[MAXN][MAXN];
bool used[MAXN];
int pal[MAXN];
int n, m;

void load() {
    fin >> m >> n;
    n -= m;
    int a, b;
    while (true) {
        fin >> a >> b;
        if (-1 == a)
            break;
        b -= m;
        g[a][b] = true;
    }
}
int tot;
bool suc[MAXN];
bool find(int u) {
    for (int v = 1; v <= n; ++v)
        if (g[u][v] && !used[v]) {
            used[v] = true;
            if (!pal[v] || find(pal[v])) {
                pal[v] = u;
                return true;
            }
        }
    return false;
}

void work() {
    for (int i = 1; i <= m; ++i) {
        memset(used,0,sizeof(used));
        if (find(i)) {
            ++tot;
            suc[i] = true;
        }
    }
}

void output() {
    if (tot)
        fout << tot << endl;
    else
        fout << "No Solution!" << endl;
    for (int i = 1; i <= m; ++i)
        if (suc[i])
            fout << i << ' ' <<  n+pal[i] << endl;
}

int main() {
    load();
    work();
    output();
    return 0;
}
