#include <iostream>
#include <stdlib.h>
#include <limits.h>
using namespace std;
const int MAXN = 100001;
struct range
{
    int a;
    int b;
} data[MAXN];
int ans = INT_MAX;
int x1, y1;
int x2, y2;
inline int sqr(int num)
{
    return num*num;
}
int cmp(const void *a, const void *b)
{
    return ((range *)b)->a - ((range *)a)->a;
}
int main()
{
    int n;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    scanf("%d", &n);
    int x, y;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &x, &y);
        data[i].a = sqr(x-x1)+sqr(y-y1);
        data[i].b = sqr(x-x2)+sqr(y-y2);
    }
    qsort(data+1, n, sizeof(range), cmp);
    int maxr = 0;
    ans = data[1].a;
    for (int i = 1; i < n; i++)
    {
        maxr >?= data[i].b;
        ans <?= data[i+1].a+maxr;
    }
    printf("%d", ans);
    return 0;
}
