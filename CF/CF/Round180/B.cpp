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
const int MAXN = 100005;
int n, m, k;
int a[MAXN], b[MAXN];
int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d", a+i);
    for (int i = 0; i < m; ++i)
        scanf("%d", b+i);
    sort(a,a+n);
    sort(b,b+m);
    int pa = 0, pb = 0;
    bool flag = false;
    for (; pa < n; ++pa) {
        bool larger = false;
        for (; pb < m; ++pb)
            if (b[pb] >= a[pa]) {
                ++pb;
                larger = true;
                break;
            }
        if (!larger) {
            flag = true;
            break;
        }
    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
