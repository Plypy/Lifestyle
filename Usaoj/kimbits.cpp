/*
    ID : jake1994
    PROG : kimbits
    LANG : C++
*/
#include <iostream>
#include <fstream>
using namespace std;
const int MAXN = 32;
unsigned f[MAXN][MAXN];
unsigned n,l,c;
int main()
{
    ifstream fin("kimbits.in");
    ofstream fout("kimbits.out");
    fin >> n >> l >> c;
    for (int i = 0; i <= n; i++)
        f[i][0] = 1;
    for (int i = 0; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (j > i)
                f[i][j] = f[i][i];
            else
                f[i][j] = f[i-1][j]+f[i-1][j-1];
        }
    string ans;
    for (int i = n; i; i--)
    {
        if (c > f[i-1][l])
        {
            ans += '1';
            c -= f[i-1][l];
            --l;
        }
        else
            ans += '0';
    }
    fout << ans << endl;
    fin.close();
    fout.close();
    return 0;
}
