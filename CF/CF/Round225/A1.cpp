/**
 * Description: Consider only one pairs of numbers, see their individual cost by the order they are chosen
 *   relatively.
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
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
using namespace std;

const int MAXN = 200005;

int n;
int one[MAXN];
int cnt[MAXN];
int main(int argc, char const *argv[]) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", one+i);
    for (int i = 1; i <= n; ++i) {
        cnt[i] = cnt[i-1]+one[i];
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (!one[i])
            ans += cnt[i];
    }
    printf("%I64d\n", ans);
    return 0;
}