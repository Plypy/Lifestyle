#include <iostream>
#include <string>
using namespace std;
int main()
{
    string a,b,ans="";
    cin>>a>>b;
    int len=0;
    int len1 = a.size();
    int len2 = b.size();
    for (int i=0;i<len1;i++)
        for (int j=0;j<len2;j++)
            if (a[i]==b[j])
            {
                if (i+len<len1&&j+len<len2&&a[i+len]==b[j+len])
                {
                    int x=i,y=j;
                    while (a[x]==b[y])
                        ++x,++y;
                    if (x-i>len)
                    {
                        len=x-i;
                        ans=a.substr(i,x-i);
                    }
                }
            }
    cout<<ans;
    return 0;
}
