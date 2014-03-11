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

const int MAXN = 105*2;
int f[MAXN];
int find(int a) {
    if (f[a] == a)
        return a;
    return f[a] = find(f[a]);
}
void merge(int a, int b) {
    a = find(a), b = find(b);
    f[a] = b;
}
void init() {
    for (int i = 1; i < MAXN; ++i)
        f[i] = i;
}
int n;
int opp(int a) {
    if (a <= n)
        return a+n;
    else
        return a-n;
}
bool buf[MAXN];
void work() {
    for (int i = 1; i <= n; ++i) {
        memset(buf,0,sizeof(buf));
        buf[i] = true;
        while (true) {
            int a;
            scanf("%d", &a);
            if (0 == a)
                break;
            buf[a] = true;
        }
        for (int j = 1; j <= n; ++j)
            if (!buf[j])
                merge(i,j+n);
    }
    bool flag = true;
    for (int i = 1; i <= n; ++i)
        if (find(i) == find(i+n)) {
            flag = false;
            break;
        }
    if (flag)
        puts("YES");
    else
        puts("NO");
}
bool load() {
    init();
    return (EOF != scanf("%d", &n));
}

int main(int argc, char const *argv[]) {
    while (load()) {
        work();
    }
    return 0;
}