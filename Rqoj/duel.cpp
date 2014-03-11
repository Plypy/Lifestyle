//呃 还是不够快...
//俺要进前50 
#include <iostream>
using namespace std;
const int MAXN = 501;
bool win[2*MAXN][2*MAXN];
bool meet[2*MAXN][2*MAXN];
int n, ct, ans[MAXN];
int main()
{
    cin >> n;
    int tmp;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            scanf("%d",&tmp);
            win[i][j] = win[i+n][j+n] = win[i][j+n] = win[i+n][j] = tmp;
        }
    for (int i = 1; i < 2*n; i++)
        meet[i][i+1] = true;
    for (int k = 2; k <= n; k++)
        for (int i = 1; i + k <= 2*n; i++)
            for (int j = i+1; j < i + k; j++)
                if (meet[i][j] && meet[j][i+k] && (win[i][j] || win[i+k][j]))
                {
                    meet[i][i+k] = true;
                    break;
                }
    for (int i = 1; i <= n; i++)
        if (meet[i][i+n])
            ans[++ct]=i;
    cout << ct;
    for (int i = 1; i <= ct; i++)
        cout << endl << ans[i];
    return 0;
}
