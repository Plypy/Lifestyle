#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int MAXN = 15;
int mat[MAXN][MAXN];
int n;
int main()
{
    cin >> n;
    for (int i = 1 ; i <= n; ++i) {
        mat[i][1] = mat[1][i] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 2; j <= n; ++j) {
            mat[i][j] = mat[i-1][j] + mat[i][j-1];
        }
    }
    cout << mat[n][n] << endl;
}
