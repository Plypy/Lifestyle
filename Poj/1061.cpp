/**
 * Description: find the minimum k that (x+k*n) - (y+k*m) = k'*L
 * ProblemName:
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
#include <vector>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <stack>
using namespace std;
typedef long long ll;

ll exgcd(ll a, ll b, ll &x, ll &y) {
    // cout << a << ' ' << b << " in gcd" << endl;
    if (0 == b) {
        x = 1, y = 0;
        return a;
    }
    ll ret = exgcd(b, a%b, y, x);
    y -= x*(a/b);
    return ret;
}

bool solve(ll a, ll b, ll c, ll &x, ll &y) {// minimize x, maxmize y
    ll gd = exgcd(a,b,x,y);
    if (0 != c%gd) {
        return false;
    }
    x *= c/gd;
    y *= c/gd;
    ll t = x / (b/gd);
    x -= t*(b/gd);
    y += t*(a/gd);
    if (x < 0) {
        x += b/gd;
        y -= a/gd;
    }
    return true;
}

int main() {
    ll x, y, n, m, l;
    cin >> x >> y >> n >> m >> l;
    ll k1, k2;
    bool flag = solve(m-n, l, x-y, k1, k2);
    if (flag) {
        // cout << k1 << ' ' << k2 << endl;
        cout << k1 << endl;
    } else {
        cout << "Impossible" << endl;
    }
}
