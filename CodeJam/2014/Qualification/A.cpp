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
#include <map>
#include <vector>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
using namespace std;

const int MAXN = 20;

bool used[MAXN];

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        memset(used,0,sizeof(used));
        int r;
        scanf("%d", &r);
        for (int j = 1; j <= 4; ++j)
            for (int k = 1; k <= 4; ++k) {
                int d;
                scanf("%d", &d);
                if (j == r)
                    used[d] = true;
            }
        scanf("%d", &r);
        int ans = -1;
        int ct = 0;
        for (int j = 1; j <= 4; ++j) {
            for (int k = 1; k <= 4; ++k) {
                int d;
                scanf("%d", &d);
                if (j == r) {
                    if (used[d]) {
                        ans = d;
                        ++ct;
                    }
                }
            }
        }
        printf("Case #%d: ", i);
        if (ct == 1) {
            printf("%d\n", ans);
        } else {
            if (ct < 1) {
                puts("Volunteer cheated!");
            } else {
                puts("Bad magician!");
            }
        }
    }
}