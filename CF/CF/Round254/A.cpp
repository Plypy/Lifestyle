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

const int MAXN = 505;

int vval[MAXN];
int ea[MAXN], eb[MAXN], eval[MAXN];
int n, m;

void load() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        cin >> vval[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> ea[i] >> eb[i] >> eval[i];
    }
}

void work() {
    cout << fixed << setprecision(8);
    if (0 == m) {
        cout << 0.0 << endl;
        return ;
    }
    double ans = 0;
    for (int i = 1; i <= m; ++i) {
        double v = vval[ea[i]] + vval[eb[i]];
        double e = eval[i];
        double ta = v/e;
        if (ta > ans) {
            ans = ta;
        }
    }
    cout << ans << endl;
}

int main(int argc, char const *argv[]) {
    load();
    work();
    return 0;
}
