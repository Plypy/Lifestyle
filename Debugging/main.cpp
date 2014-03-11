#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
const int MAXN=101;
const int INF = 0x3f3f3f3f;
int f[MAXN][MAXN];
int g[MAXN][MAXN];
string s;
int n,k;
void load()
{
    ios::sync_with_stdio(false);
    cin >> s >> k;
    n = s.size();
//    n=6;
//    k=3;
//    s="310143";
    for(int j=1;j<=n;j++)
        for(int i=1;i<=j;i++)
            g[i][j]=atoi(s.substr(i-1,j-i+1).c_str());
    for(int i=1;i<=n;i++)
        f[i][0]=g[1][i];
//    for(int i=1;i<=n;i++)
//        for(int j=1;j<=i;j++)
//            cout<<j<<" "<<i<<" "<<g[j][i]<<endl;
}
void dp()
{
    for(int j=1;j<=k;j++)
        for(int i=2;i<=n;i++)
        {
            int tmp=INF;
            for(int h=1;i-h>j-1;h++)
                tmp=min(tmp,f[i-h][j-1]+g[i-h+1][i]);
            f[i][j]=tmp;
        }
    cout<<f[n][k]<<endl;
}
int main()
{
    load();
    dp();
    return 0;
}
