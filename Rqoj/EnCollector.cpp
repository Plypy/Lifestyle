//������������С�����ʣ�תΪ��𰸵ĸ���
//��ʹ�����ݳ�ԭ��
//��ν���� 

#include <iostream>
using namespace std;
typedef long long lld;
const int MAXN = 100001;
lld n,m,f[MAXN];
lld ans;
int main()
{
    cin >> n >> m;
    int bound = min(n,m);
    for (int i=bound ; i; i--)
    {   
        lld s = (n/i)*(m/i);
        for (int j=2; j*i<=bound; j++)
            s -= f[j*i];
        f[i]=s;
        ans += f[i]*i;
    }
    cout << ans*2-n*m;
    return 0;
}  
