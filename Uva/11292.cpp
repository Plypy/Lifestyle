/**
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
using namespace std;
const int MAXN = 20005;

int n, m;
int a[MAXN], b[MAXN];
int main() {
    while (true) {
        scanf("%d%d", &n, &m);
        if (0 == n && 0 == m)
            break;
        for (int i = 0; i < n; ++i)
            scanf("%d", a+i);
        for (int i = 0; i < m; ++i)
            scanf("%d", b+i);
        sort(a,a+n);
        sort(b,b+m);
        int p = 0;
        int ans = 0;
        bool flag = true;
        for (int i = 0; i < n; ++i) {
            while (p < m && b[p] < a[i])
                ++p;
            if (p >= m) {
                flag = false;
                break;
            }
            ans += b[p++];
        }
        if (flag) {
            cout << ans << endl;
        } else {
            cout << "Loowater is doomed!" << endl;
        }
    }
    return 0;
}
