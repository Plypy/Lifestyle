/*
    ID : jake1994
    PROG : humble
    LANG : C++
*/
//°¦ ÆÓËØ°¡ÆÓËØ 
#include <iostream>
#include <fstream>
#include <climits>
using namespace std;
const int MAXK = 101;
const int MAXN = 100001;
int bas[MAXK];
int ans[MAXN];
int index[MAXK];
int main()
{
    ifstream fin("humble.in");
    ofstream fout("humble.out");
    int k, n;
    fin >> k >> n;
    for (int i = 1; i <= k; i++)
        fin >> bas[i];
    ans[0] = 1;
    int add;
    for (int i = 1; i <= n; i++)
    {
        add = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            int k;
            for (k = index[j]; bas[j]*ans[k] <= ans[i-1]; k++)
                continue;
            index[j] = k;
            if (add > bas[j]*ans[k])
                add = bas[j]*ans[k];
        }
        ans[i] = add;
    }
    fout << ans[n] << endl;
    fin.close();
    fout.close();
    return 0;
}
