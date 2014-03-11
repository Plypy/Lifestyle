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

typedef long long ll;
ll extend_gcd(ll a, ll b, ll &x, ll &y) {
    if (0 == b) {
        x = 1, y = 0;
        return a;
    } else {
        ll ret = extend_gcd(b,a%b,y,x);
        y -= x*(a/b);
        return ret;
    }
}
ll a, b, c, d;
bool load() {
    cin >> a >> b >> c >> d;
    if (0 == d)
        return false;
    d = (1ll)<<d;
    return true;
}
void work() {
    b = ((b-a)%d+d)%d;

    ll x, y;
    ll gcd = extend_gcd(c, d, x, y);
    // cout << gcd << ' ' << b << endl;
    if (b%gcd) {
        cout << "FOREVER" << endl;
    } else {
        ll mod = d/gcd;
        ll ans = ((b/gcd)*x);
        ans %= mod; ans += mod; ans %= mod;
        cout << ans << endl;
    }
}
int main(int argc, char const *argv[]) {
    while (load()) {
        work();
    }
    return 0;
}