
/**
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
using namespace std;
const int MAXN = 1005;
struct Data {
    int b, j;
    bool operator<(const Data &a) const {
        return j>a.j;
    }
} data[MAXN];

int main() {
    for (int t = 1; true; ++t) {
        int n;
        scanf("%d", &n);
        if (n == 0)
            break;
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &data[i].b, &data[i].j);
        }
        sort(data+1,data+n+1);
        int p = 0;
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            p += data[i].b;
            ans = max(p+data[i].j,ans);
        }
        printf("Case %d: %d\n", t, ans);
    }
    return 0;
}
