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

const int MAXN = 15;
const int MAXSUM = 125;
const int Z = 50;

int mem[MAXN][MAXN][MAXSUM][MAXN][MAXN];
int num[MAXN];

int dp(int n, int p, int sum, int inc, int dec, bool limit) {
    if (0 == p) {
        if (sum!=Z && sum-dec<=Z && sum+inc>=Z) {
            return 1;
        }
        return 0;
    }
    int &memo = mem[n][p][sum][inc][dec];
    if (!limit && -1 != memo) {
        return memo;
    }

    int ret = 0;
    int ubd = limit?num[p]:9;
    int lbd = n==p?1:0;
    bool head = 2*p>n;
    for (int i = lbd; i <= ubd; ++i) {
        int nsum = head?sum+i:sum-i;
        int ninc = head?max(inc,9-i):max(inc,i);
        int ndec = head?max(dec,n==p?i-1:i):max(dec,9-i);
        ret += dp(n,p-1,nsum,ninc,ndec,limit&&i==ubd);
    }

    if (!limit) {
        memo = ret;
    }
    return ret;
}

int solve(int bd) {
    if (bd < 0) {
        return 0;
    }
    int len = 0;
    while (bd) {
        num[++len] = bd%10;
        bd /= 10;
    }
    int ret = 0;
    for (int i = 2; i <= len; i += 2) {
        ret += dp(i,i,Z,0,0,i==len);
    }
    return ret;
}

int main() {
    memset(mem, -1, sizeof(mem));
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", solve(b)-solve(a-1));
}
