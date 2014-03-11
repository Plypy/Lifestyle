#include <iostream>
using namespace std;
const int MAXN = 30;
long long root[MAXN][MAXN], f[MAXN][MAXN], n, list[MAXN];
int ct = 0;
long long dp(long long a, long long b)
{
    if (f[a][b])
        return f[a][b];
    if (a > b)
        return 1;
    long long res = 0;
    long long tmp;
    for (int i = a; i <= b; i++)
    {
        if (res < (tmp = dp(a,i-1)*dp(i+1,b)+list[i]))
        {
            root[a][b] = i;
            res = tmp;
        }
    }
    return f[a][b] = res;
}
void print(int a, int b)
{
    if (a <= b)
    {
        cout << root[a][b];
        if (++ct<n)
            cout << ' ';
        print(a,root[a][b]-1);
        print(root[a][b]+1,b);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> list[i], f[i][i] = list[i], root[i][i] = i;
    cout << dp(1,n) << endl;
    print(1,n);
    return 0;
}
