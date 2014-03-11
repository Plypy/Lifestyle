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

const int MAXK = 35;
vector<int> pos[MAXK];
int n, m, k;
bool check(int a[], int l) {
    int pre = 0;
    for (int i = 1; i <= k; ++i)
        if (pos[i].size()) {
            int len = pos[i].size();
            if (a[pos[i][0]] <= pre)
                return false;
            pre = a[pos[i][0]];
            for (int j = 0; j < len; ++j)
                if (a[pos[i][j]] != pre)
                    return false;
        }
    return true;
}
int a[MAXN];
int pat[MAXN];
vector<int> ans;
void clear() {
    ans.clear();
    for (int i = 1; i <= k; ++i)
        pos[i].clear();
}
bool load() {
    if (EOF == scanf("%d%d%d", &n, &m, &k))
        return false;
    clear();
    for (int i = 0; i < n; ++i)
        scanf("%d", a+i);
    for (int i = 0; i < m; ++i)
        scanf("%d", pat+i);
    return true;
}
void work() {
    for (int i = 0; i < m; ++i) {
        pos[pat[i]].push_back(i);
    }
    for (int i = 0; i < n-m+1; ++i) {
        if (check(a+i,m))
            ans.push_back(i+1);
    }
    int len = ans.size();
    printf("%d\n", len);
    for (int i = 0; i < len; ++i)
        printf("%d\n", ans[i]);
}
int main(int argc, char const *argv[]) {
    while (load()) {
        work();
    }
    return 0;
}