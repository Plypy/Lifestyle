#include <iostream>
#include <string>
using namespace std;
typedef unsigned long long ull;
long long a,b;
ull n;
string s;
int main()
{
    cin>>a>>b;
    if (a==b)
    {
        printf("0");
        return 0;
    }
    if (a<b)
        printf("-"),n=b-a;
    if (a>b)
        n=a-b;
    for (int i=1;n>0;i++)
        if (i%4!=0)
        {
            s=char(n%10+'0')+s;
            n/=10;
        }
        else
            s = ','+s;
    cout<<s;
    return 0;
}
