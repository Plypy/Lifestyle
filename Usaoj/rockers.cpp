/*
    ID : jake1994
    PROG : rockers
    LANG : C++
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("rockers.in");
ofstream fout("rockers.out");
int len[25];
int n, t, m;
int ans;
void dfs(int ndisk, int vol, int num, int nsong)
{
    if (ndisk>m || nsong>n)
        return;
    dfs(ndisk,vol,num,nsong+1);
    if (t-vol-len[nsong]>=0)
    {
        if (num+1>ans)
            ans = num+1;
        dfs(ndisk,vol+len[nsong],num+1,nsong+1);
    }else if (t-len[nsong]>=0)
    {
        if (num+1>ans && ndisk != m)
            ans = num+1;
        dfs(ndisk+1,len[nsong],num+1,nsong+1);
    }
}
int main()
{
    fin >> n >> t >> m;
    for (int i = 1; i <= n; i++)
        fin >> len[i];
    dfs(1,0,0,1);
    fout << ans << endl;
    return 0;
}
