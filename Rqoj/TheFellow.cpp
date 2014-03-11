#include <iostream>
using namespace std;
const int MAXN = 1001;
int f[MAXN], e[MAXN], r[MAXN];
int find(int a)
{
    if (a!=f[a])
        f[a] = find(f[a]);
    return f[a];
}
void merge(int a, int b)
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
            r[b]++;
        f[a] = b;
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        f[i] = i;
    char ch[2];
    int a, b;
    for (int i = 0; i < m; i++)
    {
        scanf("%s%d%d", ch, &a, &b);
        if (*ch == 'F')
            merge(a,b);
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
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (f[i] == i)
            ans++;
    cout << ans;
    return 0;
}
/*
6
4
E 1 4
F 3 5
F 4 6
E 1 2
*/
