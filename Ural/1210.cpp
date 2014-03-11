// 可以dp也可以转化成最短路
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;
const int MAXN = 35;
const int INF = 0x7ffffff;
int dp[2][MAXN];
int n;
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int t = i&1;
        int u = 1-t;
        cin >> dp[t][0];
        for (int j = 1; j <= dp[t][0]; ++j) {
            dp[t][j] = INF;
            while (true) {
                int a, b;
                cin >> a;
                if (!a)
                    break;
                cin >> b;
                if (dp[u][a]+b < dp[t][j])
                    dp[t][j] = dp[u][a]+b;
            }
        }
        string trash;
        if (i != n)
            cin >> trash;
    }
    int ans = INF;
    for (int i = 1; i <= dp[n&1][0]; ++i) {
        if (ans > dp[n&1][i])
            ans = dp[n&1][i];
    }
    cout << ans << endl;
//    system("pause");
    return 0;
} 
