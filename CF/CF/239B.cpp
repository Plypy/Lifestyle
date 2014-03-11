#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;
const int MAXN = 200;
char s[MAXN];
int ct[MAXN];
char buf[MAXN];
void excute(int l, int r) {
    memcpy(buf,s,sizeof(buf));
    int cp = l, dp = 1;
    int last = -1;
    while (cp >= l && cp <= r) {
        if (0 == buf[cp]) {
            cp += dp;
        } else if ('>' == buf[cp]) {
            if (last != -1 && !isdigit(buf[last]))
                buf[last] = 0;
            dp = 1;
            last = cp;
            cp += dp;
        } else if ('<' == buf[cp]) {
            if (last != -1 && !isdigit(buf[last]))
                buf[last] = 0;
            dp = -1;
            last = cp;
            cp += dp;
        } else {
            ++ct[buf[cp]-'0'];
            last = cp;
            if (buf[cp] > '0')
                --buf[cp];
            else
                buf[cp] = 0;
            cp += dp;;
        }
    }
}
int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    scanf("%s", s);
    for (int i = 1; i <= q; ++i) {
        memset(ct,0,sizeof(ct));
        int l, r;
        scanf("%d%d", &l, &r);
        excute(l-1,r-1);
        printf("%d", ct[0]);
        for (int i = 1; i < 10; ++i)
            printf(" %d", ct[i]);
        puts("");
    }
    return 0;
}
