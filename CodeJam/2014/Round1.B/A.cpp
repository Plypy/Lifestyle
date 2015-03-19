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
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
using namespace std;
const int MAXN = 105;

char str[MAXN][MAXN];
int ptr[MAXN];
int ct[MAXN];
int n;
void init() {
    memset(ptr,0,sizeof(ptr));
    memset(ct,0,sizeof(ct));
    memset(str,0,sizeof(str));
}
bool check() {
    for (int i = 1; i < n; ++i) {
        ct[i] = 0;
        int j = ptr[i];
        while (str[i][j] == str[0][ptr[0]]) {
            ++ct[i];
            ++j;
        }
        ptr[i] = j;
        if (0 == ct[i])
            return false;
    }
    return true;
}
int ar[MAXN];
int calc() {
    for (int i = 0; i < n; ++i) {
        ar[i] = ct[i];
    }
    sort(ar,ar+n);
    int ret = 0;
    int std = ar[n/2];
    for (int i = 0; i < n; ++i) {
        ret += abs(ar[i]-std);
    }
    return ret;
}
void load() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", str[i]);
    }
}
int work() {
    int len = strlen(str[0]);
    int ret = 0;
    ct[0] = 1;
    for (int i = 0; i < len; ++i) {
        if (str[0][i+1] == str[0][i]) {
            ++ct[0];
            continue;
        }
        ptr[0] = i;
        if (!check()) {
            return -1;
        }
        ret += calc();
        ct[0] = 1;
    }
    for (int i = 1; i < n; ++i) {
        if (str[i][ptr[i]])
            return -1;
    }
    return ret;
}
int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        init();
        load();
        int ans = work();
        printf("Case #%d: ", t);
        if (-1 == ans) {
            puts("Fegla Won");
        } else {
            printf("%d\n", ans);
        }
    }
}
