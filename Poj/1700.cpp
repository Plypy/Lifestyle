/**
 * Description: Classic crossing river problem
 * Source: POJ 1700
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
const int INF = 0x3f3f3f3f;
int n;
int ar[MAXN];
int dp[MAXN];
int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", ar+i);
        sort(ar,ar+n);
        for (int i = 1; i <= n; ++i) {
            dp[i] = INF;
        }
        dp[0] = ar[0];
        dp[1] = ar[1];
        for (int j = 2; j < n; ++j) {
            int a = dp[j-1]+ar[j]+ar[0];
            int b = dp[j-2]+ar[j]+ar[0]+ar[1]*2;
            dp[j] = min(a,b);
        }
        printf("%d\n", dp[n-1]);
    }
}