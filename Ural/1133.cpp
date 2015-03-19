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
#include <bitset>
#include <stack>
using namespace std;
const int BD = 2e9;

typedef long long ll;

ll a, fa, b, fb, n;

bool check(ll fa1) {// smaller true
    ll t1 = fa, t2 = fa1;
    for (int i = 2; a+i <= b; ++i) {
        ll t3 = t1+t2;
        if (t3 > BD) {
            return false;
        }
        if (t3 < -BD) {
            return true;
        }
        t1 = t2;
        t2 = t3;
    }
    return t2 <= fb;
}

int main() {
    cin >> a >> fa >> b >> fb >> n;
    if (a > b) {
        swap(a,b);
        swap(fa,fb);
    }
    ll l = -2e9;
    ll r = -l+1;
    while (l+1 < r) {
        ll m = (l+r)>>1;
        if (check(m)) {
            l = m;
        } else {
            r = m;
        }
    }
    ll fa1 = l;
    if (n > a) {
        ll t1 = fa, t2 = fa1;
        for (int i = 2; a+i <= n; ++i) {
            ll t3 = t1+t2;
            t1 = t2;
            t2 = t3;
        }
        cout << t2 << endl;
    } else {
        ll t1 = fa, t2 = fa1;
        for (int i = 1; a-i >= n; --i) {
            ll t3 = t2-t1;
            t2 = t1;
            t1 = t3;
        }
        cout << t1 << endl;
    }
}
