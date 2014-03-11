/**
 * Description:
 * Source: 2013 NanJing onsite problem 1009 "Wall Painting"
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

const int MAXN = 1005;
const int MOD = 1000000+3;

int C[MAXN][MAXN];
typedef long long ll;
int add(ll a, ll b) {
    return (a+b)%MOD;
}
int mult(ll a, ll b) {
    return (a*b)%MOD;
}
void init() {
    for (int i = 0; i < MAXN; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = add(C[i-1][j-1],C[i-1][j]);
        }
    }
}
const int BIT = 31;
int ct[BIT];
int ans[MAXN];
int n;
bool load() {
    if (EOF == scanf("%d", &n))
        return false;
    memset(ct,0,sizeof(ct));
    memset(ans,0,sizeof(ans));
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        for (int j = 0, p = 1; j < BIT; ++j, p<<=1) {
            if (a&p)
                ++ct[j];
        }
    }
    return true;
}

void work() {
    for (int k = 1; k <= n; ++k) {
        for (int i = 0, p = 1; i < BIT; ++i, p<<=1) {
            int sum = 0;
            int a = ct[i], b = n-ct[i];
            for (int j = 1; j <= k; j+=2)
                sum = add(sum,mult(C[a][j],C[b][k-j]));
            ans[k] = add(ans[k],mult(sum,p));
        }
    }
    for (int k = 1; k <= n; ++k) {
        printf("%d", ans[k]);
        if (k != n)
            printf(" ");
    }
    puts("");
}
int main(int argc, char const *argv[]) {
    init();
    while (load()) {
        work();
    }
    return 0;
}