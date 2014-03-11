#include <iostream>
#include <cstdio>
#include <map>
#include <set>
using namespace std;
const int MAXN = 1000001;
int lit[MAXN];
int main()
{
    map<int,int> data;
    set<int> tick;
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", lit+i);
        data[lit[i]];
    }
    int limit = data.size();
    int l = 1, r = n, bg = 1, best = n;
    int ct = 0;
    for (int i = 1; i <= n; i++)
    {
        data[lit[i]]++;
        if (data[lit[i]] >= k && tick.find(lit[i]) == tick.end())
        {
            tick.insert(lit[i]);
            ct++;
        }
        while (data[lit[bg]] > k)
        {
            data[lit[bg]]--;
            bg++;
        }
        if (i-bg+1 < best && ct == limit)
        {
            best = i-bg+1;
            l = bg;
            r = i;
        }
    }
    if (tick.size() != limit)
        printf("-1");
    else
        printf("%d %d", l, r);
    return 0;
}
