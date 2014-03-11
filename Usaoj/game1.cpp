/*
    ID : jake1994
    PROG : game1
    LANG : C++
*/
#include <iostream>
#include <fstream>
using namespace std;
int n,num[101],dp[101][101],sum[101][101];
int main()
{
    ifstream fin("game1.in");
    ofstream fout("game1.out");
    fin>>n;
    for (int i=1;i<=n;i++)
        fin>>num[i];
    for (int i=1;i<=n;i++)
    {
        dp[i][i] = sum[i][i]=num[i];
        for (int j=i+1;j<=n;j++)
            sum[i][j]=sum[i][j-1]+num[j];
    }
    for (int l=1;l<n;l++)
        for (int i=1;i<=n-l;i++)
            dp[i][i+l]=sum[i][i+l]-min(dp[i][i+l-1],dp[i+1][i+l]);
    fout<<dp[1][n]<<" "<<sum[1][n]-dp[1][n]<<endl;
    return 0;
}
