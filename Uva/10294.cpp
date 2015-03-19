/**
 * Description: Polya counting problem
 * ProblemName:
 * Source: UVA
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
using namespace std;

typedef long long ll;
ll n, k;

ll gcd(ll a, ll b) {
    while (b) {
        ll c = a;
        a = b;
        b = c%b;
    }
    return a;
}

ll power(ll base, ll exp) {
    ll ret = 1;
    for (ll tmp = base; exp; exp >>= 1) {
        if (exp&1) {
            ret *= tmp;
        }
        tmp *= tmp;
    }
    return ret;
}

int main() {
    while (cin >> n >> k) {
        ll ans1 = 0;
        ll ans2 = 0;

        // just rotation
        for (int i = 1; i <= n; ++i) {
            int exp = gcd(i,n);
            ans1 += power(k,exp);
        }
        ans2 = ans1;
        ans1 /= n;

        if (n&1) {
            ll tmp = power(k,n/2+1);
            ans2 += n*tmp;
            ans2 /= 2*n;
        } else {
            ll tmp = power(k,n/2+1);
            ans2 += (n/2)*tmp;
            tmp = power(k,n/2);
            ans2 += (n/2)*tmp;
            ans2 /= 2*n;
        }
        cout << ans1 << ' ' << ans2 <<  endl;
    }
}
