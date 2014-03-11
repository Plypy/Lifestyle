#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int MAXN = 100001;
struct clash
{
    int a;
    int b;
    int c;
} pa[MAXN];
int n, m;
int cmp(const void *a, const void *b)
{
    return ((clash *)b)->c - ((clash *)a)->c;
}
int e[MAXN];
int rank[MAXN];
int f[MAXN];
inline int find(int a)
{
    if (f[a] != a)
        f[a] = find(f[a]);
    return f[a];
}
inline void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return;
    if (rank[a] > rank[b])
        f[b] = a;
    else
    {
        if (rank[a] == rank[b])
            rank[b]++;
        f[a] = b;
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        f[i] = i;
    for (int i = 1; i <= m; i++)
        scanf("%d%d%d", &pa[i].a, &pa[i].b, &pa[i].c);
    qsort(pa+1, m, sizeof(clash), cmp);
    bool flag = false;
    int a, b, c;
    for (int i = 1; i <= m; i++)
    {
        a = pa[i].a;
        b = pa[i].b;
        c = pa[i].c;
        if (find(a) == find(b))
        {
            printf("%d", c);
            flag = true;
            break;
        }
        else
        {
            if (e[a])
                merge(e[a],b);
            else
                e[a] = b;
            if (e[b])
                merge(e[b],a);
            else
                e[b] = a;
        }
    }
    if (!flag)
        printf("0");
    return 0;
}
