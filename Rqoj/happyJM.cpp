//���ĵĽ���
//��һ�ζ�ά���� 
//�ٴη�˼
//�۱������𲽵���
//�ͱ���üӱ���Ŭ��
//����ʲô���ò��� 
#include <iostream>
using namespace std;
int n, m;
int f[26][30000];
int main()
{
    cin >> n >> m;
    int v, p;
    for (int i = 1; i <= m; i++)
    {
        cin >> v >> p;
        p = v*p;
        for (int j = 0; j <= n; j++)//f[i][j]��¼�ڵ�i����ʹ����j��Ǯ��ʱ���ܵõ��������Ҫ�� 
        {//ǰ��ҲҪ��ֵ��... 
            f[i][j] = f[i-1][j];//���õ���� 
            if (j - v >= 0) 
                if (f[i][j] < f[i-1][j-v]+p)//�õ����
                    f[i][j] = f[i-1][j-v]+p;
        }
    }
    cout << f[m][n];
    return 0;
}
