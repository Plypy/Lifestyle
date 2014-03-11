/**
 * Description: Use knowledge from memo Dp. Build an array to avoid duplication.
 * Model find a undirected graph without self loop which has exact k pairs of vertices, that satisfies
 * that only one path connects them.
 * We denote the number of a connected componenty d[i], then the total number of pair
 * described above will be Sigma(d[i]*d[j])
 * Then we use dp like search to find a solution will be fun
 * Vital point! You must notice the case that d[i]=2
 * Author: Ply_py
 */
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
#include <cmath>
using namespace std;
const int MAXN = 105;
bool vis[MAXN][MAXN*MAXN];
int ans[MAXN], ct;
int n, k;
bool find(int a, int b) {
    if (vis[a][b])
        return false;
    vis[a][b] = true;
    if (0 == b) {
        ans[++ct] = a;
        return true;
    }
    for (int i = 1; i*i <= b && i < a; ++i)
        if (b%i == 0 && i != 2) {
            int tmp = b-i*(a-i);
            if (tmp < 0)
                continue;
            if (find(a-i,tmp)) {
                ans[++ct] = i;
                return true;
            }
        }
    return false;
}
int main() {
    cin >> n >> k;
    bool flag = true;
    if (n == 2 && k == 0)
        flag = false;
    if (flag && find(n,k)) {
        int st = 0, ed = 0;
        for (int i = 1; i <= ct; ++i) {
            st = ed+1;
            if (ed) {
                cout << ed << ' ' << st << endl;
            }
            ed = ed+ans[i];
            if (ans[i] > 2)
                cout << st << ' ' << ed << endl;
            for (int j = st; j < ed; ++j)
                cout << j << ' ' << j+1 << endl;
        }
    } else {
        cout << -1 << endl;
    }
    return 0;
}
