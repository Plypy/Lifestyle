/*
ID: jake1994
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
const int MAXN = 11;
int n;
bool sour[MAXN][MAXN];
bool sour1[MAXN][MAXN];
bool tmp[MAXN][MAXN];
bool dest[MAXN][MAXN];
bool check()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (tmp[i][j] != dest[i][j])
                return false;
    return true;
}
int main()
{
    ifstream fin("transform.in");
    ofstream fout("transform.out");
    fin >> n;
    char ch;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            fin >> ch;
            if (ch == '@')
                sour[i][j] = true;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            fin >> ch;
            if (ch == '@')
                dest[i][j] = true;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            tmp[i][j] = sour[n-j+1][i];
    if (check())
    {
        fout << 1 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            tmp[i][j] = sour[n-i+1][n-j+1];
    if (check())
    {
        fout << 2 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            tmp[i][j] = sour[j][n-i+1];
    if (check())
    {
        fout << 3 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            tmp[i][j] = sour[i][n-j+1];
    if (check())
    {
        fout << 4 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            sour1[i][j] = tmp[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            tmp[i][j] = sour1[n-j+1][i];
    if (check())
    {
        fout << 5 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            tmp[i][j] = sour1[n-i+1][n-j+1];
    if (check())
    {
        fout << 5 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            tmp[i][j] = sour1[j][n-i+1];
    if (check())
    {
        fout << 5 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            tmp[i][j] = sour[i][j];
    if (check())
    {
        fout << 6 << endl;
        return 0;
    }
    fout << 7 << endl;
    return 0;
    fin.close();
    fout.close();
    return 0;
}
