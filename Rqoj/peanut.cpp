//竟然没有考虑到绝对值... 
#include <iostream>
#include <math.h>
using namespace std;
const int MAXN = 21;
struct field
{
    int x;
    int y;
    int amt;
} map[MAXN*MAXN];
int m, n, t;
int main()
{
    cin >> m >> n >> t;
    int k = 1;
    int tmp;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> tmp;
            if (tmp)
            {
                map[k].x = i;
                map[k].y = j;
                map[k++].amt = tmp;
            }
        }
    k--;
    for (int i = 1; i < k; i++)
        for (int j = i+1; j <= k; j++)
            if (map[i].amt < map[j].amt)
                swap(map[i],map[j]);
    int ans = 0;
    if (2*map[1].x+1 <= t)
    {
        ans += map[1].amt;
        t = t-map[1].x-1;
        int x = map[1].x;
        int y = map[1].y;
        int i = 2;
        while (1)
        {
            if (i > k)
                break;
            if (abs(map[i].x-x) + abs(map[i].y-y) + 1 + map[i].x <= t)
            {
                ans += map[i].amt;
                t = t-(abs(map[i].x-x)+abs(map[i].y-y)+1);
                x = map[i].x;
                y = map[i].y;
                i++;
            }
            else
                break;
        }
    }
    cout << ans;
    return 0;
}

