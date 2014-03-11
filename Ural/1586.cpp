#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int MODULE = 1000000009;
const int MAXN = 10005;
const int BASE = 10;
const int BOUND = 1000;
int pnum;
int dp[2][BASE][BASE];
bool notp[BOUND];
bool isp[BASE][BASE][BASE];
void init() {
    for (int i = 2; i < BOUND; ++i)
        if (!notp[i]) {
            if (i > 100) {
                int p = i;
                int r = p%10;
                p /= 10;
                int q = p%10;
                p /= 10;
                ++dp[3&1][p][q];
                isp[p][q][r] = true;
            }
            for (int j = i*2; j < BOUND; j += i)
                notp[j] = true;
        }
}

int main() {
    init();
    int n;
    cin >> n;
    for (int i = 4; i <= n; ++i) {
        int p = i&1;
        int q = (i-1)&1;
        for (int j = 1; j < BASE; ++j)
            for (int k = 0; k < BASE; ++k) {
                dp[p][j][k] = 0;
                for (int l = 0; l < BASE; ++l)
                    if (isp[j][k][l])
                        dp[p][j][k] = (dp[p][j][k]+dp[q][k][l])%MODULE;
            }
    }
    int ans = 0;
    int p = n&1;
    for (int i = 1; i < BASE; ++i)
        for (int j = 0; j < BASE; ++j)
            ans = (dp[p][i][j]+ans)%MODULE;
    cout << ans << endl;
//    system("pause");
    return 0;
}
