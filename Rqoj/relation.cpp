#include <stdio.h>
const int MAXN = 5001;
int f[MAXN], r[MAXN];
int n, m, p;
inline int find(int a)
{
    if (a != f[a])
        f[a] = find(f[a]);
    return f[a];
}
inline void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return;
    if (r[a] > r[b])
        f[b] = a;
    else
    {
        if (r[a] == r[b])
            ++r[b];
        f[a] = b;
    }
}
int main()
{
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 1; i <= n; ++i)
        f[i] = i;
    int a, b;
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d", &a, &b);
        merge(a,b);
    }
    for (int i = 1; i <= p; ++i)
    {
        scanf("%d%d", &a, &b);
        if (find(a) == find(b))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
