#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 10005;
int len[MAXN];
int n, m;
int where(int t) {
    int l = 1, r = n;
    while (l < r) {
        int mid = int((l+r)/2.0+0.5);
        if (len[mid] > t)
            r = mid-1;
        else
            l = mid;
    }
    return l;
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 2; i <= n; ++i) {
            scanf("%d", len+i);
            len[i] += len[i-1];
        }
        while (m--) {
            int s;
            scanf("%d", &s);
            int pos = where(s);
            if (s == len[pos])
                printf("%d\n", pos);
            else
                printf("%d %d\n", pos, pos+1);
        }
    }
    return 0;
}
