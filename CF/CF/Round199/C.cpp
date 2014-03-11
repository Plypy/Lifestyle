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
ll r, h;
ll ans;
ll sqr(ll x) {
    return x*x;
}
int main() {
    cin >> r >> h;
    r <<= 1;
    h <<= 1;
    ll hr = r/2;
    ll tmp = (h-hr)/r;
    ans = 2*tmp;
    int d = 0;
    if (h >= hr) {
        d = 1;
        ans += 2;
    }
    ll x1 = hr*d;
    ll y1 = hr*d+tmp*r;
    ll x2 = r;
    ll y2 = h+r-hr;
    if (sqr(x1-x2)+sqr(y1-y2) > sqr(r)) {
        ++ans;
    }
    cout << ans << endl;
    return 0;
}