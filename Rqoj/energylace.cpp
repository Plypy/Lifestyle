/*Ҫ��Ū�����ݽṹ������
 *ֻ����������ȷ��������������
 *����ά������
----------------------------------- 
 *Ҫ�м����ص�������������ͬ������
 *�������ܻᵼ�±������
 *���������һ�ж����� 
 */
#include <iostream>
using namespace std;
int f[201][201], n, ar[201];
long dp(int a, int b);
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ar[i];
        ar[n+i] = ar[i];
    }
    long ans = 0;
    for (int i = 1; i <= n; i++)
        ans >?= dp(i,i+n);
    cout << ans;
    return 0;
}
long dp(int a, int b)
{
    if (f[a][b])
        return f[a][b];
    long res = 0;
    for (int i = a+1; i < b; i++)
        res >?= dp(a,i)+dp(i,b)+ar[i]*ar[a]*ar[b];
    f[a][b] = res;
    return res;
}
