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

const int MAXN = 105;
int anslist[MAXN][MAXN];
int used[MAXN][MAXN];
int n, m;

void inc(int &a) {
    ++a;
    if (a > n)
        a = 1;
}
int main() {
    while (EOF != scanf("%d%d", &n, &m)) {
        memset(used,0,sizeof(used));
        int cur = 0;
        for (int i = 1; i <= m; ++i) {
            inc(cur);
            anslist[i][1] = cur;
            used[i][cur] = true;
        }
        for (int i = 1; i <= n; ++i) {
            int buf = cur;
            for (int j = 1; j <= m; ++j) {
                if (anslist[j][1] == i) {
                    inc(buf);
                    if (i == buf)
                        inc(buf);
                    anslist[j][2] = buf;
                    used[j][buf] = true;
                }
            }
        }

        for (int i = 1; i <= m; ++i) {
            int k = 3;
            for (int j = 1; j <= n; ++j) {
                if (!used[i][j])
                    anslist[i][k++] = j;
            }
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                printf("%d", anslist[i][j]);
                if (j != n)
                    printf(" ");
                else
                    puts("");
            }
        }
    }
}