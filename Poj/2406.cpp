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
const int MAXN = 1000005;

char s[MAXN];
int pre[MAXN];
int n;
void kmp() {
    pre[1] = 0;
    int k = 0;
    for (int i = 2; i <= n; ++i) {
        while (k > 0 && s[k+1] != s[i])
            k = pre[k];
        if (s[k+1] == s[i])
            k = k+1;
        pre[i] = k;
    }
}

int main() {
    while (true) {
        scanf("%s", s+1);
        if (0 == strcmp(".",s+1))
            break;
        n = strlen(s+1);
        kmp();

        int ans = 1;
        if (0 == n%(n-pre[n])) {
            ans = n/(n-pre[n]);
        }
        printf("%d\n", ans);
    }
    return 0;
}