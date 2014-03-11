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
const int MAXN = 200;

int f[MAXN][MAXN][10];;
int n, v1, v2, k;
struct Item {
    int a, b, val;
    bool operator< (const Item &t) const {
        return val>t.val;
    }
} item[MAXN];
int ans = 0;
int cnt = 0;
bool load() {
    ans = 0;
    memset(f,0,sizeof(f));
    memset(item,0,sizeof(item));
    cin >> n >> v1 >> v2 >> k;
    if (!cin)
        return false;
    cnt = 0;
    for (int i = 1; i <= n; ++i) {
        ++cnt;
        cin >> item[cnt].a >> item[cnt].b >> item[cnt].val;
        if (item[cnt].a == 0 || item[cnt].b == 0) {
            ans += item[cnt].val;
            --cnt;
        }
    }
    return true;
}
void work() {
    for (int i = 1; i <= cnt; ++i) {
        for (int p = v1; p >= 0; --p)
            for (int q = v2; q >= 0; --q) {
                for (int s = k; s >= 0; --s) {
                    if (s >= 1) {
                        int t = f[p][q][s-1]+item[i].val;
                        if (f[p][q][s] < t)
                            f[p][q][s] = t;
                    }
                    if (p >= item[i].a) {
                        int t = f[p-item[i].a][q][s]+item[i].val;
                        if (f[p][q][s] < t) {
                            f[p][q][s] = t;
                        }
                    }
                    if (q >= item[i].b) {
                        int t = f[p][q-item[i].b][s]+item[i].val;
                        if (f[p][q][s] < t) {
                            f[p][q][s] = t;
                        }
                    }
                }
            }
    }
    cout << f[v1][v2][k]+ans << endl;
}
int main() {
    while (load()) {
        work();
    }
}
