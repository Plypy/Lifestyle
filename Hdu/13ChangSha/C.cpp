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
const int MAXN = 50;
int mat1[MAXN][MAXN];
int mat2[MAXN][MAXN];
int n;
int main() {
    while (true) {
        scanf("%d", &n);
        if (n == 0)
            break;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%d", &mat1[i][j]);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%d", &mat2[i][j]);
        int ans[4] = {0, 0, 0, 0};
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                if (mat1[i][j] == mat2[i][j])
                    ++ans[1];
                if (mat1[i][j] == mat2[j][n-i-1])
                    ++ans[2];
                if (mat1[i][j] == mat2[n-i-1][n-j-1])
                    ++ans[3];
                if (mat1[i][j] == mat2[n-j-1][i])
                    ++ans[0];
            }
        int ansf = *max_element(ans, ans+4);
        printf("%d\n", ansf);
    }
}