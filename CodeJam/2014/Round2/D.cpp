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

const int MAXN = 200;

int n,m;
int ans1 = 0, ans2 = 0;

string str[MAXN];

int cnt[MAXN][MAXN];

vector<int> vct[MAXN];

int p[MAXN];

void dfs(int cur) {

    if (cur > n) {
        for (int i = 1; i <= m; ++i)
            vct[i].clear();
        for (int i = 1; i <= n; ++i)
            vct[p[i]].push_back(i);
        for (int i = 1; i <= m; ++i)
            if (vct[i].size() == 0)
                return ;

        int tans = 0;
        for (int i = 1; i <= m; ++i) {
            ++tans;
            for (int j = 1; j <= vct[i].size(); ++j) {
                tans += str[vct[i][j - 1]].length();
                int maxsum = 0;
                for (int k = 1; k <= j-1; ++k)
                    maxsum = max(maxsum,cnt[vct[i][k - 1]][vct[i][j - 1]]);
                tans -= maxsum;
            }
        }
        if (tans > ans1) {
            ans1 = tans; ans2 = 1;
        } else if (tans == ans1) ++ans2;

        return ;
    }
    for (int i = 1; i <= m; ++i) {
        p[cur] = i;
        dfs(cur + 1);
    }
}

int main() {
    int T;
    cin >> T;

    for (int kase = 1; kase <= T; ++kase) {
        cout << "Case #" << kase << ": ";
        // printf("Case #%d: ",kase);
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            cin >> str[i];
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j) {
                cnt[i][j] = min(str[i].length(),str[j].length());
                for (int k = 1; k <= min(str[i].length(), str[j].length()); ++k)
                    if (str[i][k - 1] != str[j][k - 1]) {
                        cnt[i][j] = k - 1; break ;
                    }
        }
        ans1 = 0, ans2 = 0;
        dfs(1);
        cout << ans1 << ' ' << ans2 << endl;
    }
    return 0;
}
