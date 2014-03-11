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

const int MOD = 1000000007;
typedef long long ll;

int mult(ll a, ll b) {
    ll t = a*b;
    return (t%MOD+MOD)%MOD;
}
int add(ll a, ll b) {
    ll t = a+b;
    return (t%MOD+MOD)%MOD;
}
const int MAXN = 1000005;
int pfact[MAXN], rfact[MAXN];
int a[MAXN];
int n;

void work() {
    sort(a+1,a+n+1);
    pfact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        pfact[i] = mult(pfact[i-1],a[i]);
    }
    rfact[n+1] = 1;
    for (int i = n; i; --i) {
        rfact[i] = mult(rfact[i+1],a[i]);
    }
    int ans = mult(n,pfact[n]);
    int rem = n-1;
    int i = n;
    while (rem > 0) {
        int tmp = mult(pfact[i-1],rfact[i+1]);
        ans = add(ans,-tmp);
        --rem;
        if ((n-rem)&1)
            --i;
    }
    printf("%d\n", ans);
}

void load() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a+i);
    }
}


int main(int argc, char const *argv[]) {
    int T;
    scanf("%d", &T);
    while (T--) {
        load();
        work();
    }
    return 0;
}