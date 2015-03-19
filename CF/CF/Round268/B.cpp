/**
 * Description:
 * ProblemName:
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
#include <vector>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
using namespace std;

const int MAXN = 200005;

map<int, int> table;

int fa[MAXN*2];
int find(int a) {
    if (fa[a] == 0) {
        return a;
    }
    return fa[a] = find(fa[a]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) {
        return;
    }
    fa[a] = b;
}

int a, b;
int n;
int ar[MAXN];
int chose[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> a >> b;
    for (int i = 1; i <= n; ++i) {
        cin >> ar[i];
        table[ar[i]] = i;
    }

    bool flag = true;
    for (int i = 1; i <= n; ++i) {
        int u = i;
        int v = -1;;
        if (table.count(a-ar[i])) {
            v = table[a-ar[i]];
            merge(u,v);
        } else {
            merge(u,n+1);
        }
        if (table.count(b-ar[i])) {
            v = table[b-ar[i]];
            merge(u,v);
        } else {
            merge(u,n+2);
        }
    }
    for (int i = 1; i <= n && flag; ++i) {
        if (find(n+1) == find(n+2)) {
            flag = false;
        }
    }
    if (!flag) {
        puts("NO");
        return 0;
    }
    puts("YES");
    for (int i = 1; i <= n; ++i) {
        printf("%d%c", (find(i) != find(n+2))?1:0, i == n? '\n': ' ');
    }
}
