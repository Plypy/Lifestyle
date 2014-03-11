/*
    ID : jake1994
    PROG : range
    LANG : C++
*/
#include <iostream>
#include <fstream>
using namespace std;
const int MAXN = 251;
int map[MAXN][MAXN];
int ans[MAXN];
int min(int a, int b, int c)
{
    if (a > b)
        a = b;
    return a<c?a:c;
}
int main()
{
    ifstream fin("range.in");
    ofstream fout("range.out");
    int n;
    fin >> n;
    char ch;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            fin >> ch;
            if (ch == '1')
                map[i][j] = 1;
        }
    for (int i = n-1; i; i--)
        for (int j = n-1; j; j--)
            if (map[i][j])
            {
                map[i][j] = min(map[i+1][j+1],map[i][j+1],map[i+1][j])+1;
                for (int k = 2; k <= map[i][j]; k++)
                    ans[k]++;
            }
    bool flag = true;
    for (int i = 2; i < 251; i++)
        if (ans[i])
        {
            fout << i << ' ' << ans[i] << endl;
            flag = false;
        }
    if (flag)
        fout << endl;
    fin.close();
    fout.close();
    return 0;
}
