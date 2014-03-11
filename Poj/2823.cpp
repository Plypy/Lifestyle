/**
 * Description: Simple monotone queue's use
 * Author: Ply_py
 */
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
#include <cmath>
using namespace std;
const int MAXN = 1000005;
int a[MAXN];
int n, k;
int que[MAXN], st, ed;
int pos[MAXN];
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a+i);
    st = 1;
    for (int i = 1; i <= n; ++i) {
        while (st <= ed && que[ed] > a[i])
            --ed;
        que[++ed] = a[i];
        pos[ed] = i;
        if (pos[st]+k <= i)
            ++st;
        if (i >= k)
            printf("%d ", que[st]);
    }
    puts("");
    st = 1;
    ed = 0;
    for (int i = 1; i <= n; ++i) {
        while (st <= ed && que[ed] < a[i])
            --ed;
        que[++ed] = a[i];
        pos[ed] = i;
        if (pos[st]+k <= i)
            ++st;
        if (i >= k)
            printf("%d ", que[st]);
    }
    puts("");

    return 0;
}
