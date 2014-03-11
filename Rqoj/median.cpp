#include <iostream>
using namespace std;
int list[100001],ct[200001],n,i,k,pos,ans;
bool flag;
int main()
{
    cin>>n;
    for (i=1;i<=n;i++) 
        scanf("%d", list+i);
    cin>>k; 
    ct[100000]=1; pos=100000;
    for (i=1;i<=n;i++)
    {
        if (list[i]<k) 
            pos--;
        if (list[i]>k) 
            pos++;
        if (list[i]==k) 
            flag=true;
        if (flag) 
            ans += ct[pos];
        else 
            ct[pos]++;
    }
    cout<<ans; 
    return 0;
}
