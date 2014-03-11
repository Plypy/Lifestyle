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
const int MAXN = 10005;
int n, k, l, r, sum, sk;
int a[MAXN];
int main(int argc, char const *argv[]) {
    scanf("%d%d%d%d%d%d", &n, &k, &l, &r, &sum, &sk);
    if (k < n) {
        int sr = sum-sk;
        int nr = n-k;
        int p = sr/nr, q = sr%nr;
        for (int i = k; i < n; ++i) {
            a[i] = p;
            if (i-k < q)
                ++a[i];
        }
        l = a[k];
    }
    sk -= l*k;
    for (int i = 0; i < k; ++i) {
        a[i] = l;
        if (sk) {
            int del = min(sk,r-l);
            a[i] += del;
            sk -= del;
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    return 0;
}