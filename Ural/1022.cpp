#include <iostream>
#include <cstdlib>
using namespace std;
const int MAXN = 110;
int adj[MAXN][MAXN];
int n;
void load()
{
    cin >> n;
    int a;
    for (int i = 1; i <= n; ++i)
    {
        while (1)
        {
            cin >> a;
            if (a == 0)
                break;
            adj[i][++adj[i][0]] = a;
        }
    }
}
int ans[MAXN];
bool used[MAXN];
void dfs(int u)
{
    used[u] = true;
    for (int i = 1; i <= adj[u][0]; ++i)
        if (!used[adj[u][i]])
            dfs(adj[u][i]);
    ans[++ans[0]] = u;
}
void dfs_walk()
{
    for (int i = 1; i <= n; ++i)
        if (!used[i])
            dfs(i);
}
void work()
{
    dfs_walk();
    cout << ans[ans[0]];
    for (int i = ans[0]-1; i; i--)
        cout << ' ' << ans[i];
    cout << endl;
    //system("pause");
}
int main()
{
    load();
    work();
    return 0;
}
