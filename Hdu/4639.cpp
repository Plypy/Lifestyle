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

const int MAXN = 11000;
const int MOD = 10007;
char s[MAXN];
int f[MAXN];
int add(int a, int b) {
    return (a+b)%MOD;
}
int mult(int a, int b) {
    return (a*b)%MOD;
}
int fib(int n) {
    if (f[n])
        return f[n];
    return f[n] = add(fib(n-1),fib(n-2));
}
void load() {
    scanf("%s", s);
}
int work() {
    int ans = 1;
    int len = strlen(s);
    for (int i = 0; i < len; ++i) {
        int cnt = 0;
        while (i < len-1 && 'h' == s[i] && 'e' == s[i+1]) {
            ++cnt;
            i += 2;
        }
        // cout << i << ' ' << cnt << endl;
        ans = mult(ans,fib(cnt));
    }
    return ans;
}
int main(int argc, char const *argv[]) {
    int T;
    scanf("%d", &T);
    f[0] = 1;
    f[1] = 1;
    for (int i = 1; i <= T; ++i) {
        load();
        printf("Case %d: %d\n", i, work());
    }
    return 0;
}