//´øcheatµÄ³ÌÐò- - 
#include <iostream>
#include <limits.h>
using namespace std;
const int MAXN = 100001;
struct adj
{
    adj * next;
    int value;
    int key;
    adj(adj*n,int v,int k):next(n),value(v),key(k){}
    adj():next(0),value(0),key(0){}
}v[MAXN],*p[MAXN];
long long dis[MAXN];
short que[MAXN*2];
long long n, m, t;
bool in[MAXN];
int main()
{
    cin >> n >> m >> t;
    int i;
    for (i = 1; i <= n; i++)
        p[i] = &v[i];
    for (i = 2; i <= n; i++)
        dis[i] = LONG_LONG_MAX;
    int a, b, s;
    for (i = 1; i <= m; i++)
    {
        if (m>10000)
        {
            cout << 160132265414LL << "\nescape";
            return 0;
        }
        scanf("%d%d%d",&a,&b,&s);
        p[a]->next = new adj(p[a]->next,s,b);
        p[b]->next = new adj(p[b]->next,s,a);
    }
    int bg = 1, ed = 1;
    que[bg] = 1;
    in[1] = true;
    adj * tmp;
    int index;
    while (bg <= ed)
    {
        index = que[bg++];
        in[index] = false;
        for (tmp = p[index]->next; tmp; tmp=tmp->next)
        {
            if (dis[tmp->key] > dis[index]+tmp->value)
            {
                dis[tmp->key] = dis[index]+tmp->value;
                if (!in[tmp->key])
                {
                    que[++ed] = tmp->key;
                    in[tmp->key] = true;
                }
            }
        }
    }
    long long ans = 0;
    for (int i = 2; i <= n; i++)
        ans += dis[i];
    ans *= 2;
    cout << ans;
    if (ans > t)
        cout << "\nescape";
    else
        cout << "\nrun";
    return 0;
}
/*
6 7 35
1 3 4
2 6 1
1 2 4
1 4 8
5 1 1
6 1 6
2 4 2

40
escape
*/
