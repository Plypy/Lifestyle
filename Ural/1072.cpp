// Note
// 这道题就是求一个最短路
// 由于边权全部一样，用宽搜就可以了
// 悲剧啊，把数据范围搞错，调试了近1个小时... 
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstdlib>
#include <cctype>
using namespace std;
const int MAXN = 100;
const int MAXE = MAXN*MAXN;
unsigned int mask[MAXN][5];
int num[MAXN];
int edge[MAXE];
int nxt[MAXE];
int adj[MAXN];
void add(int u, int v)
{
    edge[++edge[0]] = v;
    nxt[edge[0]] = adj[u];
    adj[u] = edge[0];
}
int n;
void read(unsigned int &t)
{
    t = 0;
    char ch;
    do {
        cin.get(ch);
    } while(!isdigit(ch));
    do {
        t = t*10+ch-'0';
        cin.get(ch);
    } while(isdigit(ch));
}
bool match(int u, int v)
{
    for (int i = 0; i < num[u]; ++i)
        for (int j = 0; j < num[v]; ++j)
        {
            if (mask[u][i] == mask[v][j])
                return true;
        }
    return false;
}
int st, ed;
void load()
{
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    cin >> n;
    unsigned int tmp[3];
    for (int i = 1; i <= n; ++i)
    {
        cin >> num[i];
        for (int j = 0; j < num[i]; ++j)
        {
            for (int k = 0; k < 4; ++k)
            {
                tmp[0] <<= 8;
                read(tmp[2]);
                tmp[0] += tmp[2];
            }
            for (int k = 0; k < 4; ++k)
            {
                tmp[1] <<= 8;
                read(tmp[2]);
                tmp[1] += tmp[2];
            }
            mask[i][j] = tmp[0]&tmp[1];
        }
    }
    cin >> st >> ed;
    for (int i = 1; i < n; ++i)
        for (int j = i+1; j <= n; ++j)
            if (match(i,j))
            {
                add(i,j);
                add(j,i);
            }
}
bool used[MAXN];
int pre[MAXN];
int ans[MAXN];
int que[MAXN];
int head, tail;
void work()
{
    que[head] = st;
    used[st] = true;
    while (head <= tail)
    {
        int u = que[head++];
        for (int t = adj[u]; t; t = nxt[t])
        {
            if (used[edge[t]])
                continue;
            used[edge[t]] = true;
            que[++tail] = edge[t];
            pre[edge[t]] = u;
        }
        if (used[ed])
            break;
    }
    if (!used[ed])
    {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    for (int t = ed; t; t = pre[t])
        ans[++ans[0]] = t;
    cout << st;
    for (int i = ans[0]-1; i; --i)
        cout << ' ' << ans[i];
    cout << endl;
}
int main()
{
    load();
    work();
    return 0;
}
