//������ǿ��������
//������ʵ����ΰ�� 
//������ʵ��������
//3 100
//���� 100 ���Ա�ʾ�ɶ������� 1100100
//��981��Ϊ3��2�η���3��5�η���3��6�η�
//��981=3^2+3^5+3^6 
#include <iostream>
using namespace std;
int bas, n;
bool list[10];
int sq(int bas, int j);
int main()
{
    cin >> bas >> n;
    int ans = 0;
    int i = 0;
    while (n)
    {
        list[i++] = n%2;
        n/=2;
    }
    for (int j = 0; j < i; j++)
    {
        if (list[j])//����ǰ�0Ҳ������..��Υ�� 
            ans+=sq(bas,j);//��������ʽ˼· �Ǻ� 
    }
    cout << ans;
    return 0;
}
int sq(int bas, int j)
{
    int res = 1;
    for (int i = 1; i <= j; i++)
        res*=bas;
    return res;
}
