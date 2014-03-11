/*
  Name: LUP-DECOMPOSTION
  Author: Ply_py
  Date: 2011.4
  Description: USING LUP-DECOMPOSTION TO SOLVE A LINEAR EQUATION SYSTEM.
               REALIZED BY CPP LANGUAGE.
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
const int MAXN = 105;
double mat[MAXN][MAXN];
int pem[MAXN];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> mat[i][j];
    for (int i = 1; i <= n; ++i)
        pem[i] = i;
    for (int k = 1; k <= n; ++k)
    {
        int t;
        double p = 0;
        for (int i = k; i <= n; ++i)
            if (fabs(mat[i][k]) > p)
            {
                p = fabs(mat[i][k]);
                t = i;
            }
        swap(pem[k],pem[t]);
        for (int i = 1; i <= n; ++i)
            swap(mat[k][i], mat[t][i]);
        for (int i = k+1; i <= n; ++i)
        {
            mat[i][k] = mat[i][k]/mat[k][k];
            for (int j = k+1; j <= n; ++j)
                mat[i][j] = mat[i][j]-mat[i][k]*mat[k][j];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cout << mat[i][j] << ' ';
        cout << endl;
    }
    system("pause");

    return 0;
}
