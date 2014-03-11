/**
 * Description: Finding rule~
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
ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b,a%b);
}
ll lcm(ll a, ll b) {
    return a*b/gcd(a,b);
}
ll calc(int a, int b, int n) {
    ll x = 0, y = 0, i = 0;
    ll ret = 0;
    while (i < n) {
        ll t = min(a-x,b-y);
        if (i+t > n)
            t = n-i;
        ret += t*abs(x-y);
        x = (x+t)%a;
        y = (y+t)%b;
        i += t;
    }
    return ret;
}
int main(int argc, char const *argv[]) {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, a, b;
        scanf("%d%d%d", &n, &a, &b);
        ll m = lcm(a,b);
        ll ans = 0;
        if (m >= n)
            ans = calc(a,b,n);
        else {
            ans = calc(a,b,m)*(n/m)+calc(a,b,n%m);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}