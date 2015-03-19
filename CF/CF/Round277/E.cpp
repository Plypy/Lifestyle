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
#include <bitset>
#include <stack>
using namespace std;

const int MAXN = 1005;
int N, L;
int pic[MAXN];
double pos[MAXN];
double dis[MAXN];
double g[MAXN][MAXN];
int pre[MAXN];
const double INF = 1e10;

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> L;
    for (int i = 1; i <= N; ++i) {
        cin >> pos[i] >> pic[i];
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < i; ++j) {
            g[j][i] = g[i][j] = sqrt(abs(pos[i]-pos[j]-L));
        }
    }

    double l = 0, r = INF;
    int T = 100;
    while (T--) {
        double mid = (l+r)/2;
        for (int i = 1; i <= N; ++i) {
            dis[i] = INF;
            for (int j = 0; j < i; ++j) {
                double len = g[j][i]-mid*pic[i];
                if (dis[i] > dis[j]+len) {
                    dis[i] = dis[j]+len;
                    pre[i] = j;
                }
            }
        }
        if (dis[N] < 0) {
            r = mid;
        } else {
            l = mid;
        }
    }
    int p = N;
    vector<int> ans;
    while (p) {
        ans.push_back(p);
        p = pre[p];
    }
    for (int i = ans.size()-1; i >= 0; --i) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}
