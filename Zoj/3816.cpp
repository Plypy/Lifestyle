/**
 * Description:
 * ProblemName:
 * Source: 2014 MuDanJiang Online contest
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


typedef long long ll;
const int MAXN = 35;

ll N;
int len;
char str[MAXN];
int lnum[MAXN], rnum[MAXN];

ll get(int l, int r) {
    ll ret = 0;
    for (int i = 1; i <= l; ++i) {
        ret = ret*10 + lnum[i];
    }
    for (int i = r; i; --i) {
        ret = ret*10 + rnum[i];
    }
    return ret;
}

ll dfs(int l, int r, bool flag) {
    ll ret = -1;
    if (l+r-1 >= len) {
        if (l+r-1 > len) {
            return -1;
        }
        ret = get(l-1,r);
        if (ret < N) {
            return ret;
        }
        return -1;
    }

    int tmp = flag?str[l]:9;
    for (int i = tmp; i >= 0; --i) {
        lnum[l] = i;
        if ((l == 1 || lnum[l] != lnum[l-1]) && !(l==1 && i == 0) && !(l+r == len)) {
            for (int k = 1; k+r+l <= len; ++k) {
                rnum[r+k] = i;
                ret = max(ret, dfs(l+1, r+k, flag && i==str[l]));
            }
        } else {
            ret = max(ret, dfs(l+1, r, flag && i==str[l]));
        }
        if (ret > 0) { // itreate from high to low, return the largest directly
            return ret;
        }
    }
    return ret;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld", &N);
        sprintf(str+1, "%lld", N);
        len = strlen(str+1);
        for (int i = 1; i <= len; ++i) {
            str[i] -= '0';
        }
        printf("%lld\n", dfs(1, 0, true));
    }
}
