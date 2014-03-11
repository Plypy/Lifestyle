/*
ID: jake1994
LANG: C++
TASK: milk
*/
// Note�� ɵ�˱���...�������� 
// �ٴ�ɵ��...ϰ����n�������� 
#include <iostream>
#include <stdio.h>
using namespace std;
const int MAX = 5050;
int n, m;
int amount[MAX], price[MAX];
int main()
{
    freopen("milk.in", "r", stdin);
    freopen("milk.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> price[i] >> amount[i];
    for (int i = 1; i < m; i++)
        for (int j = i+1; j <= m; j++)
            if (price[i] > price[j])
                swap(price[i],price[j]),swap(amount[i], amount[j]);
    int sum = 0, ans = 0;
    for (int i = 1; i <= m; i++)
    {
        if (sum + amount[i] <= n)
        {
            sum += amount[i];
            ans += amount[i]*price[i];
        }
        else
        {
            ans += (n-sum)*price[i];
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
