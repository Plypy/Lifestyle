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

const int MAXN =  100005;
const int INF = 0x7fffffff;

int ar[MAXN];
int l[MAXN], r[MAXN];
int n;
int ans = 0;

int main(int argc, char const *argv[]) {
    scanf("%d", &n);
    ar[0] = -INF;
    ar[n+1] = INF;
    int len = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", ar+i);
        if (ar[i] > ar[i-1]) {
            l[i] = l[i-1]+1;
        } else {
            l[i] = 1;
        }
    }
    int ans = 0;
    for (int i = n; i; --i) {
        if (ar[i] < ar[i+1]) {
            r[i] = r[i+1]+1;
        } else {
            r[i] = 1;
        }
        int t = 0;
        if (ar[i+1]-ar[i-1] <= 1) {
            t = max(l[i-1],r[i+1])+1;
        } else {
            t = l[i-1]+1+r[i+1];
        }
        if (t > ans) {
            ans = t;
        }
    }
    printf("%d\n", ans);
    return 0;
}
