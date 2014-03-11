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

const int MAXN = 100005;
int n, m, s, f;
int t[MAXN], l[MAXN], r[MAXN];
typedef long long ll;
bool check(ll p, ll l, ll r) {
    return (p-l)*(p-r)<=0;
}
int main(int argc, char const *argv[]) {
    scanf("%d%d%d%d", &n, &m, &s, &f);
    for (int i = 0; i < m; ++i)
        scanf("%d%d%d", t+i, l+i, r+i);
    int i = 0, j = 1;
    int dir = f-s;
    if (dir>0)
        dir = 1;
    else
        dir = -1;
    while (s != f) {
        int nxt = s+dir;
        if (t[i] == j && (check(nxt,l[i],r[i]) || check(s,l[i],r[i])))
            putchar('X');
        else {
            putchar(dir>0?'R':'L');
            s = nxt;
        }
        ++j;
        if (j > t[i])
            ++i;
    }
    return 0;
}