#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iomanip>
#include <queue>
using namespace std;
typedef long long LL;
const long long MAXN = 20;
const long long MOD = 1000000007;
long long fact[MAXN];
long long fact2[MAXN];
int n;
void init() {
    fact[1] = 1;
    for (int i = 2; i <= MAXN; ++i)
        fact[i] = fact[i-1]*i%MOD;
    fact2[1] = 1;
    fact2[0] = 1;
    for (int i = 2; i <= MAXN; ++i)
        fact2[i] = fact2[i-2]*i%MOD;
}
int main() {
    init();
    scanf("%d", &n);
    if (n == 1 || n == 2 || 0 == n%2)
        puts("0");
    long long ans = fact[n]*fact2[n]%MOD;
    printf("%I64d\n", ans);
    return 0;
}
