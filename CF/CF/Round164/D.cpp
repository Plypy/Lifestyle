#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;
const int MAXN = 1001;
const int MAXH = 31;
const int MOD = 1000000009;
inline void add(int &a, const int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
}
int n, h, ans;
int dp[2][2][MAXH][MAXH][MAXH];
int main() {
    cin >> n >> h;
    dp[1][1][1][1][1] = 4;
    for (int t = 1; t < n; ++t) {
        int p = t&1;
        int q = 1^p;
        memset(dp[q],0,sizeof(dp[q]));
        for (int i = 1; i <= h; ++i)
            for (int j = 1; j <= h; ++j)
                for (int k = 1; k <= h; ++k) {
                    for (int s = 0; s < 2; ++s) {
                        int ni = min(h,i+1), nj = min(h,j+1), nk = min(h,k+1);
                        int t = dp[p][s][i][j][k];
                        //d0
                        add(dp[q][s][ni][nj][nk],t);
                        if (s) {
                            //d1
                            add((i<h)?dp[q][1][1][nj][nk]:dp[q][0][1][nj][nk],t);
                            //d2
                            add((j<h)?dp[q][1][1][ni][nk]:dp[q][0][1][ni][nk],t);
                            //d3
                            add((k<h)?dp[q][1][1][ni][nj]:dp[q][0][1][ni][nj],t);
                        } else {
                            //d1
                            add((i<h)?dp[q][1][h][nj][nk]:dp[q][0][h][nj][nk],t);
                            //d2
                            add((j<h)?dp[q][1][h][ni][nk]:dp[q][0][h][ni][nk],t);
                            //d3
                            add((k<h)?dp[q][1][h][ni][nj]:dp[q][0][h][ni][nj],t);
                        }
                    }
                }
    }
    for (int i = 1; i <= h; ++i)
        for (int j = 1; j <= h; ++j)
            for (int k = 1; k <= h; ++k) {
                add(ans,dp[n&1][1][i][j][k]);
                if (i<h || j<h || k<h)
                    add(ans,dp[n&1][0][i][j][k]);
            }
    cout << ans << endl;
    return 0;
}
