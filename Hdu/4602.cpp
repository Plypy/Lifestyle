/**
 * Description: 把n看成n个连续的1，一个数字k就是k个连续的1相连,那么随意选连续的k个数字，然后再用隔板将其左右分隔
 * Source: hdu4602
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
inline int add(ll a, ll b) {
    return (a+b)%MOD;
}
inline int mult(ll a, ll b) {
    return (a*b)%MOD;
}
inline ll mypow(ll a, ll b) {
    if (b == 0)
        return 1;
    ll tmp = mypow(a,b/2);
    ll ret = mult(tmp,tmp);
    if (b&1)
        ret = mult(ret,a);
    return ret;
}
const int MAXN = 10005;
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, k;
        scanf("%d%d", &n, &k);
        if (n == k)
            puts("1");
        else if (n < k)
            puts("0");
        else {
            int ans = add(mypow(2,n-k), mult(n-k-1,mypow(2,n-k-2)));
            printf("%d\n", ans);
        }
    }
}