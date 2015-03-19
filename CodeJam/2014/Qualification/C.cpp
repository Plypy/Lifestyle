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
#include <set>
#include <iomanip>
#include <algorithm>
using namespace std;

const int MAXN = 55;

int n, m, x;
char map[MAXN][MAXN];
// Only check 2 3 5 7, if this works then other will be fine.
bool work() {
    int ct = 0;
    if (1 == x)
        return true;
    if (n == 1 || m == 1) {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) {
                map[i][j] = '.';
                ++ct;
                if (ct == x)
                    return true;
            }
    }
    if (n == 2 || m == 2) {
        if (x == 2)
            return false;
        if (x & 1)
            return false;
        if (m == 2) {
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= m; ++j) {
                    map[i][j] = '.';
                    ++ct;
                    if (ct == x)
                        return true;
                }
        } else {
            for (int i = 1; i <= m; ++i)
                for (int j = 1; j <= n; ++j) {
                    map[j][i] = '.';
                    ++ct;
                    if (ct == x)
                        return true;
                }
        }
    }
    if (2 == x || 3 == x || x == 5 || x == 7)
        return false;
    if (x >= 2*m) {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) {
                map[i][j] = '.';
                ++ct;        ct = 1;
                if (ct == x)
                    return true;
            }
    } else {
        bool flag = false;
        if (x & 1) {
            x -= 3;
            flag = true;
        }
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= 2; ++j) {
                map[j][i] = '.';
                ++ct;
                if (ct == x)
                    goto outside;
            }
        outside:
        if (flag)
            map[3][1] = map[3][2] = map[3][3] = '.';
        return true;
    }
}
int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        memset(map,0,sizeof(map));
        scanf("%d%d%d", &n, &m, &x);
        printf("Case #%d:\n", i);
        x = n*m-x;
        bool flag = work();
        if (!flag) {
            puts("Impossible");
        } else {
            int ct = 0;
            for (int j = 1; j <= n; ++j) {
                for (int k = 1; k <= m; ++k) {
                    if (1 == j && 1 == k) {
                        putchar('c');
                    } else if (map[j][k]) {
                        ++ct;
                        putchar(map[j][k]);
                    } else
                        putchar('*');
                }
                puts("");
            }
            // if (ct+1 != x) {
            //     cerr << ct+1 << ' ' << x << ' ' << n*m << endl;
            //     cerr << "fucked at case " << i << endl;
            // }
        }
    }
    return 0;
}