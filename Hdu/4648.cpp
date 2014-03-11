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
const int MAXM = 10005;
int ar[MAXN];
int fst[MAXM];
int n, m;
int main() {
    while (EOF != scanf("%d%d", &n, &m)) {
        memset(fst,-1,sizeof(fst));
        memset(ar,0,sizeof(ar));
        int ans = 0;
        fst[0] = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", ar+i);
            ar[i] += ar[i-1];
            int tmp = (ar[i]%m+m)%m;
            if (fst[tmp] != -1) {
                ans = max(ans,i-fst[tmp]);
            } else {
                fst[tmp] = i;
            }
        }
        printf("%d\n", ans);
    }
}