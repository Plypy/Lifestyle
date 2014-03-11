/**
 * Description:
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
#include <map>
#include <vector>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
using namespace std;
const int MAXN = 1005;
const int MAXL = MAXN<<1;
int ar[MAXL];
int n;
int dp[MAXL][MAXL];
void work() {
    int l = n<<1;
    for (int i = 1; i <= l; ++i) {
        dp[i][i] = 1;
    }
    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i+len-1 <= l; ++i) {
            int j = i+len-1;
            dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            if (ar[i] == ar[j]) {
                dp[i][j] = max(dp[i][j],dp[i+1][j-1]+2);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int t = max(dp[i][i+n-1], dp[i][i+n-2]+1);
        ans = max(ans,t);
    }
    printf("%d\n", ans);
}
void clear() {
    memset(dp,0,sizeof(dp));
}
bool load() {
    clear();
    scanf("%d", &n);
    if (0 == n)
        return false;
    for (int i = 1; i <= n; ++i) {
        int a;
        scanf("%d", &a);
        ar[i] = ar[i+n] = a;
    }
    return true;
}
int main(int argc, char const *argv[]) {
    while (load()) {
        work();
    }
    return 0;
}