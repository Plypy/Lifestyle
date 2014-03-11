#include <iostream>
using namespace std;
const int MAXN = 10010;
int f[MAXN];
int n;
int main()
{
    scanf("%d",&n);
    int hit;
    scanf("%d",&hit);
    f[1] = hit;
    scanf("%d",&hit);
    f[2] = hit;
    for (int i = 3; i <= n; i++)
    {
        scanf("%d",&hit);
        f[i] = min(f[i-1]+hit,min(f[i-2]+hit,f[i-3]+hit));
    }
    cout << min(f[n],min(f[n-1],f[n-2]));
    return 0;
}
