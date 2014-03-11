#include <iostream>
using namespace std;
const int MAXN = 101;
int row[MAXN];
int col[MAXN];
int n, m;
int main()
{
    cin >> n >> m;
    int tmp;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> tmp;
            if (tmp)
            {
                ++row[i];
                ++col[j];
            }
        }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ans >?= row[i]+col[j];
    cout << ans;
    return 0;
}
