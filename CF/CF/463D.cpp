/**
 * Description: LCM of K string with a small K (2~5)
 * ProblemName:
 * Source: Codeforces
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

const int MAXN = 1005;
const int MAXK = 7;

int pos[MAXK][MAXN];
int ar[MAXK][MAXN];
int n, k;
int dp[MAXN];

bool check(int a, int b) {
    for (int i = 2; i <= k; ++i) {
        if (pos[i][a] < pos[i][b]) {
            return false;
        }
    }
    return true;
}
int main() {
    cin >> n >> k;
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> ar[i][j];
        }
    }
    for (int i = 2; i <= k; ++i) {
        for (int j = 1; j <= n; ++j) {
            int t = ar[i][j];
            pos[i][t] = j;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i] = 1;
        for (int j = 1; j < i; ++j) {
            if (check(ar[1][i],ar[1][j])) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}
