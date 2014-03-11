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

const int BD = 1<<16;

bool notp[BD];
vector<int> plis;
int pnum;

void prep() {
    for (int i = 2; i < BD; ++i)
        if (!notp[i]) {
            plis.push_back(i);
            for (int j = i+i; j < BD; j += i)
                notp[j] = true;
        }
    pnum = plis.size();
}

int solve(int n) {
    int ret = 1;
    for (int i = 0; i < pnum && plis[i]*plis[i] <= n; ++i) {
        int p = plis[i];
        int tmp = 0;
        while (n%p == 0) {
            ++tmp;
            n /= p;
        }
        if (tmp)
            ret *= 6*tmp;
    }
    if (n>1)
        ret *= 6;
    return ret;
}
int main(int argc, char const *argv[]) {
    prep();
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        int g, l;
        scanf("%d%d", &g, &l);
        int ans = 0;
        if (l%g == 0)
            ans = solve(l/g);
        printf("%d\n", ans);
    }
    return 0;
}