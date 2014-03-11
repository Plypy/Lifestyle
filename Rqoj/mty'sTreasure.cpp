#include <iostream>
using namespace std;
const int MAXN = 1001;
int in[MAXN];
int f[MAXN];
bool map[MAXN][MAXN];
int n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
            in[j] += map[i][j];
        }
    int ct = 0;
    bool flag;
    int top = 0;
    while (1)
    {
        top++;
        flag = true;
        for (int i = 1; i <= n; i++)
        {
            if (in[i] == 0)
            {
                flag = false;
                f[i] = top;
                ct++;
            }
        }
        if (flag)
            break;
        for (int i = 1; i <= n; i++)
        {
            if (f[i] == top)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (map[i][j])
                    {
                        map[i][j] = false;
                        in[j]--;
                    }
                }
            }
        }
    }
    if (ct == n)
        cout << "N";
    else
        cout << "Y";
//    system("pause");
    return 0;
}
