#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef long long LL;

LL L, R;
LL ans;
bool check(LL t) {
    if (t < L)
        return false;
    if (t > R)
        return false;
    return true;
}
void dfs(LL a, LL b, int dep) {
    if (check(a) && check(b)) {
        if (ans < (a^b))
            ans = (a^b);
    }
    if (dep) {
        LL tmp = (1LL << (dep-1));
        LL tmp2 = (tmp<<1)-1;
        LL tmp3 = tmp2>>1;
        if (a+tmp <= R && a+tmp2 >= L && b+tmp3 >= L) {
            dfs(a+tmp,b,dep-1);
            return ;
        }
        if (a+tmp3 >= L && b+tmp <= R && b+tmp2 >= L) {
            dfs(a,b+tmp,dep-1);
            return ;
        }
        if (a+tmp3 >= L && b+tmp3 >= L) {
            dfs(a,b,dep-1);
            return ;
        }
        if (a+tmp <= R && a+tmp2 >= L && b+tmp <= R && b+tmp2 >= L) {
            dfs(a+tmp,b+tmp,dep-1);
            return ;
        }
    }
}
int main() {
    cin >> L >> R;
    dfs(0,0,63);
    cout << ans << endl;
    return 0;
}
