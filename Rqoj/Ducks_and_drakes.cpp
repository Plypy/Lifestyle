#include <iostream>
using namespace std;
const int MAXN = 10001;
int f[MAXN], n;
int main()
{
    scanf("%d",&n);
    int tmp, ans = 0, bg, ed, tbg;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&tmp);
        if (tmp > tmp+f[i-1])
        {
            tbg = i;
            f[i] = tmp;
        }
        else
        {
            f[i] = tmp+f[i-1];
        }
        if (ans < f[i])
        {
            ans = f[i];
            bg = tbg;
            ed = i;
        }
    }
    cout << bg << ' ' << ed << endl << ans;
    return 0;
}
