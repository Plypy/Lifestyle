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
int n;
int used[MAXN];

int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    for (int t= 1; t<= T; ++t) {
        memset(used,0,sizeof(used));
        int r;
        scanf("%d", &r);
        for (int i = 1; i <= 4; ++i)
            for (int j = 1; j <= 4; ++j) {
                int d;
                scanf("%d", &d);
                if (i == r) {
                    used[d] = true;
                }
            }

        scanf("%d", &r);
        int ct = 0;
        int ans = 0;
        for (int i = 1; i <= 4; ++i)
            for (int j = 1; j <= 4; ++j) {
                int d;
                scanf("%d", &d);
                if (i == r) {
                    if (used[d]) {
                        ++ct;
                        ans = d;
                    }
                }
            }
        printf("Case #%d: ", t);
        if (ct == 1) {
            printf("%d\n", ans);
        } else if (ct < 1) {
            puts("Volunteer cheated!");
        } else {
            puts("Bad magician!");
        }
    }
    return 0;
}