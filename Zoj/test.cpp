#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long ll;
using namespace std;

char str[50];
int len;
char leftnum[50], rightnum[50];
char ans[50];
ll target;

ll getans(int l, int r) {
    ll ans = 0;
    for (int i = 1; i <= l; i++)
        ans = ans * 10 + leftnum[i];
    for (int i = r; i >= 1; i--)
        ans = ans * 10 + rightnum[i];
    return ans;
}
ll dfs(int l, int r, int eq) {
    ll ans = -1;
    if (l + r - 1 >= len) {
        if (l + r - 1 > len)
            return -1ll;
        ans = getans(l - 1, r);
        if (ans < target)
            return ans;
        return -1ll;
    }

    int m = eq ? str[l] : 9;
    for (int i = m; i >= 0; i--) {
        leftnum[l] = i;
        if ((l == 1 || leftnum[l] != leftnum[l - 1]) && !(l == 1 && i == 0) && !(l+r == len)) {
            for (int k = 1; k + r + l <= len; k++) {
                rightnum[r + k] = i;
                ans = max(ans, dfs(l + 1, r + k, eq && (i == m)));
            }
        }
        else ans = max(ans, dfs(l + 1, r, eq && i == m));
        if (ans  > 0 )
            return ans;
    }
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld", &target);
        sprintf(str+1, "%lld", target);
        len = strlen(str+1);
        for (int i = 1; i <= len; i++)
            str[i] -= '0';
        printf("%lld\n", dfs(1, 0, 1));
    }
    return 0;
}
