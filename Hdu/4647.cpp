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
double w[MAXN];
int n, m;

void work() {
    double ans = 0;
    sort(w+1,w+n+1);
    for (int i = 1; i <= n; i+=2) {
        ans += w[i+1]-w[i];
    }
    printf("%.0lf\n", ans);
}
bool load() {
    if (EOF == scanf("%d%d", &n, &m))
        return false;
    for (int i = 1; i <= n; ++i)
        scanf("%lf", w+i);
    for (int i = 1; i <= m; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        w[a] += c/2.0;
        w[b] += c/2.0;
    }
    return true;
}
int main(int argc, char const *argv[]) {
    while (load()) {
        work();
    }
    return 0;
}