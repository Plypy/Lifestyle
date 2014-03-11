#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
const int MAXN = 2010;
int f[MAXN][MAXN];
int alen, blen;
int k;
const int INF = 52111425;
inline int min(int a, int b)
{
    return a<b?a:b;
}
int main()
{
    string a;
    string b;
    cin >> a >> b >> k;
    blen = b.size();
    alen = a.size();
    a = ' '+a;
    b = ' '+b;
    for (int i = 1; i <= alen; ++i)
        f[i][0] = i*k;
    for (int i = 1; i <= blen; ++i)
        f[0][i] = i*k;
    for (int i = 1; i <= alen; ++i)
        for (int j = 1; j <= blen; ++j)
        {
            f[i][j] = f[i-1][j-1]+abs(a[i]-b[j]);
            f[i][j] = min(f[i][j], f[i-1][j]+k);
            f[i][j] = min(f[i][j], f[i][j-1]+k);
        }
    cout << f[alen][blen] << endl;
//    system("pause");
    return 0;
}
