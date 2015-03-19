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

int check(int a, int b) {
    int c = a^b;
    int ret = 0;
    while (c) {
        if (c&1) {
            ++ret;
        }
        c >>= 1;
    }
    return ret;
}
int n, m, k;
const int MAXN = 1005;
int ar[MAXN];
int main() {
    cin >> n >> m >> k;
    ++m;
    for (int i = 1; i <= m; ++i) {
        cin >> ar[i];
    }
    int ans = 0;
    for (int i = 1; i < m; ++i) {
        if (k >= check(ar[i], ar[m])) {
            ++ans;
        }
    }
    cout << ans << endl;
}
