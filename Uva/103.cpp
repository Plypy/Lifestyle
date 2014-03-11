#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 35;
const int MAXM = 15;
int n, m;
struct Data {
    int ar[MAXM];
    bool operator<(const Data &t) const {
        for (int i = 0; i < m; ++i)
            if (ar[i] >= t.ar[i])
                return false;
        return true;
    }
} box[MAXN];
int f[MAXN];
int pre[MAXN];
int ans;
int last;
int anslist[MAXN];
int main() {
    while (EOF != scanf("%d%d", &n, &m)) {
        memset(f,-1,sizeof(f));
        memset(pre,-1,sizeof(pre));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
                scanf("%d", &box[i].ar[j]);
            sort(box[i].ar,box[i].ar+m);
        }
        for (int i = 0; i < n; ++i) {
            f[i] = 1;
            for (int j = 0; j < i; ++j)
                if (box[j] < box[i] && f[j]+1 > f[i]) {
                    f[i] = f[j]+1;
                    pre[i] = j;
                }
        }
        for (int i = 1; i < n; ++i)
            if (f[i] > f[last])
                last = i;
        ans = f[last];
        for (int i = f[last]; i; --i) {
            anslist[i] = last+1;
            last = pre[last];
        }
        printf("%d\n", ans);
        for (int i = 1; i <= ans; ++i) {
            printf("%d", anslist[i]);
            if (ans == i)
                printf("\n");
            else
                printf(" ");
        }
    }
}
