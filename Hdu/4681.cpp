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


const int MAXN = 1005;

char a[MAXN], b[MAXN], c[MAXN];
int lcs1[MAXN][MAXN], lcs2[MAXN][MAXN];
int st1[MAXN][MAXN], st2[MAXN][MAXN];
int n, m, k;
void init() {
    memset(lcs1,0,sizeof(lcs1));
    memset(lcs2,0,sizeof(lcs2));
    memset(st1,0,sizeof(st1));
    memset(st2,0,sizeof(st2));
}
int work() {
    n = strlen(a);
    m = strlen(b);
    k = strlen(c);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            lcs1[i][j] = max(lcs1[i-1][j],lcs1[i][j-1]);
            if (a[i-1] == b[j-1])
                lcs1[i][j] = max(lcs1[i][j],lcs1[i-1][j-1]+1);

        }
    for (int i = n; i; --i)
        for (int j =m; j; --j) {
            lcs2[i][j] = max(lcs2[i+1][j],lcs2[i][j+1]);
            if (a[i-1] == b[j-1])
                lcs2[i][j] = max(lcs2[i][j],lcs2[i+1][j+1]+1);
        }
    for (int i = 0; i <= n; ++i)
        st1[i][0] = i;
    for (int i = 1; i <= k; ++i)
        st1[0][i] = -1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= k; ++j) {
            if (a[i-1] == c[j-1])
                st1[i][j] = st1[i-1][j-1];
            else
                st1[i][j] = st1[i-1][j];
        }
    for (int i = 0; i <= m; ++i)
        st2[i][0] = i;
    for (int i = 1; i <= k; ++i)
        st2[0][i] = -1;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= k; ++j) {
            if (b[i-1] == c[j-1])
                st2[i][j] = st2[i-1][j-1];
            else
                st2[i][j] = st2[i-1][j];
        }
    int ret = 0;
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j) {
            if (st1[i][k] != -1 && st2[j][k] != -1) {
                int a = st1[i][k], b = st2[j][k];
                ret = max(ret,k+lcs1[a][b]+lcs2[i+1][j+1]);
            }
        }
    return ret;
}
void load() {
    scanf("%s%s%s", a, b, c);
}
int main(int argc, char const *argv[]) {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        load();
        init();
        printf("Case #%d: %d\n", i, work());
    }
    return 0;
}