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

const int MAXN = 50005;

int n,k;

double x[MAXN];

void load() {
    cin >> n >> k;
    k = n-k;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
}

double work() {
    if (0 == k || 1 == k) {
        return 0;
    }
    sort(x, x+n);
    double ans = 0;
    double s2 = 0;
    double s = 0;
    for (int i = 0; i < k; ++i) {
        s += x[i];
        s2 += x[i]*x[i];
    }
    ans = s2-s*s/k;
    for (int i = k; i < n; ++i) {
        s += x[i];
        s2 += x[i]*x[i];
        int t = i-k;
        s -= x[t];
        s2 -= x[t]*x[t];
        double tans = s2-s*s/k;
        if (tans < ans) {
            ans = tans;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    int T;
    cin >> T;
    while (T--) {
        load();
        cout << work() << endl;
    }
}
