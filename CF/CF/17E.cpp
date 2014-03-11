#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL MAXN = 2000005;
LL n, N;
char s[MAXN*2];
LL len[MAXN*2];
LL st[MAXN], fn[MAXN];
const LL MOD = 51123987;
int main() {
    cin >> n >> (s+1);
    for (int i = n; i; --i)
        s[i+i] = s[i], s[i+i+1] = '#';
    N = 2*n+1;
    s[1] = '#';
    s[0] = '$';
    LL mx = 0, id = 1;
    for (int i = 2; i <= N; ++i) {
        if (mx >= i)
            len[i] = min(len[2*id-i], mx-i);
        while (s[i-len[i]-1] == s[i+len[i]+1])
            ++len[i];
        if (i+len[i]>mx) {
            mx = i+len[i];
            id = i;
        }
    }
    LL tot = 0;
    for (int i = 1; i <= N; ++i) {
        if ((i&1) && !len[i])
            continue;
        LL l = (i-len[i]+1)/2, r = (i+len[i])/2;
        LL tlen = r-l+1, hlen = (tlen+1)/2;
        tot += hlen;
        ++st[l], --st[l+hlen];
        ++fn[r-hlen+1], --fn[r+1];
    }
    tot %= MOD;
    tot = tot*(tot-1)/2%MOD;
    for (int i = 1; i <= n; ++i) {
        st[i] = (st[i]+st[i-1])%MOD;
        fn[i] = (fn[i]+fn[i-1])%MOD;
    }
    LL sfn = 0, ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = (ans+sfn*st[i])%MOD;
        sfn = (sfn+fn[i])%MOD;
    }
    ans = ((tot-ans)%MOD+MOD)%MOD;
    cout << ans << endl;
    return 0;
}
