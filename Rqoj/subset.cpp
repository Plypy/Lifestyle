/*
ID:jake1994
LANG:C++
TASK:subset
*/
//必须膜拜的大牛哇 
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
int dp[10000], n, max;
int main()
{
    ifstream fin("subset.in");
    ofstream fout("subset.out");
    fin>>n;
    max=(n*(n+1))/2;
    if (max&1==1)//判断是否为奇数 
    {
        fout<<0<<endl;
        return 0;
    }
    max/=2;
    dp[0]=1;
    for (int i=1;i<=n;i++)  //利用背包的思想，求出最后能够凑出一半的方法数但注意要除二 很巧妙哇 
        for (int j=max;j>=i;j--)
            dp[j]=dp[j]+dp[j-i];    //dp[i]表示能够凑成总和为i的方法数，然后这行代码运用了一下加法原理 
    fout<<dp[max]/2<<endl;
    return 0;
}
