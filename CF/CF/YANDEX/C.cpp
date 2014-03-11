/**
 * Description:
 * Author: Ply_py
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iomanip>
#include <queue>
#include <cmath>
using namespace std;
typedef long long LL;

LL n;
LL get(LL a) {
    if (3 == a%4)
        return 0;
    LL t = 4*(a/4);
    LL ret = 0;
    for (LL i = t; i <= a; ++i)
        ret ^= i;
    return ret;
}
void check(LL a) {
    LL t = 0;
    for (LL i = 1; i <= a; ++i) {
        t ^= i;
        if (t != get(i))
            cout << "fucked" << endl;
    }
    cout << "end" << endl;
}
LL get2(LL a) {
    LL take = get(a);
    if (1 == take) {
        return (a+1)/2;
    }
    LL p;
    for (p = 1; (p<<1) <= take; p <<= 1)
        continue;
    return a-p+1;
}
LL get3(LL a) {
    LL take = get(a);
    int ret = 0;
    for (int i = 1; i <= a; ++i) {
        int t = i^take;
        if (t < i)
            ++ret;
    }
    return ret;
}
void check2(LL a) {
    for (int i = 1; i <= a; ++i) {
        if (get(i)) {
            cout << get(i) << endl;
            cout << i << ' ' << get2(i) << ' ' << get3(i) << endl;
        }
    }
}
int main() {
    cin >> n;
    LL ans1 = n*(n+1)/2;
    LL ans2 = 0;
    LL take = get(n);
    if (0 == take)
        ans2 = 0;
    else {
        ans2 = get2(n);
    }
    cout << ans1 << ' ' << ans2 << endl;
    return 0;
}
