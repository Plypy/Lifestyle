//����noip2010�Ĵ��
//��������⵽�Լ���ˮƽ
//ǰ·����
//��ͷ��ʼ��
//һ��һ����ǰ��
//Ĥ�ݴ�ţ
//������ţ
//���ճ�Ϊ��ţ
//��ʵ���Լ���ŵ��
//������񣬲�˼����ʮ��������ãã�� 
#include <iostream>
using namespace std;
bool bas[1001];
int n;
int sotd[101];
int main()
{
    cin >> n;
    int tmp;
    int tot=0;
    for (int i = 1; i <= n; i++)
    {
        cin >> tmp;
        if (bas[tmp]==false)
            tot++;
        bas[tmp] = true;
    }
    cout << tot << endl;
    int j = 1;
    for (int i = 1; i <= 1000; i++)
        if (bas[i])
            sotd[j++] = i;
    for (int i = 1; i < tot; i++)
        cout << sotd[i] << ' ';
    cout << sotd[tot];
    return 0;
}
