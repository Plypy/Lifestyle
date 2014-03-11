/**
 * Description: Game Theory. For each pile, its sg value will be the maximum number that use
 * recyle center to split this pile.
 * Source: hdu 4672
 * Author: Ply_py
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
using namespace std;

const int MAXN = 100005;
const int MAXB = 105;
const int MAXV = MAXB*MAXB;
int st[MAXN];
int b[MAXN];
int minb, maxb;
int sg[MAXN];
char p1[MAXN], p2[MAXN];
int n, m;
void work() {
    minb = MAXB;
    maxb = 0;
    for (int i = 1; i <= m; ++i) {
        minb = min(minb,b[i]);
        maxb = max(maxb,b[i]);
    }
    int bd = maxb*maxb;
    memset(sg,-1,sizeof(sg));
    sg[0] = 0;
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j+b[i] <= bd; ++j) {
            if (-1 != sg[j])
                sg[j+b[i]] = max(sg[j+b[i]], sg[j]+1);
        }
    }
    int nim = 0;
    bool flag = 0;
    for (int i = 1; i <= n; ++i) {
        int t = st[i];
        if (t <= bd) {
            if (-1 == sg[t])
                flag = true;
            else
                nim ^= sg[t];
        } else {
            t = (t-bd)%minb;
            t = bd+t-minb;
            if (-1 == sg[t])
                flag = true;
            else
                nim ^= sg[t]+(st[i]-t)/minb;
        }
    }
    if (!flag && nim) {
        puts(p1);
    } else {
        puts(p2);
    }
}
bool load() {
    if (EOF == scanf("%d%d%s%s", &n, &m, p1, p2))
        return false;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", st+i);
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%d", b+i);
    }
    return true;
}
int main(int argc, char const *argv[]) {
    while (load()) {
        work();
    }
    return 0;
}