#include <stdio.h>
#define FLAG 23456
int main(void)
{
    freopen("dom.in","r",stdin);
    freopen("dom.out","w",stdout);
	int t[12012]={0},i,j,n,up,down,tm,sum=0;
	for(i=1;i<12012;i++) 
        t[i]=FLAG;//��ʼ����Ϊt[0]=0����һ��ʼ��ʱ����Ҫ��ת 
	scanf("%i",&n);
	for(i=0;i<n;i++)
	{
		scanf("%i%i",&up,&down);
		sum+=up+down;
		for(j=sum;j>=0;j--)
			if(t[j]!=FLAG)
			{
				tm=t[j];
				t[j]=FLAG;
				if(t[j+down]>tm) 
                    t[j+down]=tm;
				if(t[j+up]>tm+1) 
                    t[j+up]=tm+1;
			}
	}
	for(i=sum/2,j=int(sum/2.0+.5);t[i]==FLAG&&t[j]==FLAG;i--,j++)//���м俪ʼ��������ɢѰ�ҵ�һ���ܹ�ͨ�����Ƶ����ֵ 
        continue;                                                //������ȻΪ�ܹ�ʹ���߲�ֵ��С�ķ�ת   
	printf("%i",( (t[i]<t[j])? t[i] : t[j] ));
	return 0;
}
/*  ״̬���� ���գ����� 
    f[i]=min��f[i-up],f[i-down]+1�� 
