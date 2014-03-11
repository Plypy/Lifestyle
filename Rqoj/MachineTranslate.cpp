#include <iostream>
using namespace std;
const int MAXN = 1010;
bool in[MAXN];
int que[MAXN];
int bg, ed, n, m;
int main()
{
    cin >> m >> n;
    int tmp;
    int tot = 0;
    bg = 1;
    ed = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> tmp;
        if (in[tmp])
            continue;
        else if (ed-bg+1 < m)
        {
            que[++ed] = tmp;
            in[tmp] = true;
            tot++;
        }
        else
        {
            in[que[bg++]] = false;
            que[++ed] = tmp;
            in[tmp] = true;
            tot++;
        }
    }
    cout << tot;
    return 0;
}
