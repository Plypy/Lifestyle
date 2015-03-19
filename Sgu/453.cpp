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

typedef long long ll;
ll l, u, v, t;

ll gcd(ll a, ll b) {
    ll c;
    while (b) {
        c = b;
        b = a%b;
        a = c;
    }
    return a;
}


int main() {
    // cout << -1/2 << endl;
    cin >> l >> u >> v >> t;
    if (u < v) {
        swap(u,v);
    }
    ll ans1 = t*(u+v)-l;
    ll ans2 = t*(u-v)-l;
    ans1 = ans1/(2*l)+(ans1>=0);
    ans2 = ans2/(2*l)+(ans2>=0);
    if (u == v) {
        cout << ans1 << endl;
        return 0;
    }
    ll gc = gcd(u,v);
    double t1 = 1.0*l/gc;
    ll nt = (u-v)/gc;
    ll cnt = 0;
    if (nt&1) {
        if (t >= t1) {
            cnt = (t-t1)/(2*t1)+1;
        }
    }
    ll ans = ans1+ans2-cnt;
    cout << ans << endl;
    return 0;
}
