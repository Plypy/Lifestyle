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


const int MAXN = 55;

bool g[MAXN][MAXN];
void zero[MAXN][MAXN];
int N, M, X;
int ct;
int check(int r, int c) {
    int ret = 0;
    for (int i = -1; i <= 1; ++i)
        for (int j = -1; j <= 1; ++j) {
            if (!g[i][j])
                ++ret;
        }
    return ret;
}

void work(int r, int c) {
    if ()
}

void init() {
    ct = 1;
    g[i][i] = 1;
}
int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        scanf("%d%d%d", &N, &M, &X);
        printf("Case #%d:", i);
        X = N*M-X;
        init();
        if (work(1,1)) {

        } else {
            puts("Impossible");
        }
    }
    return 0;
}