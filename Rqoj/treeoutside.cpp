#include <iostream>
using namespace std;
bool line[10010];
int m, n;
int main()
{
    cin >> n >> m;
    int bg, ed;
    for (int i = 1; i <= m; i++)
    {
        cin >> bg >> ed;
        for (int j = bg; j <= ed; j++)
            line[j] = true;
    }
    int ans = 0;
    for (int i = 0; i <= n; i++)
        if (line[i] == false)
            ans++;
    cout << ans;
    return 0;
}
