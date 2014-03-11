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

const int MAXN = 100005;
int ct[MAXN][3];
char s[MAXN];
int num[4];
int main(int argc, char const *argv[]) {
    gets(s+1);
    int n, m;
    scanf("%d", &m);
    n = strlen(s+1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 3; ++j) {
            ct[i][j] = ct[i-1][j];
        }
        ++ct[i][s[i]-'x'];
    }
    while (m--) {
        int l, r;
        scanf("%d%d", &l, &r);
        for (int j = 0; j < 3; ++j)
            num[j] = ct[r][j]-ct[l-1][j];
        int mx = *max_element(num, num+3);
        int mn = *min_element(num, num+3);
        if (r-l < 2 || mx-mn <= 1)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
