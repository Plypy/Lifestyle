/**
 * Description: Easy
 * ProblemName:
 * Source: Codeforces
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

const int MAXN = 100005;
int n;
int ht[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", ht+i);
    }
    int ans = 0, en = 0;
    for (int i = 1; i <= n; ++i) {
        int cost = ht[i]-ht[i-1];
        if (cost <= 0) {
            en -= cost;
            continue;
        }
        if (cost <= en) {
            en -= cost;
            continue;
        }
        cost -= en;
        en = 0;
        ans += cost;
    }
    cout << ans << endl;
}
