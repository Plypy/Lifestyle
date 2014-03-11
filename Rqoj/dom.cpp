#include <stdio.h>
#define FLAG 23456
int main(void)
{
    freopen("dom.in","r",stdin);
    freopen("dom.out","w",stdout);
	int t[12012]={0},i,j,n,up,down,tm,sum=0;
	for(i=1;i<12012;i++) 
        t[i]=FLAG;//初始条件为t[0]=0，即一开始的时候不需要翻转 
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
	for(i=sum/2,j=int(sum/2.0+.5);t[i]==FLAG&&t[j]==FLAG;i--,j++)//从中间开始向两边扩散寻找第一个能够通过翻牌到达的值 
        continue;                                                //则其显然为能够使两边差值最小的翻转   
	printf("%i",( (t[i]<t[j])? t[i] : t[j] ));
	return 0;
}
/*  状态方程 哒哒！！！ 
    f[i]=min（f[i-up],f[i-down]+1） 
