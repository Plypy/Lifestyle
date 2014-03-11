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

int gcd(int a, int b) {
    if (0 == b)
        return a;
    return gcd(b,a%b);
}
int extend_gcd(int a, int b, int &x, int &y) {
    if (0 == b) {
        x = 1, y = 0;
        return a;
    } else {
        int ret = extend_gcd(b,a%b,y,x);
        y -= x*(a/b);
        return ret;
    }
}
int inv(int x, int m) {
    int a, b;
    extend_gcd(x,m,a,b);
    return a;
}
int crt(int a[], int m[], int n) {
    int M = 1;
    for (int i = 0; i < n; ++i)
        M *= m[i];
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        int e = M/m[i];
        int ne = inv(e,m[i]);
        // cout << e << ' ' << ne << " matching " << m[i] << endl;
        ret = (ret+e*ne*a[i])%M;
    }
    return (ret+M)%M;
}
const int MAXN = 5;
int mod[MAXN] = {23, 28, 33};
int fst[MAXN];
int beg;
int lcm(int a, int b) {
    return a*b/gcd(a,b);
}
void test() {
    cout << lcm(23,lcm(28,33)) << endl;
}
bool load() {
    for (int i = 0; i < 3; ++i) {
        scanf("%d", fst+i);
        fst[i] %= mod[i];
    }
    scanf("%d", &beg);
    if (-1 == beg)
        return false;
    return true;
}
int work() {
    int ans = crt(fst,mod,3);
    // cout << "origin " << ans << endl;
    int M = mod[0]*mod[1]*mod[2];
    if (ans <= beg)
        ans += M;
    ans -= beg;
    return ans;
}
int main(int argc, char const *argv[]) {
    // test();
    int kase = 0;
    while (load()) {
        printf("Case %d: the next triple peak occurs in %d days.\n", ++kase, work());
    }
    return 0;
}