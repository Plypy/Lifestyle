//Note
//һ�����Ǹ��������ڹ�
//�Ҿ��������
//��ʱΪʲô�������������һ���õ�״̬
//��Ȼ����Ķ�û���뵽���Ǹ�ɵ���ά״̬
//����Ĺ���������Ĳ���һ��
//����������û��
//��Ѿ�����ų����и�ƨ�ð� 


//���ֲ���ʵ�� 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
const int L=100001;
int n,a[L],p[L],ans;

int get(int num)
{
    int bg=1,ed=ans,mid;
    while (bg <= ed)
    {
        mid = (bg+ed)>>1;
        if (p[mid]==num)
            return mid;
        else if (p[mid] < num)
            bg = mid+1;
        else
            ed = mid-1;
    }
    return bg;
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",a+i);
    for (int i=n,t;i>=1;i--)
    {
        if (a[i]==0)
            continue;
        t=get(a[i]);
        if (t>ans)
            ans++;
        p[t]=a[i];
    }
    cout << ans;
    return 0;
}
