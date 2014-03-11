#include <iostream>
using namespace std;
const int MAXV = 1001;
const int MAXE = 5001;
struct edge
{
    int bg;
    int ed;
    int wt;
}e[MAXE];
int dis[MAXV];
int n, m;
int mini;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> e[i].ed >> e[i].bg >> e[i].wt;
    bool flag;
    int a, b, c;
    for (int i = 1; i <= n; i++)
    {
        flag = false;
        for (int j = 1; j <= m; j++)
        {
            a = e[j].bg;
            b = e[j].ed;
            c = e[j].wt;
            if (dis[b] > dis[a] + c)
            {
                dis[b] = dis[a]+c;
                flag = true;
            }
            mini <?= dis[b];
        }
        if (!flag)
            break;
    }
    flag = false;
    for (int i = 1; i <= m; i++)
        if (dis[e[i].ed] > dis[e[i].bg]+e[i].wt)
        {
            flag = true;
            break;
        }
    if (flag)
    {
        cout << "NO SOLUTION\n";
        return 0;
    }
    for (int i = 1; i <= n; i++)
        cout << dis[i]-mini << endl;
    return 0;
}
