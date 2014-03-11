#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int MAXN = 2001;
int hit[MAXN];
int app[MAXN];
int n, m;
int cmp(const void *a, const void *b)
{
    if (*(int *)a < *(int *)b)
        return 1;
    return -1;
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++)
        scanf("%d",app+i);
    for (int i = 1; i <= m; i++)
        scanf("%d",hit+i);
    int tmp;
    qsort(app+1,n,sizeof(int),cmp);
    qsort(hit+1,m,sizeof(int),cmp);
    int i = 1, j = 1, d = 0;
    while (i <= n && j <= m)
    {
        if (!hit[j])
            break;
        if (app[i] > hit[j]) //使用两个单调队列进行操作 
            i++, j++, d++;
        else
            j++;
    }
    cout << m-d;
    return 0;
}
