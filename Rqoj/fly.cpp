#include <iostream>
#include <math.h>
using namespace std;
const int MAXN = 1001;
struct pos
{
    int x;
    int y;
} pt[MAXN];
int f[MAXN];
int n, m, k;
int cmp(const void *a, const void *b)
{
    return ((pos *)a)->x - ((pos *)b)->x;
}
int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i)
        cin >> pt[i].x >> pt[i].y;
    qsort(pt,k,sizeof(pos),cmp);
    int ans = 0;
    for (int i = 0; i < k; ++i)
    {
        f[i] = 1;
        for (int j = 0; j < i; ++j)
            if (pt[j].x < pt[i].x && pt[j].y < pt[i].y)
                f[i] >?= f[j]+1;
        ans >?= f[i];
    }
    ans = ((n-ans)+(m-ans))*100+int(double(ans*100)*sqrt(2)+0.5);
    cout << ans;
    return 0;
}   
