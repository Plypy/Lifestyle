//�����Ӽ�˼�룬�����зֳ�n��q��ȫ���Ӽ�
//��ÿһ���ж�ǡ����1��q�������������С��С 
//���ս������n+1 
#include <iostream>
#include <string.h>
using namespace std;
int n, q;
bool use[10];
int let;
int main()
{
    scanf("%d%d",&n,&q);
    int ans = 0;
    int num;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&num);
        if (!use[num])
        {
            use[num]=true;
            let++;
            if (let==q)
            {
                let=0;
                memset(use,0,sizeof(use));
                ans++;
            }
        }
    }
    cout << ans+1;
    return 0;
}
