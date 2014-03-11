#include <iostream>
using namespace std;
const int MAXN = 10001;
int a[MAXN];
int ans, n;
int get(int num)
{
    int bg = 1, ed = ans, mid;
    while (bg <= ed)
    {
        mid = (bg+ed)>>1;
        if (a[mid] == num)
            return mid;
        else if (a[mid] < num)
            bg = mid+1;
        else
            ed = mid-1;
    }
    return bg;
}
int main()
{
    scanf("%d",&n);
    int tmp, t;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&tmp);
        t = get(tmp);
        ans >?= t;
        a[t] = tmp;
    }
    printf("%d",ans);
    return 0;
}
