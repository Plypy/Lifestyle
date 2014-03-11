/*
    ID : jake1994
    PROG : shuttle
    LANG : C++
*/
//此题找规律
//对于这种题，打眼上去就能看出来具有一定规律的
//可以先笔算出几组小答案，然后找规律 
#include <fstream>
#include <cstdlib>
#include <cstring> 
using namespace std;
ifstream cin("shuttle.in");
ofstream cout("shuttle.out");

int main()
{
    int n,t,s,res[500],tt=0;
    memset(res,0,sizeof(res));
    cin>>n;
    for (int i=2;i<=n+1;i++)
    {
        if (i%2==1) t=-2;
        else t=2;
        if (i%2==1) s=n+i;
        else s=n-i+2;
        res[++tt]=s;
        for (int j=2;j<=i;j++)
        {
            s+=t;
            res[++tt]=s;
        }
    }
    for (int i=n;i>=2;i--)
    {
        if (i%2==1) t=-2;
        else t=2;
        if (i%2==1) s=n+i;
        else s=n-i+2;
        res[++tt]=s;
        for (int j=2;j<=i;j++)
        {
            s+=t;
            res[++tt]=s;
        }
    }
    res[++tt]=n+1;
    for (int i=1;i<=tt;i++)
    {
        cout<<res[i];
        if ((i%20==0)||(i==tt)) cout<<endl;
        else cout<<" ";
    }
    return 0;
}
