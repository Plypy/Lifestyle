//�����K������ 
//ÿ�������ȡL�� 
//��ô������������������ȡ����
//���۵�һ����ȡ����
//�ڶ���������ȡһ����,ʹ��������ȡ�����ܺ�ΪL+1
//��ô���K�ǣ�L+1���ı�������һ���˱�Ȼ�ǻ����
//�����һ���˱�Ȼ����Ӯ�� 
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
int main()
{
    int k;
    cin >> k;
    int bound = int(sqrt(double(k)));
    for (int i = 3; i <= bound; ++i)
        if (k%i == 0)
        {
            cout << i-1 << endl;
            return 0;
        }
    if (k&1)
        cout << k-1 << endl;
    else
    {
        int t = (k>>1)-1;
        if (t < 2)
            t = k-1;
        cout << t << endl;
    }
    return 0; 
}
