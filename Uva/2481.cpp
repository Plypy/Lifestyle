// Accepted
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1005
#define INF 52111425
using namespace std;
int n;
bool getn() {
    scanf("%d", &n);
    if (!n)
        return false;
    return true;
}

int num[MAXN];
int ctable[MAXN];
int nxt[MAXN];
bool vis[MAXN];
int id[MAXN];
int work() {
    int minval = INF;
    memset(ctable,0,sizeof(ctable));
    for (int i = 1; i <= n; ++i) {
        scanf("%d", num+i);
        minval = min(minval,num[i]);
        ctable[num[i]] = 1;
    }
    for (int i = minval+1; i < MAXN; ++i)
        ctable[i] += ctable[i-1];
    for (int i = 1; i <= n; ++i) {
        id[i] = ctable[num[i]];
        nxt[id[i]] = i;
    }
    
    memset(vis,0,sizeof(vis));
    int ret = 0;
    for (int i = 1; i <= n; ++i)
        if (!vis[i]) {
            int sum = 0;
            int len = 0;
            int tmval = INF;
            int j = i;
            while (true) {
                vis[j] = true;
                ++len;
                sum += num[j];
                tmval = min(tmval,num[j]);
                if (vis[nxt[j]])
                    break;
                j = nxt[j];
            }
            ret += min(sum+tmval*(len-2),sum+minval*(len+1)+tmval);
        }
    return ret;
}


int main() {
    for (int i = 1; getn(); ++i) {
        printf("Case %d: %d\n\n", i, work());
    }
    return 0;
}
