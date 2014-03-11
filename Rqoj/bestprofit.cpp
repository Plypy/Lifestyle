#include<iostream>
using namespace std;
const int MAXM = 31;
double dp[MAXM];
int main ()
{
    double n,a,b,p,q;
    int m;
    cin>>m>>n>>a>>b>>p>>q;
    p=1.0-p,q=1.0-q;
    dp[m]=max(a,b);
    for (int i=m-1; i>0; i--)
        dp[i]=max(dp[i+1]*p+a,dp[i+1]*q+b);
    printf("%.5f",dp[1]*n);
    return 0;
}
