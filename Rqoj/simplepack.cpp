//笨蛋啊...又把++ --整反了...
//不应该轻视啊... 
#include <iostream>
using namespace std;
int t, m;
int f[1010];
int a, b;
int main()
{
    cin >> t >> m;
    int i,j;
    for (i = 1; i <= m; i++)
    {
        cin >> a >> b;
        for (j = t; j >= a; j--)
            f[j] >?= f[j-a]+b;
    }
    cout << f[t];
    return 0;
}
