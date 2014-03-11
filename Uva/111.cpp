#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 105;
int pos[MAXN];
int ar[MAXN];
int f[MAXN];
int h[MAXN];
int ans;
int n;

bool load() {
    int t;
    if (EOF == scanf("%d", &t))
        return false;
    ar[t] = 1;
    for (int i = 2; i <= n; ++i) {
        scanf("%d", &t);
        ar[t] = i;
    }
    return true;
}
int find(int t) {
    int bg = 1, ed = ans;
    while (bg <= ed) {
        int mid = (bg+ed)>>1;
        if (h[mid] > t) {
            ed = mid-1;
        } else if (h[mid] == t) {
            bg = mid;
            break;
        } else {
            bg = mid+1;
        }
    }
    h[bg] = t;
    return bg;
}
int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("ans.txt", "w", stdout);
    
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int t;
        scanf("%d", &t);
        pos[i] = t;
    }
    while (load()) {
        for (int i = 1; i <= n; ++i)
            ar[i] = pos[ar[i]];
        ans = 0;
        for (int i = 1; i <= n; ++i) {
            f[i] = find(ar[i]);
            if (ans < f[i])
                ans = f[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}
