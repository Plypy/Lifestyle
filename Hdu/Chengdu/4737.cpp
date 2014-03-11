/**
 * Description:
 * Source:
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

typedef long long lld;

int n, m;
const int MAXN = 100005;
int ar[MAXN];
lld work() {
    lld ret = 0;
    for (int i = 1; i <= n; ++i) {
        int tmp = 0;
        for (int j = i; j <= n && (tmp|ar[j]) < m; ++j) {
            tmp |= ar[j];
            ++ret;
        }
    }
    return ret;
}
void load() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", ar+i);
    }
}
int main(int argc, char const *argv[]) {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        load();
        printf("Case #%d: %lld\n", i, work());
    }
    return 0;
}