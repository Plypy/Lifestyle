#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 110;
const int USED = 1;
const int DECREASED = -1;
const int ADDED = 2;
int graph[MAXN][MAXN];
int n;
long long d, a;
int ect;
void load() {
    cin >> n;
    cin >> d >> a;
    for (int i = 1; i <= n; ++i) {
        getchar();
        for (int j = 1; j <= n; ++j) {
            char c;
            scanf("%c", &c);
            if ('1' == c) {
                graph[i][j] = DECREASED;
                ++ect;
            }
        }
    }
    ect >>= 1;
}


int ct;
int rep[MAXN];
bool vis[MAXN];
long long ans;
void dfs(int u) {
    vis[u] = true;
    for (int v = 1; v <= n; ++v)
        if (graph[u][v] && !vis[v]) {
            graph[u][v] = graph[v][u] = USED;
            dfs(v);
        }
}
void work() {
    for (int i = 1; i <= n; ++i)
        if (!vis[i]) {
            rep[++ct] = i;
            dfs(i);
        }
    for (int i = 2; i <= ct; ++i)
        graph[rep[1]][rep[i]] = graph[rep[i]][rep[1]] = ADDED;
    int anum = ct-1;
    int dnum = ect+anum-n+1;
    ans = anum*a+dnum*d;
}

void out() {
    cout << ans << endl;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            switch (graph[i][j]) {
                case DECREASED:
                    putchar('d');
                    break;
                case ADDED:
                    putchar('a');
                    break;
                default:
                    putchar('0');
            }
        }
        putchar('\n');
    }
}

int main() {
    load();
    work();
    out();
 //   system("pause");
    return 0;
}
