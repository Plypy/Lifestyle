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


typedef long long lld;
const int MAXN = 15;
const int MAXF = (1<<9)*9;
int f[MAXN][MAXF];
int ans;

int bs[MAXN], len;
int a, b;
void dfs(int n, int v) {
    if (0 == n) {
        ans += f[n][v];
        return ;
    }
    int mult = (1<<(n-1));
    for (int i = 0; i < bs[n]; ++i) {
        if (v<i*mult)
            break;
        ans += f[n-1][v-i*mult];
    }
    if (v>=bs[n]*mult)
        dfs(n-1,v-bs[n]*mult);
}
void clear() {
    len = ans = 0;
}
void init() {
    for (int i = 0; i < MAXF; ++i)
        f[0][i] = 1;
    int mult = 1;
    for (int i = 1; i <= 9; ++i) {
        int bd = (1<<i)-1;
        bd *= 9;
        for (int j = 0; j <= bd; ++j) {
            for (int k = 0; k <= 9 && j>=k*mult; ++k) {
                f[i][j] += f[i-1][j-k*mult];
            }
        }
        for (int j = bd+1; j < MAXF; ++j)
            f[i][j] = f[i][bd];
        mult <<= 1;
    }
}
int work() {
    while (b) {
        bs[++len] = b%10;
        b /= 10;
    }
    int w = 0;
    int d = 1;
    while (a) {
        int t = a%10;
        a /= 10;
        w += t*d;
        d *= 2;
    }
    dfs(len,w);
    return ans;
}
void load() {
    scanf("%d%d", &a, &b);
}
int main(int argc, char const *argv[]) {
    int T;
    scanf("%d", &T);
    init();
    for (int i = 1; i <= T; ++i) {
        load();
        printf("Case #%d: %d\n", i, work());
        clear();
    }
    return 0;
}