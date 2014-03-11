#include <stdio.h>
const int MAXN = 1001;
int f[MAXN], r[MAXN], ct[MAXN];
int n, m;
int ans;
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
    int sum = ct[b]+ct[a];
    ct[b] = ct[a] = sum;
    ans >?= sum;
    if (r[a] > r[b])
        f[b] = a;
    else
    {
        if (r[a] == r[b])
            r[b]++;
        f[a] = b;
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        f[i] = i, ct[i] = 1;
    int a, b;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &a, &b);
        merge(a, b);
    }
    printf("%d", ans);
    return 0;
}
