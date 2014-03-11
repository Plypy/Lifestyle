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

const int MAXN = 100;
int n;
int c[MAXN];
inline int lowbit(int a) {
    return a&-a;
}
void ins(int a) {
    while (a <= n) {
        ++c[a];
        a += lowbit(a);
    }
}
void del(int a) {
    while (a <= n) {
        --c[a];
        a += lowbit(a);
    }
}

int sel(int k) {
    int ret = 0;
    for (int p = 1<<(int(log2(n))); p; p >>= 1)
        if (ret+p < n && c[ret+p] < k)
            k -= c[ret+=p];
    return ret+1;
}

int get(int a) {
    int ret = 0;
    while (a) {
        ret += c[a];
        a -= lowbit(a);
    }
    return ret;
}
int rank(int a) {
    return get(a-1);
}
int num(int l, int r) {
    return get(r)-get(l-1);
}
