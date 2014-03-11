#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int MAXN = 200001;
int ans[MAXN];
int list[MAXN];
int cmp(const void*a, const void*b)
{
    return *(int*)a-*(int*)b;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", list+i);
    qsort(list+1,n,sizeof(int),cmp);
    int tmp = list[1];
    int ct = 1;
    for (int i = 2; i <= n; i++)
    {
        if (tmp == list[i])
            ct++;
        else
        {
            printf("%d %d\n", tmp, ct);
            tmp = list[i];
            ct = 1;
        }
    }
    printf("%d %d", tmp, ct);
    return 0;
}
