#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iomanip>
#include <queue>
using namespace std;
typedef long long LL;
const int MAXN = 200005;
LL a[MAXN];
LL mem[MAXN][2];
bool flag[MAXN][2];
LL n;
LL search(int pos, int dir) {
    if (mem[pos][dir])
        return mem[pos][dir];
    if (flag[pos][dir]) {
        return mem[pos][dir] = -1;
    }
    flag[pos][dir] = true;
    LL ret = 0;
    if (dir) {
        int t = pos+a[pos];
        if (t <= n) {
            ret = search(t,!dir);
        }
    } else {
        int t = pos-a[pos];
        if (t > 0) {
            ret = search(t,!dir);
        }
    }
    if (ret != -1) {
        ret += a[pos];
    }
    return mem[pos][dir] = ret;
}
int main() {
    scanf("%I64d", &n);
    for (int i = 2; i <= n; ++i)
        scanf("%I64d", a+i);
    for (int i = 2; i <= n; ++i) {
        LL t = search(i,0);
        if (t != -1) {
            t  += i-1;
        }
        printf("%I64d\n", t);
    }
    return 0;
}
