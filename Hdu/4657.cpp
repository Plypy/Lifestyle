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
int n;
int a[MAXN], b[MAXN], c[MAXN];
int idxa[MAXN];


int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &b[i]);
        for (int i = 0; i < n; ++i)
            a[i] = c[i] = idxa[i] = i;
        for (int i = 0; i < n; ++i) {
            int cur = i;
            while ((a[cur]+b[cur])%n != c[cur]) {
                int nxt = idxa[(c[cur]-b[cur]+n)%n];
                swap(a[cur],a[nxt]);
                swap(idxa[a[cur]],idxa[a[nxt]]);
                if (nxt > i)
                    break;
                swap(c[nxt],c[i+1]);
                cur = nxt;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i) {
                printf(" ");
            }
            printf("%d", a[i]);
        }
        puts("");
        for (int i = 0; i < n; ++i) {
            if (i) {
                printf(" ");
            }
            printf("%d", c[i]);
        }
        puts("");
    }
    return 0;
}