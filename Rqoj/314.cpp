#include <iostream>
#include <cstdlib>
using namespace std;
const int MAXN = 11;
int mat[MAXN][MAXN];
int f[MAXN][MAXN][MAXN][MAXN];
int n;
void load() {
    cin >> n;
    int x, y, v;
    while (true) {
        cin >> x >> y >> v;
        if (!x)
            break;
        mat[x][y] = v;
    }
}
inline int max(int a, int b) {
    return a>b?a:b;
}
void work() {
    f[1][1][1][1] = mat[1][1];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            for (int k = 1; k <= n; ++k)
                for (int l = 1; l <= n; ++l) {
                    if ((i != k || j != l) || (i == n && j == n)) {
                        f[i][j][k][l] = max(f[i][j][k][l],f[i-1][j][k-1][l]);
                        f[i][j][k][l] = max(f[i][j][k][l],f[i-1][j][k][l-1]);
                        
                        f[i][j][k][l] = max(f[i][j][k][l],f[i][j-1][k-1][l]);
                        f[i][j][k][l] = max(f[i][j][k][l],f[i][j-1][k][l-1]);
                        f[i][j][k][l] += mat[i][j]+mat[k][l];
                    }
                }
    int ans = f[n][n][n][n]-mat[n][n];
    cout << ans << endl;
//    system("pause");
}
int main() {
    load();
    work();
    return 0;
}
/*
8
2  3  13
2  6   6
3  5   7
4  4  14
5  2  21 
5  6   4
6  3  15
7  2  14
0  0   0

ans  67
*/
