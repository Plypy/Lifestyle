/**
 * Description:
 * Author: Ply_py
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iomanip>
#include <queue>
#include <cmath>
using namespace std;
const int MAXN = 2005;
int n, m, k;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool used[MAXN][MAXN];
struct Pt {
    int x, y;
    Pt(int x = 0, int y = 0): x(x), y(y) { }
} ;
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while (cin >> n >> m >> k) {
        memset(used,0,sizeof(used));
        for (int i = 0; i <= m; ++i) {
            used[0][i] = used[n+1][i] = true;
        }
        for (int i = 0; i <= n; ++i) {
            used[i][0] = used[i][m+1] = true;
        }

        queue<Pt> que;
        while (k--) {
            int a, b;
            scanf("%d%d", &a, &b);
            que.push(Pt(a,b));
            used[a][b] = true;
        }
        int ansx = 0, ansy = 0;
        while (que.size()) {
            Pt t = que.front();
            ansx = t.x;
            ansy = t.y;
            que.pop();

            for (int i = 0; i < 4; ++i) {
                int tx = t.x+dx[i], ty = t.y+dy[i];
                if (!used[tx][ty]) {
                    used[tx][ty] = true;
                    que.push(Pt(tx,ty));
                }
            }
        }
        cout << ansx << ' ' << ansy << endl;
    }
    return 0;
}
