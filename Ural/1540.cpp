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
const int MAXK = 55;

int sg[MAXK][MAXN][MAXN];
int ar[MAXK][MAXN];
int n;

int dp(int kth, int l, int r);

int pick(int kth, int l, int r, int id) {
    int ret = 0;
    int last = 0;
    int pivot = ar[kth][id];
    for (int i = l; i <= r+1; ++i) {
        if (pivot >= ar[kth][i] || i == r+1) {
            if (last) {
                ret ^= dp(kth, last, i-1);
                last = 0;
            }
            continue;
        }
        if (!last) {
            last = i;
        }
    }
    return ret;
}

int mex(int *mem) {
    int i = 0;
    while (mem[i]) {
        ++i;
    }
    return i;
}

int dp(int kth, int l, int r) {
    if (-1 != sg[kth][l][r]) {
        return sg[kth][l][r];
    }
    int mem[MAXN] = {0};
    for (int i = l; i <= r; ++i) {
        int tsg = pick(kth, l, r, i);
        mem[tsg] = 1;
    }
    return sg[kth][l][r] = mex(mem);
}

void work() {
    memset(sg, -1, sizeof(sg));
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= ar[i][0]; ++j) {
            sg[i][j][j] = 1;
        }
        ans ^= dp(i, 1, ar[i][0]);
    }
    if (ans == 0) {
        printf("S\n");
        return;
    }
    for (int i = 1; i <= n; ++i) {
        int tans = ans^sg[i][1][ar[i][0]];
        for (int j = 1; j <= ar[i][0]; ++j) {
            int nsg = pick(i,1,ar[i][0],j);
            if (0 == (tans^nsg)) {
                printf("G\n%d %d\n", i, j);
                return ;
            }
        }
    }
}

void load() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", ar[i]);
        for (int j = 1; j <= ar[i][0]; ++j) {
            scanf("%d", ar[i]+j);
        }
    }
}

int main() {
    load();
    work();
}
