#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 305;
int ans = 52111425;
int son[MAXN];
int bro[MAXN];
int fa[MAXN];
int size[MAXN];
int tmp[MAXN];
int n, p;
void load();
void dfs(int *,int);
int cmp(const void *a, const void *b)
{
    return size[*(int *)b] - size[*(int *)a];
}
int main()
{
    load();
    tmp[0] = 1;
    dfs(tmp,1);
    cout << ans;
    return 0;
}
void load()
{
    cin >> n >> p;
    int a, b;
    for (int i = 0; i < p; i++)
    {
        cin >> a >> b;
        if (a > b)
            swap(a,b);
        bro[b] = son[a];
        son[a] = b;
        fa[b] = a;
        for (int t = a; t; t = fa[t])
            size[t] += size[b]+1;
    }
}

void dfs(int *list, int amt)
{
    int back[MAXN];
    int ct = 0;
    for (int i = 0; list[i]; i++)
        for (int t = son[list[i]]; t; t = bro[t])
            back[ct++] = t;
    if (!ct && amt < ans)
    {
        ans = amt;
        return;
    }
    back[ct] = 0;
    qsort(back, ct, sizeof(int), cmp);
    --ct;
    int mem;
    if (amt+ct < ans)
        for (int i = 0; i <= ct; i++)
        {
            swap(back[i],back[ct]);
            mem = back[ct];
            back[ct] = 0;
            dfs(back,amt+ct);
            back[ct] = mem;
            swap(back[i],back[ct]);
        }
}
/*
SAMPLE

7 6
1 2
1 3
2 4
2 5
3 6
3 7

*/
