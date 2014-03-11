#include <iostream>
using namespace std;
const int MAXN = 1001;
int num[2*MAXN];
int f[MAXN];
int tmp;
int get(int num)
{
    int bg = 1, ed = tmp, mid;
    while (bg <= ed)
    {
        mid = (bg+ed)/2;
        if (f[mid-1]<=num && num < f[mid])
            return mid;
        if (f[mid] <= num)
            bg = mid+1;
        else
            ed = mid-1;
    }
    return bg;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
        num[i+n] = num[i];
    }
    int ans = 1000;
    int t;
    for (int i = 1; i <= n; i++)
    {
        tmp = 0;
        memset(f,0,sizeof(f));
        for (int j = i; j < i+n; j++)
        {
            t = get(num[j]);
            if (t > tmp)
                tmp = t;
            f[t] = num[j];
        }
        ans <?= tmp;
    }
    cout << ans;
    return 0;
}
