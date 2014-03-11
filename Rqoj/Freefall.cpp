#include <iostream>
#include <math.h>
using namespace std;
const double des=1E-5;
double s1,s2,t1,t2,h,s,v,l,k;
int n,ans;
int main()
{
    cin >> h >> s >> v >> l >> k >> n;
    s1=s+l-v*sqrt((h-k)/5);
    s2=s-v*sqrt(h/5);
    for (int i=0;i<n;i++)
        if (s1+des >= i && s2-des <= i)
        {
            ans++;
            if (s2-des > i)
                break;
        }
    cout << ans;
    return 0;
}
