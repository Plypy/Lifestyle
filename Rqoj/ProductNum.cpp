#include <iostream>
using namespace std;
bool map[10][10];
int n;
string sr;
int ct[10];
int main()
{
    cin >> sr >> n;
    int a, b;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b;
        map[a][b] = true;
    }
    for (int i = 0; i < 10; i++)
        map[i][i] = true;
    for (int k = 0; k < 10; k++)
        for (int i = 0; i < 10; i++)
            if (i != k)
                for (int j = 0; j < 10; j++)
                    if (i != j && k != j)
                        map[i][j] = map[i][j] || (map[i][k] && map[k][j]);
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            if (map[i][j])
                ++ct[i];
    const int bas = 10000;
    int ans[20];
    ans[1] = 1;
    ans[0] = 1;
    int mult;
    int tmp;
    for (int i = 0; i < sr.size(); i++)
    {
        mult = ct[sr[i]-'0'];
        tmp = 0;
        for (int i = 1; i <= ans[0]; i++)
        {
            ans[i] = ans[i]*mult+tmp;
            tmp = ans[i]/bas;
            ans[i] %= bas;
        }
        if (tmp)
            ans[++ans[0]] = tmp;
    }
    for (int i = ans[0]; i > 0; i--)
        if (!ans[i])
            cout << "0000";
        else
            cout << ans[i];
    return 0;
}
