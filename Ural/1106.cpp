//考虑到图是连通的，故必然可以将其分为题目要求的两个集合
//只需要依序分配即可，便能保证符合要求 
#include <stdio.h>
#include <stdlib.h>
#define MAXN 20010
#define MAXV 110
int edge[MAXN], next[MAXN], adj[MAXV], ct;
short side[MAXV];
void add(int u, int v)
{
    edge[++ct] = v;
    next[ct] = adj[u];
    adj[u] = ct;
}
int n;
int anslist[MAXV], ans;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int j;
        scanf("%d", &j);
        while (j)
        {
            add(i,j);
            add(j,i);
            scanf("%d", &j);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!side[i])
        {
            anslist[++ans] = i;
            side[i] = 1;
            int u = adj[i];
            while (u)
            {
                if (!side[edge[u]])
                    side[edge[u]] = 2;
                u = next[u];
            }
        }
    }
    printf("%d\n", ans);
    printf("%d", anslist[1]);
    for (int i = 2; i <= ans; i++)
        printf(" %d", anslist[i]);
    printf("\n");
    return 0;
}
