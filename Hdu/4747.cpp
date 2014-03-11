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

const int MAXN = 200005;
int ar[MAXN];
int last[MAXN];
int minpos[MAXN];
typedef long long ll;
int n;
void clear() {
    memset(last,0,sizeof(last));
    memset(minpos,0,sizeof(minpos));
}
void work() {
    ll sum = 0;
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (ar[i] <= n) {
            int px = last[ar[i]];
            last[ar[i]] = i;
            for (int j = ar[i]; j <= n; ++j) {
                if (j > 0) {
                    minpos[j] = min(minpos[j-1],last[j]);
                } else {
                    minpos[j] = last[j];
                }
                if (minpos[j] > px) {
                    sum += minpos[j]-px;
                } else
                    break;
            }
        }
        ans += sum;
    }
    printf("%I64d\n", ans);
}
bool load() {
    if (EOF == scanf("%d", &n) || 0 == n)
        return false;
    for (int i = 1; i <= n; ++i)
        scanf("%d", ar+i);
    return true;
}
int main(int argc, char const *argv[]) {
    while (load()) {
        work();
        clear();
    }
    return 0;
}