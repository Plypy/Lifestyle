#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 10005;
const int MAXM = 55;
int n, m;
int k[MAXM];
bool dp[MAXN];
const bool WIN = false;
const bool LOSE = true;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
        cin >> k[i];
    sort(k+1,k+m+1);
    for (int i = 1; i <= n; ++i) {
        dp[i] = LOSE;
        for (int j = 1; j <= m && k[j] <= i; ++j)
            if (LOSE == dp[i-k[j]]) {
                dp[i] = WIN;
                break;
            }
    }
    if (WIN == dp[n])
        cout << 1 << endl;
    else
        cout << 2 << endl;
//    system("pause");
    return 0;
}
