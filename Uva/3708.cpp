/**
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

const int MAXN = 1005;

int n, m;

int main() {
    cout << fixed << setprecision(6);
    while (cin >> n >> m) {
        double ans = 0;
        for (int i = 1; i < n; ++i) {
            double pos = double(i)/n*(n+m);
            ans += abs(pos-floor(pos+0.5));
        }
        cout << ans*10000/(n+m) << endl;
    }
    return 0;
}
