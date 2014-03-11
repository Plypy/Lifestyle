#include <iostream>
using namespace std;
const int MAXN = 1000001;
bool vis[MAXN];
int p[MAXN];
int main()
{
    int n;
    cin >> n;
    int a, b;
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d",&a,&b);
        p[b] = a;
    }
    cin >> a >> b;
    vis[1] = true;
    while (a!=1)
    {
        vis[a] = true;
        a = p[a];
    }
    while (!vis[b])
        b = p[b];
    cout << b;
    return 0;
}
