/*
    ID : jake1994
    PROG : inflate
    LANG : C++
*/
#include <iostream>
#include <fstream>
using namespace std;
const int MAXN = 10001;
int f[MAXN];
int cost[MAXN];
int val[MAXN];
int main()
{
    ifstream fin("inflate.in");
    ofstream fout("inflate.out");
    int t, n;
    fin >> t >> n;
    for (int i = 1; i <= n; i++)
        fin >> val[i] >> cost[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = cost[i]; j <= t; j++)
            if (f[j] < f[j-cost[i]]+val[i])
                f[j] = f[j-cost[i]]+val[i];
    }
    fout << f[t] << endl;
    fin.close();
    fout.close();
    return 0;
}
