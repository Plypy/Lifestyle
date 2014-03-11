#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef long long LL;
const int MAXN = 200005;
LL a[MAXN];
LL cthelp[MAXN], ct[MAXN];
LL n, q;
LL ans;
bool cmp(const int &A, const int &B) {
    return A>B;
}
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= q; ++i) {
        int l, r;
        cin >> l >> r;
        ++cthelp[l], --cthelp[r+1];
    }
    sort(a+1, a+n+1, cmp);
    LL cter = 0;
    for (int i = 1; i <= n; ++i) {
        cter += cthelp[i];
        ct[i] = cter;
    }
    sort(ct+1,ct+n+1,cmp);
    for (int i = 1; i <= n; ++i)
        ans += ct[i]*a[i];
    cout << ans << endl;
    return 0;
}
