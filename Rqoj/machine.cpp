// ������ һ���ac�ˣ���
// �������÷�˼...
// ��Ȼ��������ѭ��...
// ���Ƕ����ݽṹ�ı�ʾ��������
// Ҫ���������ݽṹ��
// ���ܱ�֤���������׼ȷ��
// NOIP��ʤ�� 
#include <iostream>
using namespace std;
const int MAX = 25;
int m, n;
int ftime[MAX];
int order[MAX*MAX];
int use[MAX][MAX];
int cost[MAX][MAX];
int ct[MAX];
bool machine[MAX][MAX*MAX];
void find(int obj, int ma)
{
    int i, j, k;
    int co = cost[obj][ct[obj]];
    for (i = ftime[obj]+1; ;)
    {
        for (j = i; machine[ma][j] == false && j <= i+co-1; j++)
            continue;
        if (j == i +co)
        {
            for (k = i; k < j; k++)
                machine[ma][k] = true;
            ftime[obj] = j-1;
            break;
        }
        else
            i = j+1;
    }
    ct[obj]++;
}
int main()
{
    cin >> m >> n;
    int t = m*n;
    for (int i = 1; i <= t; i++)
        cin >> order[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> use[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> cost[i][j];
    for (int i = 1; i <= n; i++)
        ct[i] = 1;
    int obj, ma;
    for (int i = 1; i <= t; i++)
    {
        obj = order[i];
        ma = use[obj][ct[obj]];
        find(obj, ma);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (ans < ftime[i])
            ans = ftime[i];
    cout << ans;
    return 0;
}
