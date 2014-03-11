/**
 * Description: For ith integer, find the longest non-decreasing sub-sequence that begins with it
 * and the longest non-increasing sub-sequence that begins with it. The answer will be their combination.
 * Source: HDU 4604
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

const int MAXN = 100005;
int pos1[MAXN], pos2[MAXN];
int val1[MAXN], val2[MAXN];
int f1[MAXN], f2[MAXN];
int len1, len2;
int a[MAXN];
int pre[MAXN];
int sum[MAXN];
int get1(int x) {
    int l = 0, r = len1+1;
    while (l+1 < r) {
        int m = (l+r)/2;
        if (x <= val1[m])
            l = m;
        else
            r = m;
    }
    return l+1;
}
int get2(int x) {
    int l = 0, r = len2+1;
    while (l+1 < r) {
        int m = (l+r)/2;
        if (x >= val2[m])
            l = m;
        else
            r = m;
    }
    return l+1;
}
int n;
void lis() {
    for (int i = n; i; --i) {
        int t = get1(a[i]);
        if (t > len1)
            len1 = t;
        f1[i] = t;
        pre[i] = pos1[t-1];
        val1[t] = a[i];
        pos1[t] = i;
    }
    for (int i = n; i; --i) {
        ++sum[i];
        int t = pre[i];
        if (a[t] == a[i])
            sum[i] = sum[t]+1;
    }
}
void nlis() {
    for (int i = n; i; --i) {
        int t = get2(a[i]);
        if (t > len2)
            len2 = t;
        f2[i] = t;
        val2[t] = a[i];
    }
}
void init() {
    len1 = len2 = 0;
    memset(pos1,0,sizeof(pos1));
    memset(pos2,0,sizeof(pos2));
    memset(val1,0,sizeof(val1));
    memset(val2,0,sizeof(val2));
    memset(f1,0,sizeof(f1));
    memset(f2,0,sizeof(f2));
    memset(pre,0,sizeof(pre));
    memset(sum,0,sizeof(sum));
}
void work() {
    lis();
    nlis();
    int ans = 0;
    // for (int i = 1; i <= n; ++i) {
    //     printf("%d %d %d %d\n", i, f1[i], f2[i], sum[i]);
    // }
    for (int i = 1; i <= n; ++i) {
        int t = f1[i]+f2[i]-sum[i];
        if (ans < t)
            ans = t;
    }
    printf("%d\n", ans);
}
void load() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a+i);
}
int main(int argc, char const *argv[]) {
    int T;
    scanf("%d", &T);
    while (T--) {
        init();
        load();
        work();
    }
    return 0;
}