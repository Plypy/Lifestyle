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
const int MAXD = 30;

int c[MAXD];
inline int lowbit(int a) {
    return a&-a;
}
void ins(int a) {
    while (a < MAXD) {
        ++c[a];
        a += lowbit(a);
    }
}
int get(int a) {
    int ret = 0;
    while (a) {
        ret += c[a];
        a -= lowbit(a);
    }
    return ret;
}
int rank(int a) {
    return get(a-1);
}
void clr() {
    memset(c,0,sizeof(c));
}
void clear() {
}
int n, m, k;
bool check(int a[], int p[], int l) {
    clr();
    for (int i = 0; i < l; ++i) {
        ins(a[i]);
        if (p[i] != rank(a[i]))
            return false;
    }
    return true;
}
int a[MAXN], pat[MAXN];
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
    int ans = 0;
    clr();
    for (int i = 0; i < m; ++i) {
        ins(pat[i]);
        pat[i] = rank(pat[i]);
        // cout << pat[i] << ' ';
    }
    // cout << endl;
    for (int i = 0; i < n-m+1; ) {
        if (check(a+i, pat, m)) {
            // cout << i << endl;
            i += m, ++ans;
        } else
            ++i;
    }
    printf("%d\n", ans);
}

int main(int argc, char const *argv[]) {
    while (load()) {
        work();
    }
    return 0;
}