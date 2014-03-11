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
#include <climits>
using namespace std;
typedef long long LL;
const int MAXN = 300005;
LL ans;
int a[MAXN];
int n;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a+i);
    }
    sort(a+1,a+n+1);
    for (int i = 1; i <= n; ++i) {
        ans += abs(i-a[i]);
    }
    printf("%I64d\n", ans);
    return 0;
}
