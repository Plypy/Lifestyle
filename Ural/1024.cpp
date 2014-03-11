// 群论
// 拆置换群为循环
// 各个循环节长度的最小公约数即为所求 

#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int MAXN = 1005;
int ar[MAXN];
int n;

void load() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", ar+i);
}

bool vis[MAXN];

int dfs(int u) {
    vis[u] = true;
    int ret = 1;
    if (!vis[ar[u]])
        ret += dfs(ar[u]);
    return ret;
}

inline int gcd(int a, int b) {
    int t;
    while (b) {
        t = a;
        a = b;
        b = t%b;
    }
    return a;
}

inline int lcm(int a, int b) {
    int t = gcd(a,b);
    return a*b/t;
}

void work() {
    int ans = 1;
    for (int i = 1; i <= n; ++i)
        if (!vis[i]) {
            int len = dfs(i);
            ans = lcm(ans,len);
        }
    
    printf("%d\n", ans);
}

int main() {
    load();
    work();
//    system("pause");
    return 0;
}
