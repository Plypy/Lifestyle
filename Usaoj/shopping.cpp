/*
    ID : jake1994
    PROG : shopping
    LANG : C++
*/
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
const int INF = 52111425;
int f[6][6][6][6][6];
int target[6];
int wt[110][6];
int val[110];
int tick[6];
int note(int id)
{
    int i;
    for (i = 1; tick[i]; i++)
        if (tick[i] == id)
            return i;
    tick[i] = id;
    return i;
}
int main()
{
    ifstream fin("shopping.in");
    ofstream fout("shopping.out");
    int s;
    int n;
    fin >> s;
    int c, k, p;
    for (int i = 1; i <= s; i++)
    {
        fin >> n;
        for (int j = 1; j <= n; j++)
        {
            fin >> c >> k;
            wt[i][note(c)] = k;
        }
        fin >> val[i];
    }
    fin >> n;
    n += s;
    for (int i = s+1; i <= n; i++)
    {
        fin >> c >> k;
        target[note(c)] = k;
        wt[i][note(c)] = 1;
        fin >> val[i];
    }
    for (int q = 0; q <= target[1]; q++)
        for (int w = 0; w <= target[2]; w++)
            for (int e = 0; e <= target[3]; e++)
                for (int r = 0; r <= target[4]; r++)
                    for (int t = 0; t <= target[5]; t++)
                        f[q][w][e][r][t] = INF;
    f[0][0][0][0][0] = 0;
    int tmp;
    for (int i = 1; i <= n; i++)
        for (int q = wt[i][1]; q <= target[1]; q++)
            for (int w = wt[i][2]; w <= target[2]; w++)
                for (int e = wt[i][3]; e <= target[3]; e++)
                    for (int r = wt[i][4]; r <= target[4]; r++)
                        for (int t = wt[i][5]; t <= target[5]; t++)
                            if (f[q][w][e][r][t] > (tmp = f[q-wt[i][1]][w-wt[i][2]][e-wt[i][3]][r-wt[i][4]][t-wt[i][5]]+val[i]))
                                f[q][w][e][r][t] = tmp;
    fout << f[target[1]][target[2]][target[3]][target[4]][target[5]] << endl;
    fin.close();
    fout.close();
    return 0;
}
