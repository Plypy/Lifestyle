#include <iostream>
using namespace std;
const int MAXN = 100001;
int n;
int pa[MAXN];
int a[MAXN];
int ans;
int get(int num)
{
    int bg, ed, mid;
    bg = 1; ed = ans;
    while (bg <= ed)
    {
        mid = (bg+ed)>>1;
        if (a[mid] == num)
            return mid;
        if (a[mid] > num)
            ed = mid-1;
        else
            bg = mid+1;
    }
    return bg;
}
int main()
{
    scanf("%d",&n);
    int tmp;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &tmp);
        pa[tmp] = i;
    }
    int t;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &tmp);
        tmp = pa[tmp];
        t = get(tmp);
        if (t > ans)
            ans = t;
        a[t] = tmp;
    }
    cout << n-ans;
    return 0;
}
