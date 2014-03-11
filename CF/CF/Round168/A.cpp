#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <iomanip>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL MAXN = 100005;
LL n, k;
LL a[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (LL i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a+1, a+n+1);
    LL ans = 0;
    set<LL> del;
    for (LL i = 1; i <= n; ++i) {
        if (del.find(a[i]) == del.end()) {
            ++ans;
            del.insert(a[i]*k);
        }
    }
    cout << ans << endl;
    return 0;
}
