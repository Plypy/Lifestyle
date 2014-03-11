#include <iostream>
#include <math.h>
using namespace std;
const int MAXN = 2001;
int f[MAXN][MAXN];
string a, b;
int k;
int main()
{
    cin >> a >> b;
    cin >> k;
    int m = a.size();
    int n = b.size();
    for (int i = 0; i <= m; i++)
        f[i][0] = i*k;
    for (int j = 1; j <= n; j++)
        f[0][j] = j*k;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            f[i][j] = min(f[i-1][j]+k,min(f[i][j-1]+k,f[i-1][j-1]+abs(a[i-1]-b[j-1])));
    cout << f[m][n];
    return 0;
}
