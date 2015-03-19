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
#include <map>
#include <vector>
#include <queue>
#include <ctime>
#include <set>
#include <iomanip>
#include <algorithm>
using namespace std;
const int MAXN = 1005;
int n;
double a[MAXN], b[MAXN];
int i, j;
int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    int ans1 = 0, ans2 = 0;
    for (int t = 1; t <= T; ++t) {
        scanf("%d", &n);
        for (i = 1; i <= n; ++i)
            scanf("%lf", a+i);
        for (i = 1; i <= n; ++i)
            scanf("%lf", b+i);
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);


        j = 1;
        int ct = 0;
        for (i = 1; i <= n; ++i) {
            while (j != n+1 && b[j] < a[i])
                ++j;
            if (j == n+1)
                break;
            ++j;
            ++ct;
        }
        ans2 = n-ct;

        i = 1;
        ct = 0;
        for (j = 1; j <= n; ++j) {
            while (i != n+1 && a[i] < b[j])
                ++i;
            if (i == n+1)
                break;
            ++i;
            ++ct;
        }
        ans1 = ct;

        printf("Case #%d: %d %d\n", t, ans1, ans2);
    }
    return 0;
}