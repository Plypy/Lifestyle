/**
 * Model: Given n points on a axis, find a point which satisfies that the sum between
 * the point and the given ones is minimum.
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
using namespace std;

const int MAXN = 1000005;
long long n;
long long a[MAXN];
int main() {
    ios::sync_with_stdio(false);
    while (cin >> n) {
        long long m = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            m += a[i];
        }
        m /= n;
        for (int i = 1; i < n; ++i) {
            a[i] = a[i]+a[i-1]-m;
        }
        sort(a,a+n);
        long long p = a[n/2];
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += abs(a[i]-p);
        }
        cout << ans << endl;
    }
}
