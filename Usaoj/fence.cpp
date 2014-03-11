/*
    ID : jake1994
    PROG : fence
    LANG : C++
*/
#include <iostream>
#include <fstream>
using namespace std;
const int MAXN = 505;
int map[MAXN][MAXN];
int d[MAXN];
int output[MAXN];
int st = 505;
int ed = 0;
void walk(int id)
{
    for (int i = st; d[id]; i++)
    {
        if (map[id][i])
        {
            --d[id];
            --d[i];
            --map[id][i];
            --map[i][id];
            walk(i);
        }
    }
    output[++output[0]] = id;
}
int main()
{
    ifstream fin("fence.in");
    ofstream fout("fence.out");
    int n;
    fin >> n;
    int a, b;
    for (int i = 0; i < n; i++)
    {
        fin >> a >> b;
        ++map[a][b];
        ++map[b][a];
        d[a]++;
        d[b]++;
        if (st > a)
            st = a;
        if (st > b)
            st = b;
        if (ed < a)
            ed = a;
        if (ed < b)
            ed = b;
    }
    bool flag = true;
    for (int i = st; i <= ed; i++)
    {
        if (d[i]&1)
        {
            walk(i);
            flag = false;
            break;
        }
    }
    if (flag)
        walk(st);
    for (int i = output[0]; i; i--)
        fout << output[i] << endl;
    fin.close();
    fout.close();
    return 0;
}
