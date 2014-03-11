/**
 * Description: This problem requires you to find a maximum sub-square that each column and row forms a palindrome.
 *  For this kind of problem that involves palindrome, we may just use violent method.
 *  Dichotomy (bisection) the size, or just enumerate decreasingly, and check it.
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

const int MAXN = 305;
int mat[MAXN][MAXN];
int n, m;
bool ispal(int x, int y, int size) {
    for (int i = 0; i < size; ++i) {
        int row = x+i;
        int l = y, r = y+size-1;
        while (l <= r) {
            if (mat[row][l] != mat[row][r])
                return false;
            ++l, --r;
        }
        int col = y+i;
        l = x, r = x+size-1;
        while (l <= r) {
            if (mat[l][col] != mat[r][col])
                return false;
            ++l, --r;
        }
    }
    return true;
}

bool check(int size) {
    for (int i = 1; i+size-1 <= n; ++i)
        for (int j = 1; j+size-1 <= m; ++j)
            if (ispal(i,j,size)) {
                return true;
            }
    return false;
}

void work() {
    int ans = 0;
    for (int i = min(n,m); i; --i)
        if (check(i)) {
            ans = i;
            break;
        }
    printf("%d\n", ans);
}
void load() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &mat[i][j]);
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        load();
        work();
    }
}