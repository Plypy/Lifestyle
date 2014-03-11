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

const int MAXD = 6;
const int MAXS = (1<<MAXD);
const int MAXN = 60006;
int n, d, m;
int ptc[MAXN][MAXD];
multiset<int> table[MAXS];
void clear() {
    for (int i = 0; i < MAXS; ++i)
        table[i].clear();
}

int eval(int ar[], int s) {
    int ret = 0;
    for (int k = 0; k < d; ++k) {
        if ((1<<k) & s)
            ret += ar[k];
        else
            ret -= ar[k];
    }
    return ret;
}
void work() {
    for (int i = 1; i <= n; ++i) {
        int od;
        scanf("%d", &od);
        if (0 == od) {
            for (int j = 0; j < d; ++j)
                scanf("%d", &ptc[i][j]);
            for (int j = 0; j < m; ++j) {
                int s = eval(ptc[i],j);
                table[j].insert(s);
            }
        } else {
            int num;
            scanf("%d", &num);
            for (int j = 0; j < m; ++j) {
                int s = eval(ptc[num],j);
                multiset<int>::iterator itr = table[j].find(s);
                table[j].erase(itr);
            }
        }
        int ans = 0;
        for (int i = 1; i < m; ++i)
            ans = max(ans,*(--table[i].end())-*(table[i].begin()));
        printf("%d\n", ans);
    }
}

bool load() {
    if (EOF == scanf("%d%d", &n, &d))
        return false;
    m = (1<<d);
    return true;
}
int main(int argc, char const *argv[]) {
    while (load()) {
        work();
        clear();
    }
    return 0;
}