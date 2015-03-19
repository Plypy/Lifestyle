/**
 * Description:
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
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    while (b) {
        ll c = a;
        a = b;
        b = c%b;
    }
    return a;
}

int dig(ll num) {
    if (0 == num) {
        return 1;
    }
    int ret = floor(log10(num))+1;
    return ret;
}

struct Frac {
    ll a, b;
    Frac(ll a, ll b): a(a), b(b) {}

    void simplify() {
        ll div = gcd(a,b);
        a /= div;
        b /= div;
    }

    Frac operator+=(const Frac& t) {
        a =  a*t.b+t.a*b;
        b *= t.b;
        simplify();
        return *this;
    }

    Frac operator*=(const ll t) {
        a *= t;
        simplify();
        return *this;
    }

    friend ostream& operator<<(ostream& os, Frac& t) {
        if (1 == t.b) {
            os << t.a;
            return os;
        }
        ll div = t.a/t.b;
        ll rem = t.a%t.b;

        int sp = dig(div)+1;
        string space = string(sp, ' ');

        int len = dig(t.b);
        string line = string(len, '-');

        os << space << rem << endl;
        os << div << ' ' << line << endl;
        os << space << t.b;
        return os;
    }
};

int main() {
    int n;
    while (cin >> n) {
        Frac ans(1,1);
        for (int i = 2; i <= n; ++i) {
            ans += Frac(1,i);
        }
        ans *= n;
        cout << ans << endl;
    }
}
