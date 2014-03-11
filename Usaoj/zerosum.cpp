/*
ID: jake1994
PROG: zerosum
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
// 2 rep +
// 3 rep -
// 1 rep blank
ifstream fin("zerosum.in");
ofstream fout("zerosum.out");
int op[10];
int num[10];
int n;
int cal()
{
    int ct = 1;
    num[ct] = 1;
    for (int i = 1; i < n; i++)
    {
        if (op[i] == 1)
            num[ct] = num[ct]*10+i+1;
        else
            num[++ct] = i+1;
    }
    int ret = num[1];
    ct = 1;
    for (int i = 1; i < n; i++)
    {
        if (op[i] == 1)
            continue;
        else if (op[i] == 3)
            ret -= num[++ct];
        else
            ret += num[++ct];
    }
    return ret;
}
void show()
{
    fout << 1;
    for (int i = 1; i < n; i++)
    {
        if (op[i] == 2)
            fout << '+';
        else if (op[i] == 3)
            fout << '-';
        else
            fout << ' ';
        fout << i+1;
    }
    fout << endl;
}
void dfs(int pos)
{
    if (pos == n)
    {
        if (!cal())
            show();
        return;
    }
    for (int i = 1; i <= 3; i++)
    {
        op[pos] = i;
        dfs(pos+1);
    }
}
int main()
{
    fin >> n;
    dfs(1);
    fin.close();
    fout.close();
    return 0;
}
