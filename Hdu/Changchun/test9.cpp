#include <stdio.h>
#include <iostream>
using namespace std;
typedef long long ll;
ll f[2111][2111],ans[2111];//i个元素放进j个集合里面的方法数
ll MOD = 95041567;
void get()
{
    ll n,m,i,k;
    //for(k=1;k<=2000;k++)
        //f[1][k]=1;
        for(i=1;i<=2000;i++)
           f[i][1]=1;
    for(i=2;i<=2000;i++)
        for(k=1;k<=2000;k++)
        {
             f[i][k]=f[i-1][k-1]+f[i-1][k]*k;
             f[i][k]%=MOD;
        }

    for(i=1;i<=2000;i++)
    {
        ans[i]=0;
       for(k=1;k<=i;k++)
       ans[i]+=f[i][k]%MOD;
        ans[i] %= MOD;
    }
}
int p[5] = {31,37,41,43,47};
int main()
{
    ll i,j,m,n;
    get();
    for (ll i = 0; i < 2000; ++i) {
        for (int j = 0; j < 5; ++j)
            cout << i << ' ' << ans[i]%p[j] << endl;
        cout << i << "th " << ans[i] << endl;
    }
    return 0;
}