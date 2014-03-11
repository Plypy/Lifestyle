/**
 * Description: Computing the gcd of two polynomial
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

const int MAXN = 15;
typedef long long ll;
ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b,a%b);
}
struct Poly {
    ll n;
    ll coef[MAXN];
    Poly operator%(const Poly &t) const {
        Poly ret = *this;
        while (ret.n >= t.n) {
            ll hc = ret.coef[ret.n];
            ll shift = ret.n-t.n;
            for (ll i = 0; i <= ret.n; ++i) {
                ret.coef[i] *= t.coef[t.n];
            }
            for (ll i = 0; i <= t.n; ++i) {
                ret.coef[i+shift] -= t.coef[i]*hc;
            }
            while (ret.n >= 0 && ret.coef[ret.n] == 0)
                --ret.n;
        }
        ll d = 0;
        for (ll i = 0; i <= ret.n; ++i)
            if (ret.coef[i])
                d = gcd(d,ret.coef[i]);
        if (d)
            for (ll i = 0; i <= ret.n; ++i)
                ret.coef[i] /= d;
        return ret;
    }
    friend istream &operator>>(istream &is, Poly &t) {
        memset(t.coef,0,sizeof(t.coef));
        is >> t.n;
        for (ll i = 0; i <= t.n; ++i)
            is >> t.coef[t.n-i];
        return is;
    }
    friend ostream &operator<<(ostream &os, const Poly &t) {
        if (-1 == t.n) {
            os << 0 << endl;
            return os;
        }
        for (ll i = 0; i <= t.n; ++i)
            os << t.coef[t.n-i] << ' ';
        os << endl;
        return os;
    }
};
Poly gcd(const Poly &a, const Poly &b) {
    // cout << a << b;
    if (b.n == -1)
        return a;
    return gcd(b,a%b);
}

int main(int argc, char const *argv[]) {
    ll k;
    cin >> k;
    for (ll i = 0; i < k; ++i) {
        Poly a, b;
        cin >> a;
        b.n = a.n-1;
        for (ll i = 0; i < a.n; ++i)
            b.coef[i] = (i+1)*a.coef[i+1];
        Poly t = gcd(a,b);
        // cout << endl <<  t << t.n << endl;
        if (t.n == 0)
            cout << "Yes!\n";
        else
            cout << "No!\n";
    }
    return 0;
}

