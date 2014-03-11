#include <iostream>
#include <cstdlib>
using namespace std;
const int MAXN = 5050;
int n;
int f[MAXN];
int ans;
int get(int t)
{
    int bg = 1, ed = ans;
    int mid;
    while (bg <= ed)
    {
        mid = (bg+ed)>>1;
        if (f[mid] <= t)
        {
            bg = mid+1;
        }
        else
        {
            ed = mid-1;
        }
    }
    return bg;
}
int main()
{
    cin >> n;
    int a;
    int t;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a;
        f[t=get(a)] = a;
        if (t > ans)
            ans = t;
    }
    cout << ans << endl;
//    system("pause");
    return 0;
}
