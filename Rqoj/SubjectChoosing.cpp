// f[i][j] ��ʾǰi���������jƪ����������̵�ʱ��
// ���Կ�������i���������t��������ô���Ǿ���Ҫ��f[i-1][j-t]��Ȼ���Ǹ�������
// ���ҿ���Ӧ�ü��з�֤���������������������
// ���ǵ��κ�ʱ��ֻ��Ҫf[i]��f[i-1]���������飬���ǿ���ʹ�ù��������Ż��ռ�����
// ��fȫ����ʼ��ΪINFINITY ,f[0][0]��Ϊ0���� 
#include <iostream>
#include <cmath>
#include <cstring>
#include <climits>
#include <cstdlib>
using namespace std;
const int MAXN = 210;
const int MAXM = 30;
typedef unsigned long long ull;
int a[MAXM], b[MAXM];
ull f[2][MAXN];
int n, m;
void load()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
        cin >> a[i] >> b[i];
}
ull ans = LLONG_MAX;
ull min(ull a, ull b)
{
    return a<b?a:b;
}
ull power(int bas, int p)
{
    ull ret = 1;
    for (int i = 1; i <= p; ++i)
        ret *= bas;
    return ret;
}
void work()
{
    for (int i = 1; i <= n; ++i)
        f[0][i] = LLONG_MAX;
    int u, v;
    for (int i = 1; i <=m; ++i)
    {
        u = (i-1)&1;
        v = i&1;
        for (int j = 1; j <= n; ++j)
            f[v][j] = f[u][j];
        for (int j = 1; j <= n; ++j)
            for (int k = 1; k <= j; ++k)
                f[v][j] = min(f[v][j],f[u][j-k]+a[i]*power(k,b[i]));
        ans = min(ans,f[v][n]);
    }
}
void output()
{
    cout << ans << endl;
}
int main()
{
    load();
    work();
    output();
    //system("pause");
    return 0;
}
